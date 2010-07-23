// Headers.h : CHeaders 的声明

#pragma once
#include "resource.h"       // 主符号

#include "tmailx.h"
#include "MessageHeader.h"
#include "../../src/content.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif



// CHeaders

class ATL_NO_VTABLE CHeaders :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CHeaders, &CLSID_Headers>,
	public ISupportErrorInfo,
	public IDispatchImpl<IHeaders, &IID_IHeaders, &LIBID_TMail, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CHeaders()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_HEADERS)

BEGIN_COM_MAP(CHeaders)
	COM_INTERFACE_ENTRY(IHeaders)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(get_item)(BSTR name, IMessageHeader** pVal);
	STDMETHOD(put_item)(BSTR name, BSTR newVal);
	STDMETHOD(get_count)(LONG* pVal);
	STDMETHOD(clear)(void);
	STDMETHOD(erase)(BSTR name);
	STDMETHOD(get__NewEnum)(IUnknown** pVal);
	STDMETHOD(add)(BSTR name, IMessageHeader** pRet);
	STDMETHOD(exist)(BSTR name, VARIANT_BOOL* pVal);

public:
	tmail::ContentPtr content;
};

// OBJECT_ENTRY_AUTO(__uuidof(Headers), CHeaders)
OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO(__uuidof(Headers), CHeaders)
