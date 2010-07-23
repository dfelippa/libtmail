// Smtp.cpp : CSmtp µÄÊµÏÖ

#include "stdafx.h"
#include "Smtp.h"
#include "Mail.h"
#include "Options.h"

// CSmtp

STDMETHODIMP CSmtp::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_ISmtp
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}


void CSmtp::on_error(int error_id, const std::string& message)
{
	Fire_error(_bstr_t(message.c_str()));
}
void CSmtp::on_sending(size_t size, const tmail::Request& request, bool& cancel_and_disconnect)
{
	VARIANT_BOOL cancel = VARIANT_FALSE;
	Fire_sending((CommandTypeConstant)request.id, (LONG)size, &cancel);
	cancel_and_disconnect = (cancel != 0);
}
void CSmtp::on_receiving(size_t size, const tmail::Response& response, bool& cancel_and_disconnect)
{
	VARIANT_BOOL cancel = VARIANT_FALSE;
	Fire_receiving((CommandTypeConstant)response.id, (LONG)size, &cancel);
	cancel_and_disconnect = (cancel != 0);
}
void CSmtp::on_sent(const tmail::Request& request)
{
	Fire_sent((CommandTypeConstant)request.id, _bstr_t(request.c_str()));
}
void CSmtp::on_received(const tmail::Response& response)
{
	Fire_received((CommandTypeConstant)response.id, _bstr_t(response.c_str()));
}


#define VBOOL(x) ((x)?VARIANT_TRUE:VARIANT_FALSE)

STDMETHODIMP CSmtp::connect(BSTR host, LONG port, VARIANT_BOOL use_ssl, VARIANT_BOOL* pVal)
{
	if (port < 1 || port > 65535)
	{
		return E_INVALIDARG;
	}
	*pVal = VBOOL(smtp.connect((const char*)_bstr_t(host), (unsigned short)port, use_ssl != 0));
	return S_OK;
}

STDMETHODIMP CSmtp::quit(VARIANT_BOOL* pVal)
{
	*pVal = VBOOL(smtp.quit());
	return S_OK;
}

STDMETHODIMP CSmtp::auth(BSTR username, BSTR password, SmtpAuthTypeConstant authType, VARIANT_BOOL* pVal)
{
	if (authType == smtpAuthLogin)
	{
		*pVal = VBOOL(smtp.auth_login((const char*)_bstr_t(username), (const char*)_bstr_t(password)));
	}
	else if (authType == smtpAuthPlain)
	{
		*pVal = VBOOL(smtp.auth_plain((const char*)_bstr_t(username), (const char*)_bstr_t(password)));
	}
	else if (authType == smtpAuthCramMd5)
	{
		*pVal = VBOOL(smtp.auth_cram_md5((const char*)_bstr_t(username), (const char*)_bstr_t(password)));
	}
	else
	{
		return E_INVALIDARG;
	}

	return S_OK;
}

STDMETHODIMP CSmtp::get_authTypes(IOptions** pVal)
{
	*pVal = 0;
	CComObject<COptions>* options = 0;
	HRESULT hr = CComObject<COptions>::CreateInstance(&options);
	if (FAILED(hr))
		return hr;

	const std::vector<std::string>& auth_type = smtp.get_auth_type();
	for (size_t i = 0; i < auth_type.size(); i++)
	{
		options->strings.push_back(tlib::locale_to_wstring(auth_type[i]));
	}

	hr = options->QueryInterface(pVal);
	if (FAILED(hr))
	{
		delete options;
		return hr;
	}

	return S_OK;
}

STDMETHODIMP CSmtp::hello(VARIANT_BOOL* pVal)
{
	*pVal = VBOOL(smtp.hello());

	return S_OK;
}

STDMETHODIMP CSmtp::starttls(VARIANT_BOOL* pVal)
{
	*pVal = VBOOL(smtp.starttls());

	return S_OK;
}

STDMETHODIMP CSmtp::reset(VARIANT_BOOL* pVal)
{
	*pVal = VBOOL(smtp.reset());

	return S_OK;
}

STDMETHODIMP CSmtp::noop(VARIANT_BOOL* pVal)
{
	*pVal = VBOOL(smtp.noop());

	return S_OK;
}

STDMETHODIMP CSmtp::expand(BSTR mailingList, VARIANT* mails, VARIANT_BOOL* pVal)
{
	HRESULT hr = VariantClear(mails);
	if (FAILED(hr))
		return hr;

	VariantInit(mails);

	tmail::Addresses addresses;
	bool ret = smtp.expand((const char*)_bstr_t(mailingList), addresses);
	if (!ret)
	{
		*pVal = VARIANT_FALSE;
		return S_OK;
	}

	mails->vt = VT_BSTR;
	mails->bstrVal = ::SysAllocString(addresses.to_wstring().c_str());
	*pVal = VARIANT_TRUE;
	return S_OK;
}

STDMETHODIMP CSmtp::verify(BSTR name, VARIANT* mail, VARIANT_BOOL* pVal)
{
	HRESULT hr = VariantClear(mail);
	if (FAILED(hr))
		return hr;

	VariantInit(mail);

	tmail::Address address;
	bool ret = smtp.verify((const char*)_bstr_t(name), address);
	if (!ret)
	{
		*pVal = VARIANT_FALSE;
		return S_OK;
	}

	mail->vt = VT_BSTR;
	mail->bstrVal = ::SysAllocString(address.to_wstring().c_str());
	*pVal = VARIANT_TRUE;
	return S_OK;
}

STDMETHODIMP CSmtp::get_enable8Bit(VARIANT_BOOL* pVal)
{
	*pVal = VBOOL(smtp.is_enable_8bitmime());

	return S_OK;
}

STDMETHODIMP CSmtp::get_enableStartTls(VARIANT_BOOL* pVal)
{
	*pVal = VBOOL(smtp.is_enable_starttls());

	return S_OK;
}

STDMETHODIMP CSmtp::get_enablePipling(VARIANT_BOOL* pVal)
{
	*pVal = VBOOL(smtp.is_enable_pipelining());

	return S_OK;
}

STDMETHODIMP CSmtp::get_maxMailSize(LONG* pVal)
{
	*pVal = (LONG)smtp.get_max_mail_size();

	return S_OK;
}

STDMETHODIMP CSmtp::mailFrom(BSTR mailAddress, VARIANT_BOOL* pVal)
{
	tmail::Address addr = tmail::parse_address(mailAddress);
	*pVal = VBOOL(smtp.mail_from(addr));
	return S_OK;
}

STDMETHODIMP CSmtp::rcptTo(BSTR mailAddress, VARIANT_BOOL* pVal)
{
	tmail::Address addr = tmail::parse_address(mailAddress);
	*pVal = VBOOL(smtp.rcpt_to(addr));
	return S_OK;
}

STDMETHODIMP CSmtp::addressesByMail(IMail* mail, VARIANT_BOOL* pVal)
{
	try
	{
		CMail* cmail = dynamic_cast<CMail*>(mail);
		if (!cmail)
		{
			return E_INVALIDARG;
		}
		*pVal = VBOOL(smtp.send_addresses_by_mail(*(cmail->mail)));
	}
	catch (...)
	{
		return E_INVALIDARG;
	}
	return S_OK;
}

STDMETHODIMP CSmtp::sendMail(IMail* mail, VARIANT_BOOL* pVal)
{
	if (mail == 0)
		return E_INVALIDARG;
	try
	{
		CMail* cmail = dynamic_cast<CMail*>(mail);
		*pVal = VBOOL(smtp.send_mail(*(cmail->mail)));
	}
	catch (...)
	{
		return E_INVALIDARG;
	}
	return S_OK;
}
