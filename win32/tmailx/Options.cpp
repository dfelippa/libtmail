// Options.cpp : COptions µÄÊµÏÖ

#include "stdafx.h"
#include "Options.h"


// COptions

STDMETHODIMP COptions::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IOptions
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP COptions::get_item(LONG index, BSTR* pVal)
{
	if (index < 0 || index >= (LONG)strings.size())
		return DISP_E_BADINDEX;
	
	*pVal = ::SysAllocString(strings[index].c_str());

	return S_OK;
}

STDMETHODIMP COptions::get_count(LONG* pVal)
{
	*pVal = (LONG)strings.size();

	return S_OK;
}
