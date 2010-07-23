

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Fri Jul 23 23:54:58 2010
 */
/* Compiler settings for .\tmailx.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __tmailx_h__
#define __tmailx_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMessageHeader_FWD_DEFINED__
#define __IMessageHeader_FWD_DEFINED__
typedef interface IMessageHeader IMessageHeader;
#endif 	/* __IMessageHeader_FWD_DEFINED__ */


#ifndef __IHeaders_FWD_DEFINED__
#define __IHeaders_FWD_DEFINED__
typedef interface IHeaders IHeaders;
#endif 	/* __IHeaders_FWD_DEFINED__ */


#ifndef __IContent_FWD_DEFINED__
#define __IContent_FWD_DEFINED__
typedef interface IContent IContent;
#endif 	/* __IContent_FWD_DEFINED__ */


#ifndef __IContents_FWD_DEFINED__
#define __IContents_FWD_DEFINED__
typedef interface IContents IContents;
#endif 	/* __IContents_FWD_DEFINED__ */


#ifndef __IMail_FWD_DEFINED__
#define __IMail_FWD_DEFINED__
typedef interface IMail IMail;
#endif 	/* __IMail_FWD_DEFINED__ */


#ifndef __IOptions_FWD_DEFINED__
#define __IOptions_FWD_DEFINED__
typedef interface IOptions IOptions;
#endif 	/* __IOptions_FWD_DEFINED__ */


#ifndef __ISmtp_FWD_DEFINED__
#define __ISmtp_FWD_DEFINED__
typedef interface ISmtp ISmtp;
#endif 	/* __ISmtp_FWD_DEFINED__ */


#ifndef __IPop3_FWD_DEFINED__
#define __IPop3_FWD_DEFINED__
typedef interface IPop3 IPop3;
#endif 	/* __IPop3_FWD_DEFINED__ */


#ifndef __Content_FWD_DEFINED__
#define __Content_FWD_DEFINED__

#ifdef __cplusplus
typedef class Content Content;
#else
typedef struct Content Content;
#endif /* __cplusplus */

#endif 	/* __Content_FWD_DEFINED__ */


#ifndef __MessageHeader_FWD_DEFINED__
#define __MessageHeader_FWD_DEFINED__

#ifdef __cplusplus
typedef class MessageHeader MessageHeader;
#else
typedef struct MessageHeader MessageHeader;
#endif /* __cplusplus */

#endif 	/* __MessageHeader_FWD_DEFINED__ */


#ifndef __Headers_FWD_DEFINED__
#define __Headers_FWD_DEFINED__

#ifdef __cplusplus
typedef class Headers Headers;
#else
typedef struct Headers Headers;
#endif /* __cplusplus */

#endif 	/* __Headers_FWD_DEFINED__ */


#ifndef __Contents_FWD_DEFINED__
#define __Contents_FWD_DEFINED__

#ifdef __cplusplus
typedef class Contents Contents;
#else
typedef struct Contents Contents;
#endif /* __cplusplus */

#endif 	/* __Contents_FWD_DEFINED__ */


#ifndef __Mail_FWD_DEFINED__
#define __Mail_FWD_DEFINED__

#ifdef __cplusplus
typedef class Mail Mail;
#else
typedef struct Mail Mail;
#endif /* __cplusplus */

#endif 	/* __Mail_FWD_DEFINED__ */


#ifndef ___IClientEvents_FWD_DEFINED__
#define ___IClientEvents_FWD_DEFINED__
typedef interface _IClientEvents _IClientEvents;
#endif 	/* ___IClientEvents_FWD_DEFINED__ */


#ifndef __Options_FWD_DEFINED__
#define __Options_FWD_DEFINED__

#ifdef __cplusplus
typedef class Options Options;
#else
typedef struct Options Options;
#endif /* __cplusplus */

#endif 	/* __Options_FWD_DEFINED__ */


#ifndef __Smtp_FWD_DEFINED__
#define __Smtp_FWD_DEFINED__

#ifdef __cplusplus
typedef class Smtp Smtp;
#else
typedef struct Smtp Smtp;
#endif /* __cplusplus */

#endif 	/* __Smtp_FWD_DEFINED__ */


#ifndef __Pop3_FWD_DEFINED__
#define __Pop3_FWD_DEFINED__

#ifdef __cplusplus
typedef class Pop3 Pop3;
#else
typedef struct Pop3 Pop3;
#endif /* __cplusplus */

#endif 	/* __Pop3_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IMessageHeader_INTERFACE_DEFINED__
#define __IMessageHeader_INTERFACE_DEFINED__

/* interface IMessageHeader */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMessageHeader;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4D9B8FE2-E781-4B07-90A4-F5A118DACF55")
    IMessageHeader : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_text( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_text( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMessageHeaderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMessageHeader * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMessageHeader * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMessageHeader * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMessageHeader * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMessageHeader * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMessageHeader * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMessageHeader * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_name )( 
            IMessageHeader * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_text )( 
            IMessageHeader * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_text )( 
            IMessageHeader * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IMessageHeaderVtbl;

    interface IMessageHeader
    {
        CONST_VTBL struct IMessageHeaderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMessageHeader_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMessageHeader_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMessageHeader_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMessageHeader_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMessageHeader_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMessageHeader_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMessageHeader_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IMessageHeader_get_name(This,pVal)	\
    (This)->lpVtbl -> get_name(This,pVal)

#define IMessageHeader_get_text(This,pVal)	\
    (This)->lpVtbl -> get_text(This,pVal)

#define IMessageHeader_put_text(This,newVal)	\
    (This)->lpVtbl -> put_text(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMessageHeader_get_name_Proxy( 
    IMessageHeader * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IMessageHeader_get_name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMessageHeader_get_text_Proxy( 
    IMessageHeader * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IMessageHeader_get_text_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMessageHeader_put_text_Proxy( 
    IMessageHeader * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IMessageHeader_put_text_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMessageHeader_INTERFACE_DEFINED__ */


#ifndef __IHeaders_INTERFACE_DEFINED__
#define __IHeaders_INTERFACE_DEFINED__

/* interface IHeaders */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IHeaders;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("883A711E-6C77-4ACF-804F-767CFC0DC50A")
    IHeaders : public IDispatch
    {
    public:
        virtual /* [defaultcollelem][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_item( 
            /* [in] */ BSTR name,
            /* [retval][out] */ IMessageHeader **pVal) = 0;
        
        virtual /* [defaultcollelem][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_item( 
            /* [in] */ BSTR name,
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE erase( 
            /* [in] */ BSTR name) = 0;
        
        virtual /* [hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE add( 
            /* [in] */ BSTR name,
            /* [retval][out] */ IMessageHeader **pRet) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE exist( 
            /* [in] */ BSTR name,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHeadersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHeaders * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHeaders * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHeaders * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHeaders * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHeaders * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHeaders * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHeaders * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [defaultcollelem][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_item )( 
            IHeaders * This,
            /* [in] */ BSTR name,
            /* [retval][out] */ IMessageHeader **pVal);
        
        /* [defaultcollelem][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_item )( 
            IHeaders * This,
            /* [in] */ BSTR name,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_count )( 
            IHeaders * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *clear )( 
            IHeaders * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *erase )( 
            IHeaders * This,
            /* [in] */ BSTR name);
        
        /* [hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IHeaders * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *add )( 
            IHeaders * This,
            /* [in] */ BSTR name,
            /* [retval][out] */ IMessageHeader **pRet);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *exist )( 
            IHeaders * This,
            /* [in] */ BSTR name,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        END_INTERFACE
    } IHeadersVtbl;

    interface IHeaders
    {
        CONST_VTBL struct IHeadersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHeaders_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHeaders_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHeaders_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHeaders_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IHeaders_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IHeaders_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IHeaders_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IHeaders_get_item(This,name,pVal)	\
    (This)->lpVtbl -> get_item(This,name,pVal)

#define IHeaders_put_item(This,name,newVal)	\
    (This)->lpVtbl -> put_item(This,name,newVal)

#define IHeaders_get_count(This,pVal)	\
    (This)->lpVtbl -> get_count(This,pVal)

#define IHeaders_clear(This)	\
    (This)->lpVtbl -> clear(This)

#define IHeaders_erase(This,name)	\
    (This)->lpVtbl -> erase(This,name)

#define IHeaders_get__NewEnum(This,pVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pVal)

#define IHeaders_add(This,name,pRet)	\
    (This)->lpVtbl -> add(This,name,pRet)

#define IHeaders_exist(This,name,pVal)	\
    (This)->lpVtbl -> exist(This,name,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [defaultcollelem][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IHeaders_get_item_Proxy( 
    IHeaders * This,
    /* [in] */ BSTR name,
    /* [retval][out] */ IMessageHeader **pVal);


void __RPC_STUB IHeaders_get_item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [defaultcollelem][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IHeaders_put_item_Proxy( 
    IHeaders * This,
    /* [in] */ BSTR name,
    /* [in] */ BSTR newVal);


void __RPC_STUB IHeaders_put_item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IHeaders_get_count_Proxy( 
    IHeaders * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IHeaders_get_count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHeaders_clear_Proxy( 
    IHeaders * This);


void __RPC_STUB IHeaders_clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHeaders_erase_Proxy( 
    IHeaders * This,
    /* [in] */ BSTR name);


void __RPC_STUB IHeaders_erase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id][propget] */ HRESULT STDMETHODCALLTYPE IHeaders_get__NewEnum_Proxy( 
    IHeaders * This,
    /* [retval][out] */ IUnknown **pVal);


void __RPC_STUB IHeaders_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHeaders_add_Proxy( 
    IHeaders * This,
    /* [in] */ BSTR name,
    /* [retval][out] */ IMessageHeader **pRet);


void __RPC_STUB IHeaders_add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHeaders_exist_Proxy( 
    IHeaders * This,
    /* [in] */ BSTR name,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IHeaders_exist_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHeaders_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_tmailx_0263 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_tmailx_0263_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tmailx_0263_v0_0_s_ifspec;

#ifndef __IContent_INTERFACE_DEFINED__
#define __IContent_INTERFACE_DEFINED__

/* interface IContent */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IContent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("798F3451-59A0-4F09-9268-C730334C384C")
    IContent : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE parse( 
            /* [in] */ SAFEARRAY * data,
            /* [defaultvalue][in] */ VARIANT_BOOL only_headers = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE save( 
            /* [in] */ BSTR filename) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE load( 
            /* [in] */ BSTR filename,
            /* [defaultvalue][in] */ VARIANT_BOOL only_header = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setBodyText( 
            /* [in] */ BSTR text) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE loadBody( 
            /* [in] */ BSTR filename) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_headers( 
            /* [retval][out] */ IHeaders **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_body( 
            /* [retval][out] */ SAFEARRAY * *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_body( 
            /* [in] */ SAFEARRAY * newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getBodyText( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE saveBody( 
            /* [in] */ BSTR filename) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_multiparts( 
            /* [retval][out] */ IContents **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE createAlternativeBody( 
            /* [in] */ BSTR text,
            /* [in] */ BSTR html,
            /* [optional][in] */ VARIANT attachments) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE createTextBody( 
            /* [in] */ BSTR text,
            /* [optional][in] */ VARIANT attachments) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE createHtmlBody( 
            /* [in] */ BSTR html,
            /* [optional][in] */ VARIANT attachments) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE createRelatedBody( 
            /* [in] */ BSTR html,
            /* [optional][in] */ VARIANT pictures,
            /* [optional][in] */ VARIANT attachments,
            /* [defaultvalue][in] */ VARIANT_BOOL use_cid = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE createAlternativeBodyF( 
            /* [in] */ BSTR textFile,
            /* [in] */ BSTR htmlFile,
            /* [optional][in] */ VARIANT attachments) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE createTextBodyF( 
            /* [in] */ BSTR textFile,
            /* [optional][in] */ VARIANT attachments) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE createHtmlBodyF( 
            /* [in] */ BSTR htmlFile,
            /* [optional][in] */ VARIANT attachments) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE createRelatedBodyF( 
            /* [in] */ BSTR htmlFile,
            /* [optional][in] */ VARIANT pictures,
            /* [optional][in] */ VARIANT attachments,
            /* [defaultvalue][in] */ VARIANT_BOOL use_cid = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE generateId( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_contentType( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_filename( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_extname( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IContentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IContent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IContent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IContent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IContent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IContent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IContent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IContent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *parse )( 
            IContent * This,
            /* [in] */ SAFEARRAY * data,
            /* [defaultvalue][in] */ VARIANT_BOOL only_headers);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *save )( 
            IContent * This,
            /* [in] */ BSTR filename);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *load )( 
            IContent * This,
            /* [in] */ BSTR filename,
            /* [defaultvalue][in] */ VARIANT_BOOL only_header);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setBodyText )( 
            IContent * This,
            /* [in] */ BSTR text);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *loadBody )( 
            IContent * This,
            /* [in] */ BSTR filename);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_headers )( 
            IContent * This,
            /* [retval][out] */ IHeaders **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_body )( 
            IContent * This,
            /* [retval][out] */ SAFEARRAY * *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_body )( 
            IContent * This,
            /* [in] */ SAFEARRAY * newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getBodyText )( 
            IContent * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *saveBody )( 
            IContent * This,
            /* [in] */ BSTR filename);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_multiparts )( 
            IContent * This,
            /* [retval][out] */ IContents **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *createAlternativeBody )( 
            IContent * This,
            /* [in] */ BSTR text,
            /* [in] */ BSTR html,
            /* [optional][in] */ VARIANT attachments);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *createTextBody )( 
            IContent * This,
            /* [in] */ BSTR text,
            /* [optional][in] */ VARIANT attachments);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *createHtmlBody )( 
            IContent * This,
            /* [in] */ BSTR html,
            /* [optional][in] */ VARIANT attachments);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *createRelatedBody )( 
            IContent * This,
            /* [in] */ BSTR html,
            /* [optional][in] */ VARIANT pictures,
            /* [optional][in] */ VARIANT attachments,
            /* [defaultvalue][in] */ VARIANT_BOOL use_cid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *createAlternativeBodyF )( 
            IContent * This,
            /* [in] */ BSTR textFile,
            /* [in] */ BSTR htmlFile,
            /* [optional][in] */ VARIANT attachments);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *createTextBodyF )( 
            IContent * This,
            /* [in] */ BSTR textFile,
            /* [optional][in] */ VARIANT attachments);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *createHtmlBodyF )( 
            IContent * This,
            /* [in] */ BSTR htmlFile,
            /* [optional][in] */ VARIANT attachments);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *createRelatedBodyF )( 
            IContent * This,
            /* [in] */ BSTR htmlFile,
            /* [optional][in] */ VARIANT pictures,
            /* [optional][in] */ VARIANT attachments,
            /* [defaultvalue][in] */ VARIANT_BOOL use_cid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *generateId )( 
            IContent * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_contentType )( 
            IContent * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_filename )( 
            IContent * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_extname )( 
            IContent * This,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } IContentVtbl;

    interface IContent
    {
        CONST_VTBL struct IContentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IContent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IContent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IContent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IContent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IContent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IContent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IContent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IContent_parse(This,data,only_headers)	\
    (This)->lpVtbl -> parse(This,data,only_headers)

#define IContent_save(This,filename)	\
    (This)->lpVtbl -> save(This,filename)

#define IContent_load(This,filename,only_header)	\
    (This)->lpVtbl -> load(This,filename,only_header)

#define IContent_setBodyText(This,text)	\
    (This)->lpVtbl -> setBodyText(This,text)

#define IContent_loadBody(This,filename)	\
    (This)->lpVtbl -> loadBody(This,filename)

#define IContent_get_headers(This,pVal)	\
    (This)->lpVtbl -> get_headers(This,pVal)

#define IContent_get_body(This,pVal)	\
    (This)->lpVtbl -> get_body(This,pVal)

#define IContent_put_body(This,newVal)	\
    (This)->lpVtbl -> put_body(This,newVal)

#define IContent_getBodyText(This,pVal)	\
    (This)->lpVtbl -> getBodyText(This,pVal)

#define IContent_saveBody(This,filename)	\
    (This)->lpVtbl -> saveBody(This,filename)

#define IContent_get_multiparts(This,pVal)	\
    (This)->lpVtbl -> get_multiparts(This,pVal)

#define IContent_createAlternativeBody(This,text,html,attachments)	\
    (This)->lpVtbl -> createAlternativeBody(This,text,html,attachments)

#define IContent_createTextBody(This,text,attachments)	\
    (This)->lpVtbl -> createTextBody(This,text,attachments)

#define IContent_createHtmlBody(This,html,attachments)	\
    (This)->lpVtbl -> createHtmlBody(This,html,attachments)

#define IContent_createRelatedBody(This,html,pictures,attachments,use_cid)	\
    (This)->lpVtbl -> createRelatedBody(This,html,pictures,attachments,use_cid)

#define IContent_createAlternativeBodyF(This,textFile,htmlFile,attachments)	\
    (This)->lpVtbl -> createAlternativeBodyF(This,textFile,htmlFile,attachments)

#define IContent_createTextBodyF(This,textFile,attachments)	\
    (This)->lpVtbl -> createTextBodyF(This,textFile,attachments)

#define IContent_createHtmlBodyF(This,htmlFile,attachments)	\
    (This)->lpVtbl -> createHtmlBodyF(This,htmlFile,attachments)

#define IContent_createRelatedBodyF(This,htmlFile,pictures,attachments,use_cid)	\
    (This)->lpVtbl -> createRelatedBodyF(This,htmlFile,pictures,attachments,use_cid)

#define IContent_generateId(This)	\
    (This)->lpVtbl -> generateId(This)

#define IContent_get_contentType(This,pVal)	\
    (This)->lpVtbl -> get_contentType(This,pVal)

#define IContent_get_filename(This,pVal)	\
    (This)->lpVtbl -> get_filename(This,pVal)

#define IContent_get_extname(This,pVal)	\
    (This)->lpVtbl -> get_extname(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IContent_parse_Proxy( 
    IContent * This,
    /* [in] */ SAFEARRAY * data,
    /* [defaultvalue][in] */ VARIANT_BOOL only_headers);


void __RPC_STUB IContent_parse_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IContent_save_Proxy( 
    IContent * This,
    /* [in] */ BSTR filename);


void __RPC_STUB IContent_save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IContent_load_Proxy( 
    IContent * This,
    /* [in] */ BSTR filename,
    /* [defaultvalue][in] */ VARIANT_BOOL only_header);


void __RPC_STUB IContent_load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IContent_setBodyText_Proxy( 
    IContent * This,
    /* [in] */ BSTR text);


void __RPC_STUB IContent_setBodyText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IContent_loadBody_Proxy( 
    IContent * This,
    /* [in] */ BSTR filename);


void __RPC_STUB IContent_loadBody_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContent_get_headers_Proxy( 
    IContent * This,
    /* [retval][out] */ IHeaders **pVal);


void __RPC_STUB IContent_get_headers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContent_get_body_Proxy( 
    IContent * This,
    /* [retval][out] */ SAFEARRAY * *pVal);


void __RPC_STUB IContent_get_body_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IContent_put_body_Proxy( 
    IContent * This,
    /* [in] */ SAFEARRAY * newVal);


void __RPC_STUB IContent_put_body_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IContent_getBodyText_Proxy( 
    IContent * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContent_getBodyText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IContent_saveBody_Proxy( 
    IContent * This,
    /* [in] */ BSTR filename);


void __RPC_STUB IContent_saveBody_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContent_get_multiparts_Proxy( 
    IContent * This,
    /* [retval][out] */ IContents **pVal);


void __RPC_STUB IContent_get_multiparts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IContent_createAlternativeBody_Proxy( 
    IContent * This,
    /* [in] */ BSTR text,
    /* [in] */ BSTR html,
    /* [optional][in] */ VARIANT attachments);


void __RPC_STUB IContent_createAlternativeBody_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IContent_createTextBody_Proxy( 
    IContent * This,
    /* [in] */ BSTR text,
    /* [optional][in] */ VARIANT attachments);


void __RPC_STUB IContent_createTextBody_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IContent_createHtmlBody_Proxy( 
    IContent * This,
    /* [in] */ BSTR html,
    /* [optional][in] */ VARIANT attachments);


void __RPC_STUB IContent_createHtmlBody_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IContent_createRelatedBody_Proxy( 
    IContent * This,
    /* [in] */ BSTR html,
    /* [optional][in] */ VARIANT pictures,
    /* [optional][in] */ VARIANT attachments,
    /* [defaultvalue][in] */ VARIANT_BOOL use_cid);


void __RPC_STUB IContent_createRelatedBody_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IContent_createAlternativeBodyF_Proxy( 
    IContent * This,
    /* [in] */ BSTR textFile,
    /* [in] */ BSTR htmlFile,
    /* [optional][in] */ VARIANT attachments);


void __RPC_STUB IContent_createAlternativeBodyF_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IContent_createTextBodyF_Proxy( 
    IContent * This,
    /* [in] */ BSTR textFile,
    /* [optional][in] */ VARIANT attachments);


void __RPC_STUB IContent_createTextBodyF_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IContent_createHtmlBodyF_Proxy( 
    IContent * This,
    /* [in] */ BSTR htmlFile,
    /* [optional][in] */ VARIANT attachments);


void __RPC_STUB IContent_createHtmlBodyF_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IContent_createRelatedBodyF_Proxy( 
    IContent * This,
    /* [in] */ BSTR htmlFile,
    /* [optional][in] */ VARIANT pictures,
    /* [optional][in] */ VARIANT attachments,
    /* [defaultvalue][in] */ VARIANT_BOOL use_cid);


void __RPC_STUB IContent_createRelatedBodyF_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IContent_generateId_Proxy( 
    IContent * This);


void __RPC_STUB IContent_generateId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContent_get_contentType_Proxy( 
    IContent * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContent_get_contentType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContent_get_filename_Proxy( 
    IContent * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContent_get_filename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContent_get_extname_Proxy( 
    IContent * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContent_get_extname_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IContent_INTERFACE_DEFINED__ */


#ifndef __IContents_INTERFACE_DEFINED__
#define __IContents_INTERFACE_DEFINED__

/* interface IContents */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IContents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3716A914-91E2-4034-84E6-2DEB114FC554")
    IContents : public IDispatch
    {
    public:
        virtual /* [defaultcollelem][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_item( 
            /* [in] */ LONG index,
            /* [retval][out] */ IContent **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE erase( 
            /* [in] */ LONG index) = 0;
        
        virtual /* [hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE add( 
            /* [in] */ IContent *content) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IContentsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IContents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IContents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IContents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IContents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IContents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IContents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IContents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [defaultcollelem][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_item )( 
            IContents * This,
            /* [in] */ LONG index,
            /* [retval][out] */ IContent **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_count )( 
            IContents * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *clear )( 
            IContents * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *erase )( 
            IContents * This,
            /* [in] */ LONG index);
        
        /* [hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IContents * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *add )( 
            IContents * This,
            /* [in] */ IContent *content);
        
        END_INTERFACE
    } IContentsVtbl;

    interface IContents
    {
        CONST_VTBL struct IContentsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IContents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IContents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IContents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IContents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IContents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IContents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IContents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IContents_get_item(This,index,pVal)	\
    (This)->lpVtbl -> get_item(This,index,pVal)

#define IContents_get_count(This,pVal)	\
    (This)->lpVtbl -> get_count(This,pVal)

#define IContents_clear(This)	\
    (This)->lpVtbl -> clear(This)

#define IContents_erase(This,index)	\
    (This)->lpVtbl -> erase(This,index)

#define IContents_get__NewEnum(This,pVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pVal)

#define IContents_add(This,content)	\
    (This)->lpVtbl -> add(This,content)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [defaultcollelem][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContents_get_item_Proxy( 
    IContents * This,
    /* [in] */ LONG index,
    /* [retval][out] */ IContent **pVal);


void __RPC_STUB IContents_get_item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContents_get_count_Proxy( 
    IContents * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IContents_get_count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IContents_clear_Proxy( 
    IContents * This);


void __RPC_STUB IContents_clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IContents_erase_Proxy( 
    IContents * This,
    /* [in] */ LONG index);


void __RPC_STUB IContents_erase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id][propget] */ HRESULT STDMETHODCALLTYPE IContents_get__NewEnum_Proxy( 
    IContents * This,
    /* [retval][out] */ IUnknown **pVal);


void __RPC_STUB IContents_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IContents_add_Proxy( 
    IContents * This,
    /* [in] */ IContent *content);


void __RPC_STUB IContents_add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IContents_INTERFACE_DEFINED__ */


#ifndef __IMail_INTERFACE_DEFINED__
#define __IMail_INTERFACE_DEFINED__

/* interface IMail */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMail;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C19ED2A0-7414-474C-BB5E-073A9D0F2FEA")
    IMail : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_from( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_from( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_to( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_to( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_cc( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_cc( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_bcc( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_bcc( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_subject( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_subject( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_content( 
            /* [retval][out] */ IContent **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_date( 
            /* [retval][out] */ DATE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_date( 
            /* [in] */ DATE newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMailVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMail * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMail * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMail * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMail * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMail * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMail * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMail * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_from )( 
            IMail * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_from )( 
            IMail * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_to )( 
            IMail * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_to )( 
            IMail * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_cc )( 
            IMail * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_cc )( 
            IMail * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_bcc )( 
            IMail * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_bcc )( 
            IMail * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_subject )( 
            IMail * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_subject )( 
            IMail * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_content )( 
            IMail * This,
            /* [retval][out] */ IContent **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_date )( 
            IMail * This,
            /* [retval][out] */ DATE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_date )( 
            IMail * This,
            /* [in] */ DATE newVal);
        
        END_INTERFACE
    } IMailVtbl;

    interface IMail
    {
        CONST_VTBL struct IMailVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMail_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMail_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMail_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMail_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMail_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMail_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMail_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IMail_get_from(This,pVal)	\
    (This)->lpVtbl -> get_from(This,pVal)

#define IMail_put_from(This,newVal)	\
    (This)->lpVtbl -> put_from(This,newVal)

#define IMail_get_to(This,pVal)	\
    (This)->lpVtbl -> get_to(This,pVal)

#define IMail_put_to(This,newVal)	\
    (This)->lpVtbl -> put_to(This,newVal)

#define IMail_get_cc(This,pVal)	\
    (This)->lpVtbl -> get_cc(This,pVal)

#define IMail_put_cc(This,newVal)	\
    (This)->lpVtbl -> put_cc(This,newVal)

#define IMail_get_bcc(This,pVal)	\
    (This)->lpVtbl -> get_bcc(This,pVal)

#define IMail_put_bcc(This,newVal)	\
    (This)->lpVtbl -> put_bcc(This,newVal)

#define IMail_get_subject(This,pVal)	\
    (This)->lpVtbl -> get_subject(This,pVal)

#define IMail_put_subject(This,newVal)	\
    (This)->lpVtbl -> put_subject(This,newVal)

#define IMail_get_content(This,pVal)	\
    (This)->lpVtbl -> get_content(This,pVal)

#define IMail_get_date(This,pVal)	\
    (This)->lpVtbl -> get_date(This,pVal)

#define IMail_put_date(This,newVal)	\
    (This)->lpVtbl -> put_date(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMail_get_from_Proxy( 
    IMail * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IMail_get_from_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMail_put_from_Proxy( 
    IMail * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IMail_put_from_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMail_get_to_Proxy( 
    IMail * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IMail_get_to_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMail_put_to_Proxy( 
    IMail * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IMail_put_to_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMail_get_cc_Proxy( 
    IMail * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IMail_get_cc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMail_put_cc_Proxy( 
    IMail * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IMail_put_cc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMail_get_bcc_Proxy( 
    IMail * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IMail_get_bcc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMail_put_bcc_Proxy( 
    IMail * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IMail_put_bcc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMail_get_subject_Proxy( 
    IMail * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IMail_get_subject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMail_put_subject_Proxy( 
    IMail * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IMail_put_subject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMail_get_content_Proxy( 
    IMail * This,
    /* [retval][out] */ IContent **pVal);


void __RPC_STUB IMail_get_content_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMail_get_date_Proxy( 
    IMail * This,
    /* [retval][out] */ DATE *pVal);


void __RPC_STUB IMail_get_date_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMail_put_date_Proxy( 
    IMail * This,
    /* [in] */ DATE newVal);


void __RPC_STUB IMail_put_date_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMail_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_tmailx_0266 */
/* [local] */ 

/* [v1_enum] */ 
enum CommandTypeConstant
    {	smtpCmdInit	= 0x100,
	smtpCmdHelo	= smtpCmdInit + 1,
	smtpCmdEhlo	= smtpCmdHelo + 1,
	smtpCmdRset	= smtpCmdEhlo + 1,
	smtpCmdAuthLogin	= smtpCmdRset + 1,
	smtpCmdAuthLoginUsername	= smtpCmdAuthLogin + 1,
	smtpCmdAuthLoginPassword	= smtpCmdAuthLoginUsername + 1,
	smtpCmdAuthPlain	= smtpCmdAuthLoginPassword + 1,
	smtpCmdAuthCramMd5	= smtpCmdAuthPlain + 1,
	smtpCmdAuthCramMd5Data	= smtpCmdAuthCramMd5 + 1,
	smtpCmdVrfy	= smtpCmdAuthCramMd5Data + 1,
	smtpCmdExpn	= smtpCmdVrfy + 1,
	smtpCmdStarttls	= smtpCmdExpn + 1,
	smtpCmdMailFrom	= smtpCmdStarttls + 1,
	smtpCmdRcptTo	= smtpCmdMailFrom + 1,
	smtpCmdData	= smtpCmdRcptTo + 1,
	smtpCmdDataContent	= smtpCmdData + 1,
	smtpCmdNoop	= smtpCmdDataContent + 1,
	smtpCmdQuit	= smtpCmdNoop + 1,
	pop3CmdInit	= 0x200,
	pop3CmdStat	= pop3CmdInit + 1,
	pop3CmdList	= pop3CmdStat + 1,
	pop3CmdRetr	= pop3CmdList + 1,
	pop3CmdDele	= pop3CmdRetr + 1,
	pop3CmdRset	= pop3CmdDele + 1,
	pop3CmdCapa	= pop3CmdRset + 1,
	pop3CmdApop	= pop3CmdCapa + 1,
	pop3CmdTop	= pop3CmdApop + 1,
	pop3CmdUidl	= pop3CmdTop + 1,
	pop3CmdAuthPlain	= pop3CmdUidl + 1,
	pop3CmdAuthLogin	= pop3CmdAuthPlain + 1,
	pop3CmdAuthLoginUsername	= pop3CmdAuthLogin + 1,
	pop3CmdAuthLoginPassword	= pop3CmdAuthLoginUsername + 1,
	pop3CmdAuthCramMd5	= pop3CmdAuthLoginPassword + 1,
	pop3CmdAuthCramMd5Data	= pop3CmdAuthCramMd5 + 1,
	pop3CmdUser	= pop3CmdAuthCramMd5Data + 1,
	pop3CmdPass	= pop3CmdUser + 1,
	pop3CmdStls	= pop3CmdPass + 1,
	pop3CmdNoop	= pop3CmdStls + 1,
	pop3CmdQuit	= pop3CmdNoop + 1
    } ;
/* [v1_enum] */ 
enum MailPortConstant
    {	smtpPortNormal	= 25,
	smtpPortSSL	= 465,
	pop3PortNormal	= 110,
	pop3PortSSL	= 995
    } ;
/* [v1_enum] */ 
enum SmtpAuthTypeConstant
    {	smtpAuthLogin	= 0,
	smtpAuthPlain	= smtpAuthLogin + 1,
	smtpAuthCramMd5	= smtpAuthPlain + 1
    } ;
/* [v1_enum] */ 
enum Pop3AuthTypeConstant
    {	pop3AuthLogin	= 0,
	pop3AuthPlain	= pop3AuthLogin + 1,
	pop3AuthCramMd5	= pop3AuthPlain + 1,
	pop3AuthApop	= pop3AuthCramMd5 + 1,
	pop3AuthUser	= pop3AuthApop + 1
    } ;


extern RPC_IF_HANDLE __MIDL_itf_tmailx_0266_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tmailx_0266_v0_0_s_ifspec;

#ifndef __IOptions_INTERFACE_DEFINED__
#define __IOptions_INTERFACE_DEFINED__

/* interface IOptions */
/* [hidden][unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IOptions;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3278D320-60C2-43B4-AB95-FEAA8A17D670")
    IOptions : public IDispatch
    {
    public:
        virtual /* [defaultcollelem][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_item( 
            /* [in] */ LONG index,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOptionsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOptions * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOptions * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOptions * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOptions * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOptions * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOptions * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOptions * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [defaultcollelem][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_item )( 
            IOptions * This,
            /* [in] */ LONG index,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_count )( 
            IOptions * This,
            /* [retval][out] */ LONG *pVal);
        
        END_INTERFACE
    } IOptionsVtbl;

    interface IOptions
    {
        CONST_VTBL struct IOptionsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOptions_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOptions_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOptions_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOptions_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOptions_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOptions_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOptions_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOptions_get_item(This,index,pVal)	\
    (This)->lpVtbl -> get_item(This,index,pVal)

#define IOptions_get_count(This,pVal)	\
    (This)->lpVtbl -> get_count(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [defaultcollelem][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOptions_get_item_Proxy( 
    IOptions * This,
    /* [in] */ LONG index,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOptions_get_item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOptions_get_count_Proxy( 
    IOptions * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOptions_get_count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOptions_INTERFACE_DEFINED__ */


#ifndef __ISmtp_INTERFACE_DEFINED__
#define __ISmtp_INTERFACE_DEFINED__

/* interface ISmtp */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISmtp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("44A1A6DF-EC33-430C-99F3-5A6857E2048E")
    ISmtp : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE connect( 
            /* [in] */ BSTR host,
            /* [defaultvalue][in] */ LONG port,
            /* [defaultvalue][in] */ VARIANT_BOOL use_ssl,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE quit( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE auth( 
            /* [in] */ BSTR username,
            /* [in] */ BSTR password,
            /* [defaultvalue][in] */ enum SmtpAuthTypeConstant authType,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_authTypes( 
            /* [retval][out] */ IOptions **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE hello( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE starttls( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE reset( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE noop( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE expand( 
            /* [in] */ BSTR mailingList,
            /* [out] */ VARIANT *mails,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE verify( 
            /* [in] */ BSTR name,
            /* [out] */ VARIANT *mail,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_enable8Bit( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_enableStartTls( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_enablePipling( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_maxMailSize( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE mailFrom( 
            /* [in] */ BSTR mailAddress,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE rcptTo( 
            /* [in] */ BSTR mailAddress,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE addressesByMail( 
            /* [in] */ IMail *mail,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE sendMail( 
            /* [in] */ IMail *mail,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISmtpVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISmtp * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISmtp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISmtp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISmtp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISmtp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISmtp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISmtp * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *connect )( 
            ISmtp * This,
            /* [in] */ BSTR host,
            /* [defaultvalue][in] */ LONG port,
            /* [defaultvalue][in] */ VARIANT_BOOL use_ssl,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *quit )( 
            ISmtp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *auth )( 
            ISmtp * This,
            /* [in] */ BSTR username,
            /* [in] */ BSTR password,
            /* [defaultvalue][in] */ enum SmtpAuthTypeConstant authType,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_authTypes )( 
            ISmtp * This,
            /* [retval][out] */ IOptions **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *hello )( 
            ISmtp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *starttls )( 
            ISmtp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *reset )( 
            ISmtp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *noop )( 
            ISmtp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *expand )( 
            ISmtp * This,
            /* [in] */ BSTR mailingList,
            /* [out] */ VARIANT *mails,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *verify )( 
            ISmtp * This,
            /* [in] */ BSTR name,
            /* [out] */ VARIANT *mail,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_enable8Bit )( 
            ISmtp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_enableStartTls )( 
            ISmtp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_enablePipling )( 
            ISmtp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_maxMailSize )( 
            ISmtp * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *mailFrom )( 
            ISmtp * This,
            /* [in] */ BSTR mailAddress,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *rcptTo )( 
            ISmtp * This,
            /* [in] */ BSTR mailAddress,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *addressesByMail )( 
            ISmtp * This,
            /* [in] */ IMail *mail,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *sendMail )( 
            ISmtp * This,
            /* [in] */ IMail *mail,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        END_INTERFACE
    } ISmtpVtbl;

    interface ISmtp
    {
        CONST_VTBL struct ISmtpVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISmtp_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISmtp_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISmtp_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISmtp_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISmtp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISmtp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISmtp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISmtp_connect(This,host,port,use_ssl,pVal)	\
    (This)->lpVtbl -> connect(This,host,port,use_ssl,pVal)

#define ISmtp_quit(This,pVal)	\
    (This)->lpVtbl -> quit(This,pVal)

#define ISmtp_auth(This,username,password,authType,pVal)	\
    (This)->lpVtbl -> auth(This,username,password,authType,pVal)

#define ISmtp_get_authTypes(This,pVal)	\
    (This)->lpVtbl -> get_authTypes(This,pVal)

#define ISmtp_hello(This,pVal)	\
    (This)->lpVtbl -> hello(This,pVal)

#define ISmtp_starttls(This,pVal)	\
    (This)->lpVtbl -> starttls(This,pVal)

#define ISmtp_reset(This,pVal)	\
    (This)->lpVtbl -> reset(This,pVal)

#define ISmtp_noop(This,pVal)	\
    (This)->lpVtbl -> noop(This,pVal)

#define ISmtp_expand(This,mailingList,mails,pVal)	\
    (This)->lpVtbl -> expand(This,mailingList,mails,pVal)

#define ISmtp_verify(This,name,mail,pVal)	\
    (This)->lpVtbl -> verify(This,name,mail,pVal)

#define ISmtp_get_enable8Bit(This,pVal)	\
    (This)->lpVtbl -> get_enable8Bit(This,pVal)

#define ISmtp_get_enableStartTls(This,pVal)	\
    (This)->lpVtbl -> get_enableStartTls(This,pVal)

#define ISmtp_get_enablePipling(This,pVal)	\
    (This)->lpVtbl -> get_enablePipling(This,pVal)

#define ISmtp_get_maxMailSize(This,pVal)	\
    (This)->lpVtbl -> get_maxMailSize(This,pVal)

#define ISmtp_mailFrom(This,mailAddress,pVal)	\
    (This)->lpVtbl -> mailFrom(This,mailAddress,pVal)

#define ISmtp_rcptTo(This,mailAddress,pVal)	\
    (This)->lpVtbl -> rcptTo(This,mailAddress,pVal)

#define ISmtp_addressesByMail(This,mail,pVal)	\
    (This)->lpVtbl -> addressesByMail(This,mail,pVal)

#define ISmtp_sendMail(This,mail,pVal)	\
    (This)->lpVtbl -> sendMail(This,mail,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISmtp_connect_Proxy( 
    ISmtp * This,
    /* [in] */ BSTR host,
    /* [defaultvalue][in] */ LONG port,
    /* [defaultvalue][in] */ VARIANT_BOOL use_ssl,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB ISmtp_connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISmtp_quit_Proxy( 
    ISmtp * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB ISmtp_quit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISmtp_auth_Proxy( 
    ISmtp * This,
    /* [in] */ BSTR username,
    /* [in] */ BSTR password,
    /* [defaultvalue][in] */ enum SmtpAuthTypeConstant authType,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB ISmtp_auth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISmtp_get_authTypes_Proxy( 
    ISmtp * This,
    /* [retval][out] */ IOptions **pVal);


void __RPC_STUB ISmtp_get_authTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISmtp_hello_Proxy( 
    ISmtp * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB ISmtp_hello_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISmtp_starttls_Proxy( 
    ISmtp * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB ISmtp_starttls_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISmtp_reset_Proxy( 
    ISmtp * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB ISmtp_reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISmtp_noop_Proxy( 
    ISmtp * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB ISmtp_noop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISmtp_expand_Proxy( 
    ISmtp * This,
    /* [in] */ BSTR mailingList,
    /* [out] */ VARIANT *mails,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB ISmtp_expand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISmtp_verify_Proxy( 
    ISmtp * This,
    /* [in] */ BSTR name,
    /* [out] */ VARIANT *mail,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB ISmtp_verify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISmtp_get_enable8Bit_Proxy( 
    ISmtp * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB ISmtp_get_enable8Bit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISmtp_get_enableStartTls_Proxy( 
    ISmtp * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB ISmtp_get_enableStartTls_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISmtp_get_enablePipling_Proxy( 
    ISmtp * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB ISmtp_get_enablePipling_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISmtp_get_maxMailSize_Proxy( 
    ISmtp * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB ISmtp_get_maxMailSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISmtp_mailFrom_Proxy( 
    ISmtp * This,
    /* [in] */ BSTR mailAddress,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB ISmtp_mailFrom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISmtp_rcptTo_Proxy( 
    ISmtp * This,
    /* [in] */ BSTR mailAddress,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB ISmtp_rcptTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISmtp_addressesByMail_Proxy( 
    ISmtp * This,
    /* [in] */ IMail *mail,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB ISmtp_addressesByMail_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISmtp_sendMail_Proxy( 
    ISmtp * This,
    /* [in] */ IMail *mail,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB ISmtp_sendMail_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISmtp_INTERFACE_DEFINED__ */


#ifndef __IPop3_INTERFACE_DEFINED__
#define __IPop3_INTERFACE_DEFINED__

/* interface IPop3 */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IPop3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7DA5678A-76A1-4278-B289-D4BD95F3860B")
    IPop3 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE connect( 
            /* [in] */ BSTR host,
            /* [defaultvalue][in] */ LONG port,
            /* [defaultvalue][in] */ VARIANT_BOOL use_ssl,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE quit( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE auth( 
            /* [in] */ BSTR username,
            /* [in] */ BSTR password,
            /* [defaultvalue][in] */ enum Pop3AuthTypeConstant authType,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE capability( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE list( 
            /* [out] */ VARIANT *mailIndex,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE uidl( 
            /* [out] */ VARIANT *uidIndex,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE stat( 
            /* [out] */ VARIANT *mailCount,
            /* [out] */ VARIANT *totalSize,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE starttls( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE returnMailHeader( 
            /* [in] */ LONG id,
            /* [retval][out] */ IMail **pMail) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE returnMail( 
            /* [in] */ LONG id,
            /* [retval][out] */ IMail **pMail) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE deleteMail( 
            /* [in] */ LONG id,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE noop( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE reset( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_authTypes( 
            /* [retval][out] */ IOptions **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_enableStartTls( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPop3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPop3 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPop3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPop3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPop3 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPop3 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPop3 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPop3 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *connect )( 
            IPop3 * This,
            /* [in] */ BSTR host,
            /* [defaultvalue][in] */ LONG port,
            /* [defaultvalue][in] */ VARIANT_BOOL use_ssl,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *quit )( 
            IPop3 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *auth )( 
            IPop3 * This,
            /* [in] */ BSTR username,
            /* [in] */ BSTR password,
            /* [defaultvalue][in] */ enum Pop3AuthTypeConstant authType,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *capability )( 
            IPop3 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *list )( 
            IPop3 * This,
            /* [out] */ VARIANT *mailIndex,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *uidl )( 
            IPop3 * This,
            /* [out] */ VARIANT *uidIndex,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *stat )( 
            IPop3 * This,
            /* [out] */ VARIANT *mailCount,
            /* [out] */ VARIANT *totalSize,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *starttls )( 
            IPop3 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *returnMailHeader )( 
            IPop3 * This,
            /* [in] */ LONG id,
            /* [retval][out] */ IMail **pMail);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *returnMail )( 
            IPop3 * This,
            /* [in] */ LONG id,
            /* [retval][out] */ IMail **pMail);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *deleteMail )( 
            IPop3 * This,
            /* [in] */ LONG id,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *noop )( 
            IPop3 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *reset )( 
            IPop3 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_authTypes )( 
            IPop3 * This,
            /* [retval][out] */ IOptions **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_enableStartTls )( 
            IPop3 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        END_INTERFACE
    } IPop3Vtbl;

    interface IPop3
    {
        CONST_VTBL struct IPop3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPop3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPop3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPop3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPop3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPop3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPop3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPop3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPop3_connect(This,host,port,use_ssl,pVal)	\
    (This)->lpVtbl -> connect(This,host,port,use_ssl,pVal)

#define IPop3_quit(This,pVal)	\
    (This)->lpVtbl -> quit(This,pVal)

#define IPop3_auth(This,username,password,authType,pVal)	\
    (This)->lpVtbl -> auth(This,username,password,authType,pVal)

#define IPop3_capability(This,pVal)	\
    (This)->lpVtbl -> capability(This,pVal)

#define IPop3_list(This,mailIndex,pVal)	\
    (This)->lpVtbl -> list(This,mailIndex,pVal)

#define IPop3_uidl(This,uidIndex,pVal)	\
    (This)->lpVtbl -> uidl(This,uidIndex,pVal)

#define IPop3_stat(This,mailCount,totalSize,pVal)	\
    (This)->lpVtbl -> stat(This,mailCount,totalSize,pVal)

#define IPop3_starttls(This,pVal)	\
    (This)->lpVtbl -> starttls(This,pVal)

#define IPop3_returnMailHeader(This,id,pMail)	\
    (This)->lpVtbl -> returnMailHeader(This,id,pMail)

#define IPop3_returnMail(This,id,pMail)	\
    (This)->lpVtbl -> returnMail(This,id,pMail)

#define IPop3_deleteMail(This,id,pVal)	\
    (This)->lpVtbl -> deleteMail(This,id,pVal)

#define IPop3_noop(This,pVal)	\
    (This)->lpVtbl -> noop(This,pVal)

#define IPop3_reset(This,pVal)	\
    (This)->lpVtbl -> reset(This,pVal)

#define IPop3_get_authTypes(This,pVal)	\
    (This)->lpVtbl -> get_authTypes(This,pVal)

#define IPop3_get_enableStartTls(This,pVal)	\
    (This)->lpVtbl -> get_enableStartTls(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPop3_connect_Proxy( 
    IPop3 * This,
    /* [in] */ BSTR host,
    /* [defaultvalue][in] */ LONG port,
    /* [defaultvalue][in] */ VARIANT_BOOL use_ssl,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IPop3_connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPop3_quit_Proxy( 
    IPop3 * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IPop3_quit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPop3_auth_Proxy( 
    IPop3 * This,
    /* [in] */ BSTR username,
    /* [in] */ BSTR password,
    /* [defaultvalue][in] */ enum Pop3AuthTypeConstant authType,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IPop3_auth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPop3_capability_Proxy( 
    IPop3 * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IPop3_capability_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPop3_list_Proxy( 
    IPop3 * This,
    /* [out] */ VARIANT *mailIndex,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IPop3_list_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPop3_uidl_Proxy( 
    IPop3 * This,
    /* [out] */ VARIANT *uidIndex,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IPop3_uidl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPop3_stat_Proxy( 
    IPop3 * This,
    /* [out] */ VARIANT *mailCount,
    /* [out] */ VARIANT *totalSize,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IPop3_stat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPop3_starttls_Proxy( 
    IPop3 * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IPop3_starttls_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPop3_returnMailHeader_Proxy( 
    IPop3 * This,
    /* [in] */ LONG id,
    /* [retval][out] */ IMail **pMail);


void __RPC_STUB IPop3_returnMailHeader_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPop3_returnMail_Proxy( 
    IPop3 * This,
    /* [in] */ LONG id,
    /* [retval][out] */ IMail **pMail);


void __RPC_STUB IPop3_returnMail_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPop3_deleteMail_Proxy( 
    IPop3 * This,
    /* [in] */ LONG id,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IPop3_deleteMail_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPop3_noop_Proxy( 
    IPop3 * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IPop3_noop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPop3_reset_Proxy( 
    IPop3 * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IPop3_reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPop3_get_authTypes_Proxy( 
    IPop3 * This,
    /* [retval][out] */ IOptions **pVal);


void __RPC_STUB IPop3_get_authTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPop3_get_enableStartTls_Proxy( 
    IPop3 * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IPop3_get_enableStartTls_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPop3_INTERFACE_DEFINED__ */



#ifndef __TMail_LIBRARY_DEFINED__
#define __TMail_LIBRARY_DEFINED__

/* library TMail */
/* [helpstring][version][uuid] */ 

typedef /* [uuid][public] */  DECLSPEC_UUID("0B2436DD-67FA-4282-A544-1CA49C5B3BF8") enum CommandTypeConstant CommandTypeConstant;

typedef /* [uuid][public] */  DECLSPEC_UUID("799AC7C5-3B3B-41BE-82F3-0103494509FE") enum SmtpAuthTypeConstant SmtpAuthTypeConstant;

typedef /* [uuid][public] */  DECLSPEC_UUID("592366C5-6A69-4E5E-A567-2C5757E3C3D3") enum Pop3AuthTypeConstant Pop3AuthTypeConstant;

typedef /* [uuid][public] */  DECLSPEC_UUID("9C3DE86D-D898-4EEB-AFC6-BCE74249BE56") enum MailPortConstant MailPortConstant;


EXTERN_C const IID LIBID_TMail;

EXTERN_C const CLSID CLSID_Content;

#ifdef __cplusplus

class DECLSPEC_UUID("2757F0DB-AC05-4096-B9D4-DB7D276AD6E1")
Content;
#endif

EXTERN_C const CLSID CLSID_MessageHeader;

#ifdef __cplusplus

class DECLSPEC_UUID("B7AF3F6D-C7B7-4314-B584-22B638B41C85")
MessageHeader;
#endif

EXTERN_C const CLSID CLSID_Headers;

#ifdef __cplusplus

class DECLSPEC_UUID("7559924E-8109-4D49-862C-D2013C37CA21")
Headers;
#endif

EXTERN_C const CLSID CLSID_Contents;

#ifdef __cplusplus

class DECLSPEC_UUID("19D91141-36EC-4DAC-B317-B91880C6DB00")
Contents;
#endif

EXTERN_C const CLSID CLSID_Mail;

#ifdef __cplusplus

class DECLSPEC_UUID("09D7A000-1E25-4F02-A9C2-46F139C91AC6")
Mail;
#endif

#ifndef ___IClientEvents_DISPINTERFACE_DEFINED__
#define ___IClientEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IClientEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IClientEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("0E41DE9B-7DDB-4C8B-B57D-C90CCD16D978")
    _IClientEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IClientEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IClientEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IClientEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IClientEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IClientEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IClientEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IClientEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IClientEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IClientEventsVtbl;

    interface _IClientEvents
    {
        CONST_VTBL struct _IClientEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IClientEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IClientEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IClientEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IClientEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IClientEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IClientEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IClientEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IClientEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Options;

#ifdef __cplusplus

class DECLSPEC_UUID("819F3AA3-3045-47F3-9A22-69806EE4DC62")
Options;
#endif

EXTERN_C const CLSID CLSID_Smtp;

#ifdef __cplusplus

class DECLSPEC_UUID("EB4CB7F1-7770-44D4-9167-EFDB48FFE1C5")
Smtp;
#endif

EXTERN_C const CLSID CLSID_Pop3;

#ifdef __cplusplus

class DECLSPEC_UUID("A967542B-6A74-4F6C-8E72-FC9155F4D77A")
Pop3;
#endif
#endif /* __TMail_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


