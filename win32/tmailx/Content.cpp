// Content.cpp : CContent µÄÊµÏÖ

#include "stdafx.h"
#include "Content.h"
#include "Headers.h"
#include "Contents.h"
// CContent

STDMETHODIMP CContent::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IContent
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}


STDMETHODIMP CContent::parse(SAFEARRAY* data, VARIANT_BOOL only_headers)
{
	char* byte_array;
	HRESULT hr = SafeArrayAccessData(data, (void**)&byte_array);
	if (FAILED(hr))
	{
		return hr;
	}

	content->parse(byte_array, data->rgsabound[0].cElements, only_headers != 0);
	SafeArrayUnaccessData(data);
	return S_OK;
}

STDMETHODIMP CContent::save(BSTR filename)
{
	if (!content->save(filename))
	{
		set_error(L"Save file error.", L"Content");
		return E_FAIL;
	}
	else
		return S_OK;
}

STDMETHODIMP CContent::load(BSTR filename, VARIANT_BOOL only_header)
{
	if (!content->load(filename, only_header != 0))
	{
		set_error(L"Load file error.", L"Content");
		return E_FAIL;
	}
	return S_OK;
}

STDMETHODIMP CContent::setBodyText(BSTR text)
{
	content->set_body_text(text);
	return S_OK;
}

STDMETHODIMP CContent::loadBody(BSTR filename)
{
	if (!content->load_body(filename))
	{
		set_error(L"Load file error.", L"Content");
		return E_FAIL;
	}
	return S_OK;
}

STDMETHODIMP CContent::get_headers(IHeaders** pVal)
{
	*pVal = 0;
	CComObject<CHeaders>* headers;
	HRESULT hr = CComObject<CHeaders>::CreateInstance(&headers);
	if (FAILED(hr))
	{
		return E_FAIL;
	}
	headers->content = content;
	hr = headers->QueryInterface(pVal);
	if (FAILED(hr))
	{
		delete headers;
		return E_FAIL;
	}
	return S_OK;
}

STDMETHODIMP CContent::get_body(SAFEARRAY** pVal)
{
	*pVal = SafeArrayCreateVector(VT_UI1, 0, (ULONG)content->body.size());
	if (*pVal == 0)
	{
		return E_FAIL;
	}
	char* byte_array;
	HRESULT hr = SafeArrayAccessData(*pVal, (void**)&byte_array);
	if (FAILED(hr))
	{
		SafeArrayDestroy(*pVal);
		return hr;
	}
	memcpy(byte_array, content->body.c_str(), content->body.size());
	SafeArrayUnaccessData(*pVal);
	return S_OK;
}

STDMETHODIMP CContent::put_body(SAFEARRAY* newVal)
{
	char* byte_array;
	HRESULT hr = SafeArrayAccessData(newVal, (void**)&byte_array);
	if (FAILED(hr))
	{
		return hr;
	}
	content->body.assign(byte_array, newVal->rgsabound[0].cElements);
	SafeArrayUnaccessData(newVal);
	return S_OK;
}

STDMETHODIMP CContent::getBodyText(BSTR* pVal)
{
	*pVal = ::SysAllocString(content->get_body_text().c_str());
	return S_OK;
}

STDMETHODIMP CContent::saveBody(BSTR filename)
{
	if (!content->save_body(filename))
	{
		set_error(L"Save file error.", L"Content");
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP CContent::get_multiparts(IContents** pVal)
{
	CComObject<CContents>* contents = 0;
	HRESULT hr = CComObject<CContents>::CreateInstance(&contents);
	if (FAILED(hr))
		return hr;
	contents->parent_conent = content;
	hr = contents->QueryInterface(pVal);
	if (FAILED(hr))
	{
		delete contents;
		return hr;
	}
	return S_OK;
}

STDMETHODIMP CContent::createAlternativeBody(BSTR text, BSTR html, VARIANT attachments)
{
	std::vector<std::wstring> attachs;
	HRESULT hr = get_strings_by_variant(&attachments, attachs);
	if (FAILED(hr))
		return hr;

	try
	{
		content->create_normal_body(text, html, attachs);
	}
	catch (const std::exception& e)
	{
		set_error(_bstr_t(e.what()), L"Content");
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP CContent::createTextBody(BSTR text, VARIANT attachments)
{
	return createAlternativeBody(text, L"", attachments);
}

STDMETHODIMP CContent::createHtmlBody(BSTR html, VARIANT attachments)
{
	return createAlternativeBody(L"", html, attachments);
}

STDMETHODIMP CContent::createRelatedBody(BSTR html, VARIANT pictures, VARIANT attachments, 
										 VARIANT_BOOL use_cid)
{
	std::vector<std::wstring> pics;
	HRESULT hr = get_strings_by_variant(&pictures, pics);
	if (FAILED(hr))
		return hr;

	std::vector<std::wstring> attachs;
	hr = get_strings_by_variant(&attachments, attachs);
	if (FAILED(hr))
		return hr;

	try
	{
		content->create_related_body(html, pics, attachs, use_cid != 0);
	}
	catch (const std::exception& e)
	{
		set_error(_bstr_t(e.what()), L"Content");
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP CContent::createAlternativeBodyF(BSTR textFile, 
											  BSTR htmlFile, 
											  VARIANT attachments)
{
	std::wstring text;
	std::wstring html;
	try
	{
		text = tlib::load_text_file_as_wstring(textFile);
		html = tlib::load_text_file_as_wstring(htmlFile);
	}
	catch (const std::exception& e)
	{
		if (e.what())
		set_error(_bstr_t(e.what()), L"Content");
		return E_FAIL;
	}
	return createAlternativeBody((BSTR)text.c_str(), (BSTR)html.c_str(), attachments);
}

STDMETHODIMP CContent::createTextBodyF(BSTR textFile, VARIANT attachments)
{
	std::wstring text;
	try
	{
		text = tlib::load_text_file_as_wstring(textFile);
	}
	catch (const std::exception& e)
	{
		if (e.what())
		set_error(_bstr_t(e.what()), L"Content");
		return E_FAIL;
	}
	return createTextBody((BSTR)text.c_str(), attachments);
}

STDMETHODIMP CContent::createHtmlBodyF(BSTR htmlFile, VARIANT attachments)
{
	std::wstring html;
	try
	{
		html = tlib::load_text_file_as_wstring(htmlFile);
	}
	catch (const std::exception& e)
	{
		if (e.what())
		set_error(_bstr_t(e.what()), L"Content");
		return E_FAIL;
	}
	return createHtmlBody((BSTR)html.c_str(), attachments);
}

STDMETHODIMP CContent::createRelatedBodyF(BSTR htmlFile, 
										  VARIANT pictures, 
										  VARIANT attachments, 
										  VARIANT_BOOL use_cid)
{
	std::wstring html;
	try
	{
		html = tlib::load_text_file_as_wstring(htmlFile);
	}
	catch (const std::exception& e)
	{
		if (e.what())
		set_error(_bstr_t(e.what()), L"Content");
		return E_FAIL;
	}

	return createRelatedBody((BSTR)html.c_str(), pictures, attachments, use_cid);
}
STDMETHODIMP CContent::generateId(void)
{
	content->generate_id();
	return S_OK;
}

STDMETHODIMP CContent::get_contentType(BSTR* pVal)
{
	tmail::ContentHeaderPtr hd = content->get_content_type();
	if (hd)
		*pVal = ::SysAllocString(hd->get_major().c_str());
	return S_OK;
}

STDMETHODIMP CContent::get_filename(BSTR* pVal)
{
	tmail::ContentHeaderPtr hd = content->get_content_disposition();
	if (hd)
	{
		tmail::Parameters& params = hd->get_parameters();
		for (size_t i = 0; i < params.count(); i++)
		{
			if (tlib::to_lower_copy(params[i].name) == L"filename")
				*pVal = ::SysAllocString(params[i].value.c_str());
		}
	}
	return S_OK;
}

STDMETHODIMP CContent::get_extname(BSTR* pVal)
{
	BSTR bstr = 0;
	HRESULT hr = get_filename(&bstr);
	if (FAILED(hr))
		return hr;
	if (bstr)
	{
		std::vector<std::wstring> strs;
		tlib::split(bstr, L".", strs);
		::SysFreeString(bstr);
		if (strs.size() > 1)
		{
			*pVal = ::SysAllocString(strs[strs.size() - 1].c_str());
			return S_OK;
		}
	}

	tmail::ContentHeaderPtr hd = content->get_content_type();
	if (hd)
	{
		const char* ext = tmail::mime_to_ext(tlib::wstring_to_utf8(hd->get_major()).c_str());
		if (ext)
		{
			*pVal = _bstr_t(ext).copy(true);
		}
	}
	return S_OK;
}
