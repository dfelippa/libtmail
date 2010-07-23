// MessageHeader.cpp : CMessageHeader µÄÊµÏÖ

#include "stdafx.h"
#include "MessageHeader.h"


// CMessageHeader

STDMETHODIMP CMessageHeader::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IMessageHeader
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CMessageHeader::get_name(BSTR* pVal)
{
	if (header)
		*pVal = ::SysAllocString(header->get_name().c_str());
	return S_OK;
}

STDMETHODIMP CMessageHeader::get_text(BSTR* pVal)
{
	if (header)
		*pVal = ::SysAllocString(
			header->get_value().c_str());
	return S_OK;
}

STDMETHODIMP CMessageHeader::put_text(BSTR newVal)
{
	if (header)
		header->parse_value(newVal);
	return S_OK;
}
