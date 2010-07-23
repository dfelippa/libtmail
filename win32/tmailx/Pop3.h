// Pop3.h : CPop3 µÄÉùÃ÷

#pragma once
#include "resource.h"       // Ö÷·ûºÅ

#include "tmailx.h"
#include "_IClientEvents_CP.h"
#include "../../src/pop3.h"

// CPop3

class ATL_NO_VTABLE CPop3 :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPop3, &CLSID_Pop3>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CPop3>,
	public CProxy_IClientEvents<CPop3>,
	public IDispatchImpl<IPop3, &IID_IPop3, &LIBID_TMail, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CPop3()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_POP3)


BEGIN_COM_MAP(CPop3)
	COM_INTERFACE_ENTRY(IPop3)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CPop3)
	CONNECTION_POINT_ENTRY(__uuidof(_IClientEvents))
END_CONNECTION_POINT_MAP()
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		pop3.signal_error().connect(sigc::mem_fun(this, &CPop3::on_error));
		pop3.signal_received().connect(sigc::mem_fun(this, &CPop3::on_received));
		pop3.signal_sent().connect(sigc::mem_fun(this, &CPop3::on_sent));
		pop3.signal_receiving_report().connect(sigc::mem_fun(this, &CPop3::on_receiving));
		pop3.signal_sending_report().connect(sigc::mem_fun(this, &CPop3::on_sending));

		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(contact)(BSTR host, LONG port, VARIANT_BOOL use_ssl, VARIANT_BOOL* pVal);
	STDMETHOD(quit)(VARIANT_BOOL* pVal);
	STDMETHOD(auth)(BSTR username, BSTR password, Pop3AuthTypeConstant authType, VARIANT_BOOL* pVal);
	STDMETHOD(capability)(VARIANT_BOOL* pVal);
	STDMETHOD(list)(VARIANT* mailIndex, VARIANT_BOOL* pVal);
	STDMETHOD(uidl)(VARIANT* uidIndex, VARIANT_BOOL* pVal);
	STDMETHOD(stat)(VARIANT* mailCount, VARIANT* totalSize, VARIANT_BOOL* pVal);
	STDMETHOD(starttls)(VARIANT_BOOL* pVal);
	STDMETHOD(returnMailHeader)(LONG id, IMail** pMail);
	STDMETHOD(returnMail)(LONG id, IMail** pMail);
	STDMETHOD(deleteMail)(LONG id, VARIANT_BOOL* pVal);
	STDMETHOD(noop)(VARIANT_BOOL* pVal);
	STDMETHOD(reset)(VARIANT_BOOL* pVal);
	STDMETHOD(get_authTypes)(IOptions** pVal);
	STDMETHOD(get_enableStartTls)(VARIANT_BOOL* pVal);

public:
	void on_error(int error_id, const std::string& message);
	void on_sending(size_t size, const tmail::Request& request, bool& cancel_and_disconnect);
	void on_receiving(size_t size, const tmail::Response& response, bool& cancel_and_disconnect);
	void on_sent(const tmail::Request& request);
	void on_received(const tmail::Response& response);

public:
	tmail::Pop3 pop3;

};

OBJECT_ENTRY_AUTO(__uuidof(Pop3), CPop3)
