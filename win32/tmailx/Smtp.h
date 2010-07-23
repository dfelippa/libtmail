// Smtp.h : CSmtp µÄÉùÃ÷

#pragma once
#include "resource.h"       // Ö÷·ûºÅ

#include "tmailx.h"
#include "_IClientEvents_CP.h"
#include "../../src/smtp.h"

// CSmtp

class ATL_NO_VTABLE CSmtp :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSmtp, &CLSID_Smtp>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CSmtp>,
	public CProxy_IClientEvents<CSmtp>,
	public IDispatchImpl<ISmtp, &IID_ISmtp, &LIBID_TMail, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CSmtp()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SMTP)


BEGIN_COM_MAP(CSmtp)
	COM_INTERFACE_ENTRY(ISmtp)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CSmtp)
	CONNECTION_POINT_ENTRY(__uuidof(_IClientEvents))
END_CONNECTION_POINT_MAP()
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		smtp.signal_error().connect(sigc::mem_fun(this, &CSmtp::on_error));
		smtp.signal_received().connect(sigc::mem_fun(this, &CSmtp::on_received));
		smtp.signal_sent().connect(sigc::mem_fun(this, &CSmtp::on_sent));
		smtp.signal_receiving_report().connect(sigc::mem_fun(this, &CSmtp::on_receiving));
		smtp.signal_sending_report().connect(sigc::mem_fun(this, &CSmtp::on_sending));

		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(contact)(BSTR host, LONG port, VARIANT_BOOL use_ssl, VARIANT_BOOL* pVal);
	STDMETHOD(quit)(VARIANT_BOOL* pVal);
	STDMETHOD(auth)(BSTR username, BSTR password, SmtpAuthTypeConstant authType, VARIANT_BOOL* pVal);
	STDMETHOD(get_authTypes)(IOptions** pVal);
	STDMETHOD(hello)(VARIANT_BOOL* pVal);
	STDMETHOD(starttls)(VARIANT_BOOL* pVal);
	STDMETHOD(reset)(VARIANT_BOOL* pVal);
	STDMETHOD(noop)(VARIANT_BOOL* pVal);
	STDMETHOD(expand)(BSTR mailingList, VARIANT* mails, VARIANT_BOOL* pVal);
	STDMETHOD(verify)(BSTR name, VARIANT* mail, VARIANT_BOOL* pVal);
	STDMETHOD(get_enable8Bit)(VARIANT_BOOL* pVal);
	STDMETHOD(get_enableStartTls)(VARIANT_BOOL* pVal);
	STDMETHOD(get_enablePipling)(VARIANT_BOOL* pVal);
	STDMETHOD(get_maxMailSize)(LONG* pVal);
	STDMETHOD(mailFrom)(BSTR mailAddress, VARIANT_BOOL* pVal);
	STDMETHOD(rcptTo)(BSTR mailAddress, VARIANT_BOOL* pVal);
	STDMETHOD(addressesByMail)(IMail* mail, VARIANT_BOOL* pVal);
	STDMETHOD(sendMail)(IMail* mail, VARIANT_BOOL* pVal);
public:
	void on_error(int error_id, const std::string& message);
	void on_sending(size_t size, const tmail::Request& request, bool& cancel_and_disconnect);
	void on_receiving(size_t size, const tmail::Response& response, bool& cancel_and_disconnect);
	void on_sent(const tmail::Request& request);
	void on_received(const tmail::Response& response);

public:
	tmail::Smtp smtp;
};

OBJECT_ENTRY_AUTO(__uuidof(Smtp), CSmtp)
