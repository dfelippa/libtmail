// Headers.cpp : CHeaders µÄÊµÏÖ

#include "stdafx.h"
#include "Headers.h"


// CHeaders

STDMETHODIMP CHeaders::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IHeaders
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CHeaders::get_item(BSTR name, IMessageHeader** pVal)
{
	*pVal = 0;
	tmail::HeaderPtr header = content->headers.get_header(name);
	if (header)
	{
		CComObject<CMessageHeader>* msgHeader = 0;
		HRESULT hr = CComObject<CMessageHeader>::CreateInstance(&msgHeader);
		if (FAILED(hr))
		{
			return hr;
		}
		
		msgHeader->header = header;
		hr = msgHeader->QueryInterface(pVal);
		return hr;
	}
	else
		return DISP_E_BADINDEX;
}

STDMETHODIMP CHeaders::put_item(BSTR name, BSTR newVal)
{
	tmail::HeaderPtr header = content->headers.get_header(name);
	if (header)
	{
		header->parse_value(newVal);
	}
	else
	{
		header = content->headers.add(name);
		header->parse_value(newVal);
	}
	return S_OK;
}

STDMETHODIMP CHeaders::get_count(LONG* pVal)
{
	*pVal = (LONG)content->headers.count();

	return S_OK;
}

STDMETHODIMP CHeaders::clear(void)
{
	content->headers.clear();

	return S_OK;
}

STDMETHODIMP CHeaders::erase(BSTR name)
{
	content->headers.erase(name);

	return S_OK;
}

typedef CComObject<CComEnum<IEnumVARIANT, &IID_IEnumVARIANT,
		VARIANT, _Copy<VARIANT> > > CEnumVariant;

STDMETHODIMP CHeaders::get__NewEnum(IUnknown** pVal)
{
	if (pVal == 0)
		return E_INVALIDARG;
	*pVal = 0;

	CEnumVariant* penum = 0;
	HRESULT hr = CEnumVariant::CreateInstance(&penum);
	if (FAILED(hr))
		return hr;

	CComVariant* ptr_array = new CComVariant[content->headers.count()];
	for (size_t i = 0; i < content->headers.count(); i++)
	{
		CComObject<CMessageHeader>* msgHeader = 0;
		hr = CComObject<CMessageHeader>::CreateInstance(&msgHeader);
		if (FAILED(hr))
		{
			delete [] ptr_array;
			delete penum;
			return hr;
		}
		
		msgHeader->header = content->headers[i];

		LPDISPATCH lpDisp = NULL;
		msgHeader->QueryInterface(IID_IDispatch, (void**)&lpDisp);
		if (FAILED(hr))
		{
			delete [] ptr_array;
			delete penum;
			return hr;
		}
		ptr_array[i].vt = VT_DISPATCH;
		ptr_array[i].pdispVal = lpDisp;
	}

	hr = penum->Init(&ptr_array[0], &ptr_array[content->headers.count()], 0, AtlFlagCopy);
	if (FAILED(hr))
	{
		delete [] ptr_array;
		delete penum;
		return hr;
	}
	hr = penum->QueryInterface(IID_IEnumVARIANT, (void**)pVal);
	if (FAILED(hr))
	{
		delete [] ptr_array;
		delete penum;
		return hr;
	}

	delete [] ptr_array;
	return S_OK;
}

STDMETHODIMP CHeaders::add(BSTR name, IMessageHeader** pRet)
{
	tmail::HeaderPtr header = content->headers.add(name);
	CComObject<CMessageHeader>* msgHeader = 0;
	HRESULT hr = CComObject<CMessageHeader>::CreateInstance(&msgHeader);
	if (FAILED(hr))
	{
		return hr;
	}
	
	msgHeader->header = header;
	msgHeader->QueryInterface(pRet);		

	return S_OK;
}

STDMETHODIMP CHeaders::exist(BSTR name, VARIANT_BOOL* pVal)
{
	tmail::HeaderPtr header = content->headers.get_header(name);
	if (header)
		*pVal = VARIANT_TRUE;
	else
		*pVal = VARIANT_FALSE;
	return S_OK;
}
