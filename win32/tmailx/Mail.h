// Mail.h : CMail 的声明

#pragma once
#include "resource.h"       // 主符号

#include "tmailx.h"
#include "Content.h"
#include "../../src/mail.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif



// CMail

class ATL_NO_VTABLE CMail : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMail, &CLSID_Mail>,
	public ISupportErrorInfo,
	public IDispatchImpl<IMail, &IID_IMail, &LIBID_TMail, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CMail()//: _unknown(0)
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MAIL)


BEGIN_COM_MAP(CMail)
	COM_INTERFACE_ENTRY(IMail)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
//	COM_INTERFACE_ENTRY_AGGREGATE(__uuidof(IContent), _unknown)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		mail = tmail::MailPtr(new tmail::Mail());
		//CComObject<CContent>* content;
		//HRESULT hr = CComObject<CContent>::CreateInstance(&content);
		//if (FAILED(hr))
		//	return hr;
		//content->content = mail;
		//hr = content->QueryInterface(&_unknown);
		//if (FAILED(hr))
		//{
		//	delete content;
		//	return hr;
		//}
		return S_OK;
	}

	void FinalRelease()
	{
		//_unknown->Release();
	}

public:

	STDMETHOD(get_from)(BSTR* pVal);
	STDMETHOD(put_from)(BSTR newVal);

public:
	tmail::MailPtr mail;

	//IUnknown* _unknown;
	STDMETHOD(get_to)(BSTR* pVal);
	STDMETHOD(put_to)(BSTR newVal);
	STDMETHOD(get_cc)(BSTR* pVal);
	STDMETHOD(put_cc)(BSTR newVal);
	STDMETHOD(get_bcc)(BSTR* pVal);
	STDMETHOD(put_bcc)(BSTR newVal);
	STDMETHOD(get_subject)(BSTR* pVal);
	STDMETHOD(put_subject)(BSTR newVal);
	STDMETHOD(get_content)(IContent** pVal);
	STDMETHOD(get_date)(DATE* pVal);
	STDMETHOD(put_date)(DATE newVal);
};

OBJECT_ENTRY_AUTO(__uuidof(Mail), CMail)
