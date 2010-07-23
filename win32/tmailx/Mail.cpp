// Mail.cpp : CMail µÄÊµÏÖ

#include "stdafx.h"
#include "Mail.h"
#include <ATLComTime.h>

// CMail

STDMETHODIMP CMail::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IMail
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CMail::get_from(BSTR* pVal)
{
	tmail::AddressHeaderPtr hd = mail->get_from();
	if (hd)
	{
		*pVal = ::SysAllocString(hd->get_value().c_str());
	}
	else
	{
		*pVal = 0;
	}
	return S_OK;
}

STDMETHODIMP CMail::put_from(BSTR newVal)
{
	mail->set_from(newVal);
	return S_OK;
}

STDMETHODIMP CMail::get_to(BSTR* pVal)
{
	tmail::AddressHeaderPtr hd = mail->get_to();
	if (hd)
	{
		*pVal = ::SysAllocString(hd->get_value().c_str());
	}
	else
	{
		*pVal = 0;
	}

	return S_OK;
}

STDMETHODIMP CMail::put_to(BSTR newVal)
{
	mail->set_to(newVal);
	return S_OK;
}

STDMETHODIMP CMail::get_cc(BSTR* pVal)
{
	tmail::AddressHeaderPtr hd = mail->get_cc();
	if (hd)
	{
		*pVal = ::SysAllocString(hd->get_value().c_str());
	}
	else
	{
		*pVal = 0;
	}

	return S_OK;
}

STDMETHODIMP CMail::put_cc(BSTR newVal)
{
	mail->set_cc(newVal);

	return S_OK;
}

STDMETHODIMP CMail::get_bcc(BSTR* pVal)
{
	tmail::AddressHeaderPtr hd = mail->get_bcc();
	if (hd)
	{
		*pVal = ::SysAllocString(hd->get_value().c_str());
	}
	else
	{
		*pVal = 0;
	}

	return S_OK;
}

STDMETHODIMP CMail::put_bcc(BSTR newVal)
{
	mail->set_bcc(newVal);

	return S_OK;
}

STDMETHODIMP CMail::get_subject(BSTR* pVal)
{
	tmail::TextHeaderPtr hd = mail->get_subject();
	if (hd)
	{
		*pVal = ::SysAllocString(hd->get_value().c_str());
	}
	else
	{
		*pVal = 0;
	}

	return S_OK;
}

STDMETHODIMP CMail::put_subject(BSTR newVal)
{
	mail->set_subject(newVal);

	return S_OK;
}

STDMETHODIMP CMail::get_content(IContent** pVal)
{
	CComObject<CContent>* content = 0;
	HRESULT hr = CComObject<CContent>::CreateInstance(&content);
	if (FAILED(hr))
		return hr;
	content->content = mail;
	hr = content->QueryInterface(pVal);
	if (FAILED(hr))
	{
		delete content;
		return hr;
	}
	return S_OK;
}

STDMETHODIMP CMail::get_date(DATE* pVal)
{
	tmail::DatetimeHeaderPtr hd = mail->get_date();
	if (hd)
	{
		COleDateTime vtime(hd->get_time()._tm);
		*pVal = vtime;
	}
	else
	{
		*pVal = 0;
	}
	return S_OK;
}

STDMETHODIMP CMail::put_date(DATE newVal)
{
	COleDateTime vtime(newVal);
	
	tlib::Time tm;
	tm.parse((LPCTSTR)vtime.Format(L"%Y-%m-%d %H:%M:%S"));

	mail->set_date(tm);

	return S_OK;
}
