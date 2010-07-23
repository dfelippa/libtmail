// MessageHeader.h : CMessageHeader µÄÉùÃ÷

#pragma once
#include "resource.h"       // Ö÷·ûºÅ

#include "tmailx.h"
#include "../../src/header.h"


// CMessageHeader

class ATL_NO_VTABLE CMessageHeader :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMessageHeader, &CLSID_MessageHeader>,
	public ISupportErrorInfo,
	public IDispatchImpl<IMessageHeader, &IID_IMessageHeader, &LIBID_TMail, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CMessageHeader()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MESSAGEHEADER)


BEGIN_COM_MAP(CMessageHeader)
	COM_INTERFACE_ENTRY(IMessageHeader)
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

	STDMETHOD(get_name)(BSTR* pVal);
	STDMETHOD(get_text)(BSTR* pVal);
	STDMETHOD(put_text)(BSTR newVal);

	tmail::HeaderPtr header;
};

// OBJECT_ENTRY_AUTO(__uuidof(MessageHeader), CMessageHeader)
OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO(__uuidof(MessageHeader), CMessageHeader)
