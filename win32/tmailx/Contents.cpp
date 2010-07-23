// Contents.cpp : CContents µÄÊµÏÖ

#include "stdafx.h"
#include "Contents.h"
#include "Content.h"

// CContents

STDMETHODIMP CContents::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IContents
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CContents::get_item(LONG index, IContent** pVal)
{
	if (index < 0 || index >= (LONG)parent_conent->multiparts.count())
	{
		return DISP_E_BADINDEX;
	}

	tmail::ContentPtr content = parent_conent->multiparts[index];
	CComObject<CContent>* pcontent = 0;
	HRESULT hr = CComObject<CContent>::CreateInstance(&pcontent);
	if (FAILED(hr))
		return hr;
	pcontent->content = content;
	hr = pcontent->QueryInterface(pVal);
	if (FAILED(hr))
	{
		delete pcontent;
		return hr;
	}
	return S_OK;
}

STDMETHODIMP CContents::get_count(LONG* pVal)
{
	*pVal = (LONG)parent_conent->multiparts.count();

	return S_OK;
}

STDMETHODIMP CContents::clear(void)
{
	parent_conent->multiparts.clear();
	return S_OK;
}

STDMETHODIMP CContents::erase(LONG index)
{
	if (index < 0 || index >= (LONG)parent_conent->multiparts.count())
	{
		return DISP_E_BADINDEX;
	}

	parent_conent->multiparts.erase(index);

	return S_OK;
}

typedef CComObject<CComEnum<IEnumVARIANT, &IID_IEnumVARIANT,
		VARIANT, _Copy<VARIANT> > > CEnumVariant;

STDMETHODIMP CContents::get__NewEnum(IUnknown** pVal)
{
	if (pVal == 0)
		return E_INVALIDARG;
	*pVal = 0;

	CEnumVariant* penum = 0;
	HRESULT hr = CEnumVariant::CreateInstance(&penum);
	if (FAILED(hr))
		return hr;

	CComVariant* ptr_array = new CComVariant[parent_conent->multiparts.count()];
	for (size_t i = 0; i < parent_conent->multiparts.count(); i++)
	{
		CComObject<CContent>* content = 0;
		hr = CComObject<CContent>::CreateInstance(&content);
		if (FAILED(hr))
		{
			delete [] ptr_array;
			delete penum;
			return hr;
		}
		
		content->content = parent_conent->multiparts[i];

		LPDISPATCH lpDisp = NULL;
		content->QueryInterface(IID_IDispatch, (void**)&lpDisp);
		if (FAILED(hr))
		{
			delete [] ptr_array;
			delete penum;
			return hr;
		}
		ptr_array[i].vt = VT_DISPATCH;
		ptr_array[i].pdispVal = lpDisp;
	}

	hr = penum->Init(&ptr_array[0], &ptr_array[parent_conent->multiparts.count()], 0, AtlFlagCopy);
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

STDMETHODIMP CContents::add(IContent* content)
{
	if (content == 0)
		return E_INVALIDARG;
	try
	{
		CContent* pcontent = dynamic_cast<CContent*>(content);
		parent_conent->multiparts.add(pcontent->content);
	}
	catch (...)
	{
		return E_INVALIDARG;
	}
	return S_OK;
}
