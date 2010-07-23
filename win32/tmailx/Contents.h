// Contents.h : CContents 的声明

#pragma once
#include "resource.h"       // 主符号

#include "tmailx.h"
#include "Content.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif



// CContents

class ATL_NO_VTABLE CContents :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CContents, &CLSID_Contents>,
	public ISupportErrorInfo,
	public IDispatchImpl<IContents, &IID_IContents, &LIBID_TMail, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CContents()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CONTENTS)

BEGIN_COM_MAP(CContents)
	COM_INTERFACE_ENTRY(IContents)
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

	STDMETHOD(get_item)(LONG index, IContent** pVal);
	STDMETHOD(get_count)(LONG* pVal);
	STDMETHOD(clear)(void);
	STDMETHOD(erase)(LONG index);
	STDMETHOD(get__NewEnum)(IUnknown** pVal);
	STDMETHOD(add)(IContent* content);

	tmail::ContentPtr parent_conent;
};

//OBJECT_ENTRY_AUTO(__uuidof(Contents), CContents)
OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO(__uuidof(Contents), CContents)