// Pop3.cpp : CPop3 µÄÊµÏÖ

#include "stdafx.h"
#include "Pop3.h"
#include "Mail.h"
#include "Options.h"

// CPop3

STDMETHODIMP CPop3::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IPop3
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

void CPop3::on_error(int error_id, const std::string& message)
{
	Fire_error(_bstr_t(message.c_str()));
}
void CPop3::on_sending(size_t size, const tmail::Request& request, bool& cancel_and_disconnect)
{
	VARIANT_BOOL cancel = VARIANT_FALSE;
	Fire_sending((CommandTypeConstant)request.id, (LONG)size, &cancel);
	cancel_and_disconnect = (cancel != 0);
}
void CPop3::on_receiving(size_t size, const tmail::Response& response, bool& cancel_and_disconnect)
{
	VARIANT_BOOL cancel = VARIANT_FALSE;
	Fire_receiving((CommandTypeConstant)response.id, (LONG)size, &cancel);
	cancel_and_disconnect = (cancel != 0);
}
void CPop3::on_sent(const tmail::Request& request)
{
	Fire_sent((CommandTypeConstant)request.id, _bstr_t(request.c_str()));
}
void CPop3::on_received(const tmail::Response& response)
{
	Fire_received((CommandTypeConstant)response.id, _bstr_t(response.c_str()));
}


#define VBOOL(x) ((x)?VARIANT_TRUE:VARIANT_FALSE)


STDMETHODIMP CPop3::contact(BSTR host, LONG port, VARIANT_BOOL use_ssl, VARIANT_BOOL* pVal)
{
	if (port < 1 || port > 65535)
	{
		return E_INVALIDARG;
	}
	*pVal = VBOOL(pop3.connect((const char*)_bstr_t(host), (unsigned short)port, use_ssl != 0));
	return S_OK;
}

STDMETHODIMP CPop3::quit(VARIANT_BOOL* pVal)
{
	*pVal = VBOOL(pop3.quit());

	return S_OK;
}

STDMETHODIMP CPop3::auth(BSTR username, BSTR password, Pop3AuthTypeConstant authType, VARIANT_BOOL* pVal)
{
	if (authType == pop3AuthLogin)
	{
		*pVal = VBOOL(pop3.auth_login((const char*)_bstr_t(username), (const char*)_bstr_t(password)));
	}
	else if (authType == pop3AuthPlain)
	{
		*pVal = VBOOL(pop3.auth_plain((const char*)_bstr_t(username), (const char*)_bstr_t(password)));
	}
	else if (authType == pop3AuthCramMd5)
	{
		*pVal = VBOOL(pop3.auth_cram_md5((const char*)_bstr_t(username), (const char*)_bstr_t(password)));
	}
	else if (authType == pop3AuthApop)
	{
		*pVal = VBOOL(pop3.apop((const char*)_bstr_t(username), (const char*)_bstr_t(password)));
	}
	else if (authType == pop3AuthUser)
	{
		if (!pop3.user((const char*)_bstr_t(username)))
		{
			*pVal = VARIANT_FALSE;
			return S_OK;
		}
		*pVal = VBOOL(pop3.pass((const char*)_bstr_t(password)));
	}
	else
		return E_INVALIDARG;
	return S_OK;
}

STDMETHODIMP CPop3::capability(VARIANT_BOOL* pVal)
{
	*pVal = VBOOL(pop3.capability());
	return S_OK;
}

STDMETHODIMP CPop3::list(VARIANT* mailIndex, VARIANT_BOOL* pVal)
{
	tmail::Pop3::MailIndex index;
	if (!pop3.list(index))
	{
		*pVal = VARIANT_FALSE;
		return S_OK;
	}
	
	VariantClear(mailIndex);
	std::wstring result;
	for (size_t i = 0; i < index.size(); i++)
	{
		if (i > 0)
			result += L",";
		result += tlib::wstrfrom<int>(index[i].first);
		result += L":";
		result += tlib::wstrfrom<size_t>(index[i].second);
	}
	
	mailIndex->vt = VT_BSTR;
	mailIndex->bstrVal = ::SysAllocString(result.c_str());
	*pVal = VARIANT_TRUE;

	return S_OK;
}

STDMETHODIMP CPop3::uidl(VARIANT* uidIndex, VARIANT_BOOL* pVal)
{
	tmail::Pop3::UidIndex index;
	if (!pop3.uidl(index))
	{
		*pVal = VARIANT_FALSE;
		return S_OK;
	}
	
	VariantClear(uidIndex);
	std::wstring result;
	for (size_t i = 0; i < index.size(); i++)
	{
		if (i > 0)
			result += L",";
		result += tlib::wstrfrom<int>(index[i].first);
		result += L":";
		result += tlib::locale_to_wstring(index[i].second);
	}
	
	uidIndex->vt = VT_BSTR;
	uidIndex->bstrVal = ::SysAllocString(result.c_str());
	*pVal = VARIANT_TRUE;

	return S_OK;
}

STDMETHODIMP CPop3::stat(VARIANT* mailCount, VARIANT* totalSize, VARIANT_BOOL* pVal)
{
	int count = 0;
	size_t size = 0;
	if (!pop3.stat(count, size))
	{
		*pVal = VARIANT_FALSE;
		return S_OK;
	}

	VariantClear(mailCount);
	VariantClear(totalSize);
	
	mailCount->vt = VT_INT;
	mailCount->intVal = count;

	totalSize->vt = VT_I4;
	totalSize->lVal = (long)size;

	*pVal = VARIANT_TRUE;
	return S_OK;
}

STDMETHODIMP CPop3::starttls(VARIANT_BOOL* pVal)
{
	*pVal = VBOOL(pop3.starttls());
	return S_OK;
}

STDMETHODIMP CPop3::returnMailHeader(LONG id, IMail** pMail)
{
	CComObject<CMail>* cmail = 0;
	HRESULT hr = CComObject<CMail>::CreateInstance(&cmail);
	if (FAILED(hr))
		return hr;

	if (!pop3.return_mail_header((int)id, *(cmail->mail)))
	{
		delete cmail;
		*pMail = 0;
		return S_OK;
	}

	hr = cmail->QueryInterface(pMail);
	if (FAILED(hr))
	{
		delete cmail;
		*pMail = 0;
		return hr;
	}
	return S_OK;
}

STDMETHODIMP CPop3::returnMail(LONG id, IMail** pMail)
{
	CComObject<CMail>* cmail = 0;
	HRESULT hr = CComObject<CMail>::CreateInstance(&cmail);
	if (FAILED(hr))
		return hr;

	if (!pop3.return_mail((int)id, *(cmail->mail)))
	{
		delete cmail;
		*pMail = 0;
		return S_OK;
	}

	hr = cmail->QueryInterface(pMail);
	if (FAILED(hr))
	{
		delete cmail;
		*pMail = 0;
		return hr;
	}
	return S_OK;
}

STDMETHODIMP CPop3::deleteMail(LONG id, VARIANT_BOOL* pVal)
{
	*pVal = VBOOL(pop3.delete_mail((int)id));

	return S_OK;
}

STDMETHODIMP CPop3::noop(VARIANT_BOOL* pVal)
{
	*pVal = VBOOL(pop3.noop());

	return S_OK;
}

STDMETHODIMP CPop3::reset(VARIANT_BOOL* pVal)
{
	*pVal = VBOOL(pop3.reset());

	return S_OK;
}

STDMETHODIMP CPop3::get_authTypes(IOptions** pVal)
{
	*pVal = 0;
	CComObject<COptions>* options = 0;
	HRESULT hr = CComObject<COptions>::CreateInstance(&options);
	if (FAILED(hr))
		return hr;

	if (pop3.is_enable_apop())
		options->strings.push_back(L"APOP");
	if (pop3.is_enable_auth_plain())
		options->strings.push_back(L"PLAIN");
	if (pop3.is_enable_auth_login())
		options->strings.push_back(L"LOGIN");
	if (pop3.is_enable_auth_cram_md5())
		options->strings.push_back(L"CRAM-MD5");
	if (pop3.is_enable_user())
		options->strings.push_back(L"USER");

	hr = options->QueryInterface(pVal);
	if (FAILED(hr))
	{
		delete options;
		return hr;
	}

	return S_OK;
}

STDMETHODIMP CPop3::get_enableStartTls(VARIANT_BOOL* pVal)
{
	*pVal = VBOOL(pop3.is_enable_starttls());
	return S_OK;
}
