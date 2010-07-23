

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Fri Jul 23 22:17:18 2010
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

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */
#pragma warning( disable: 4211 )  /* redefine extent to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 440
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "tmailx.h"

#define TYPE_FORMAT_STRING_SIZE   1269                              
#define PROC_FORMAT_STRING_SIZE   2341                              
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   3            

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMessageHeader_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMessageHeader_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHeaders_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHeaders_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IContent_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IContent_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IContents_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IContents_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMail_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMail_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOptions_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOptions_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISmtp_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ISmtp_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IPop3_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IPop3_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub because it uses these features:
#error   -Oif or -Oicf, [wire_marshal] or [user_marshal] attribute, float, double or hyper in -Oif or -Oicf.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure get_from */


	/* Procedure get_name */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 16 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 18 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 20 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */


	/* Return value */

/* 22 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 24 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 26 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_text */

/* 28 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 30 */	NdrFcLong( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0x8 ),	/* 8 */
/* 36 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 38 */	NdrFcShort( 0x0 ),	/* 0 */
/* 40 */	NdrFcShort( 0x8 ),	/* 8 */
/* 42 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 44 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 46 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 48 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 50 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 52 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 54 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_text */

/* 56 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 58 */	NdrFcLong( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x9 ),	/* 9 */
/* 64 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 66 */	NdrFcShort( 0x0 ),	/* 0 */
/* 68 */	NdrFcShort( 0x8 ),	/* 8 */
/* 70 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 72 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 74 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 76 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Return value */

/* 78 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 80 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 82 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_item */

/* 84 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 86 */	NdrFcLong( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x7 ),	/* 7 */
/* 92 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */
/* 96 */	NdrFcShort( 0x8 ),	/* 8 */
/* 98 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter name */

/* 100 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 102 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 104 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter pVal */

/* 106 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 108 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 110 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 114 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_item */

/* 118 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0x8 ),	/* 8 */
/* 126 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 132 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter name */

/* 134 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 136 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 138 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter newVal */

/* 140 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 142 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 144 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Return value */

/* 146 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 148 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_count */

/* 152 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 154 */	NdrFcLong( 0x0 ),	/* 0 */
/* 158 */	NdrFcShort( 0x9 ),	/* 9 */
/* 160 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0x24 ),	/* 36 */
/* 166 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 168 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 170 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 172 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 174 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 176 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure clear */

/* 180 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 182 */	NdrFcLong( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0xa ),	/* 10 */
/* 188 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 192 */	NdrFcShort( 0x8 ),	/* 8 */
/* 194 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 196 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 198 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 200 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure loadBody */


	/* Procedure erase */

/* 202 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 204 */	NdrFcLong( 0x0 ),	/* 0 */
/* 208 */	NdrFcShort( 0xb ),	/* 11 */
/* 210 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 214 */	NdrFcShort( 0x8 ),	/* 8 */
/* 216 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter filename */


	/* Parameter name */

/* 218 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 220 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 222 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Return value */


	/* Return value */

/* 224 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 226 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 228 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get__NewEnum */

/* 230 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 232 */	NdrFcLong( 0x0 ),	/* 0 */
/* 236 */	NdrFcShort( 0xc ),	/* 12 */
/* 238 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 242 */	NdrFcShort( 0x8 ),	/* 8 */
/* 244 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 246 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 248 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 250 */	NdrFcShort( 0x50 ),	/* Type Offset=80 */

	/* Return value */

/* 252 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 254 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 256 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure add */

/* 258 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 260 */	NdrFcLong( 0x0 ),	/* 0 */
/* 264 */	NdrFcShort( 0xd ),	/* 13 */
/* 266 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 270 */	NdrFcShort( 0x8 ),	/* 8 */
/* 272 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter name */

/* 274 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 276 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 278 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter pRet */

/* 280 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 282 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 284 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 286 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 288 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 290 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure exist */

/* 292 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 294 */	NdrFcLong( 0x0 ),	/* 0 */
/* 298 */	NdrFcShort( 0xe ),	/* 14 */
/* 300 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 304 */	NdrFcShort( 0x22 ),	/* 34 */
/* 306 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter name */

/* 308 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 310 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 312 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter pVal */

/* 314 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 316 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 318 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 320 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 322 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 324 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure parse */

/* 326 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 328 */	NdrFcLong( 0x0 ),	/* 0 */
/* 332 */	NdrFcShort( 0x7 ),	/* 7 */
/* 334 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 336 */	NdrFcShort( 0x6 ),	/* 6 */
/* 338 */	NdrFcShort( 0x8 ),	/* 8 */
/* 340 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter data */

/* 342 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 344 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 346 */	NdrFcShort( 0x42c ),	/* Type Offset=1068 */

	/* Parameter only_headers */

/* 348 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 350 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 352 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 354 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 356 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 358 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_from */


	/* Procedure save */

/* 360 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 362 */	NdrFcLong( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x8 ),	/* 8 */
/* 368 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 372 */	NdrFcShort( 0x8 ),	/* 8 */
/* 374 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter newVal */


	/* Parameter filename */

/* 376 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 378 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 380 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Return value */


	/* Return value */

/* 382 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 384 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 386 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure load */

/* 388 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 390 */	NdrFcLong( 0x0 ),	/* 0 */
/* 394 */	NdrFcShort( 0x9 ),	/* 9 */
/* 396 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 398 */	NdrFcShort( 0x6 ),	/* 6 */
/* 400 */	NdrFcShort( 0x8 ),	/* 8 */
/* 402 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter filename */

/* 404 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 406 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 408 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter only_header */

/* 410 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 412 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 414 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 416 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 418 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 420 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_to */


	/* Procedure setBodyText */

/* 422 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 424 */	NdrFcLong( 0x0 ),	/* 0 */
/* 428 */	NdrFcShort( 0xa ),	/* 10 */
/* 430 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 434 */	NdrFcShort( 0x8 ),	/* 8 */
/* 436 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter newVal */


	/* Parameter text */

/* 438 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 440 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 442 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Return value */


	/* Return value */

/* 444 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 446 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 448 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_headers */

/* 450 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 452 */	NdrFcLong( 0x0 ),	/* 0 */
/* 456 */	NdrFcShort( 0xc ),	/* 12 */
/* 458 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 462 */	NdrFcShort( 0x8 ),	/* 8 */
/* 464 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 466 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 468 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 470 */	NdrFcShort( 0x436 ),	/* Type Offset=1078 */

	/* Return value */

/* 472 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 474 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 476 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_body */

/* 478 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 480 */	NdrFcLong( 0x0 ),	/* 0 */
/* 484 */	NdrFcShort( 0xd ),	/* 13 */
/* 486 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 490 */	NdrFcShort( 0x8 ),	/* 8 */
/* 492 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 494 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 496 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 498 */	NdrFcShort( 0x458 ),	/* Type Offset=1112 */

	/* Return value */

/* 500 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 502 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 504 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_body */

/* 506 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 508 */	NdrFcLong( 0x0 ),	/* 0 */
/* 512 */	NdrFcShort( 0xe ),	/* 14 */
/* 514 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 518 */	NdrFcShort( 0x8 ),	/* 8 */
/* 520 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 522 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 524 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 526 */	NdrFcShort( 0x42c ),	/* Type Offset=1068 */

	/* Return value */

/* 528 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 530 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 532 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_subject */


	/* Procedure getBodyText */

/* 534 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 536 */	NdrFcLong( 0x0 ),	/* 0 */
/* 540 */	NdrFcShort( 0xf ),	/* 15 */
/* 542 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 546 */	NdrFcShort( 0x8 ),	/* 8 */
/* 548 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 550 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 552 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 554 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */


	/* Return value */

/* 556 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 558 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 560 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_subject */


	/* Procedure saveBody */

/* 562 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 564 */	NdrFcLong( 0x0 ),	/* 0 */
/* 568 */	NdrFcShort( 0x10 ),	/* 16 */
/* 570 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 574 */	NdrFcShort( 0x8 ),	/* 8 */
/* 576 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter newVal */


	/* Parameter filename */

/* 578 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 580 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 582 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Return value */


	/* Return value */

/* 584 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 586 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_multiparts */

/* 590 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 592 */	NdrFcLong( 0x0 ),	/* 0 */
/* 596 */	NdrFcShort( 0x11 ),	/* 17 */
/* 598 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 602 */	NdrFcShort( 0x8 ),	/* 8 */
/* 604 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 606 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 608 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 610 */	NdrFcShort( 0x462 ),	/* Type Offset=1122 */

	/* Return value */

/* 612 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 614 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure createAlternativeBody */

/* 618 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 620 */	NdrFcLong( 0x0 ),	/* 0 */
/* 624 */	NdrFcShort( 0x12 ),	/* 18 */
/* 626 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 630 */	NdrFcShort( 0x8 ),	/* 8 */
/* 632 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter text */

/* 634 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 636 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 638 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter html */

/* 640 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 642 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 644 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter attachments */

/* 646 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 648 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 650 */	NdrFcShort( 0x47c ),	/* Type Offset=1148 */

	/* Return value */

/* 652 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 654 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 656 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure createTextBody */

/* 658 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 660 */	NdrFcLong( 0x0 ),	/* 0 */
/* 664 */	NdrFcShort( 0x13 ),	/* 19 */
/* 666 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 670 */	NdrFcShort( 0x8 ),	/* 8 */
/* 672 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter text */

/* 674 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 676 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 678 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter attachments */

/* 680 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 682 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 684 */	NdrFcShort( 0x47c ),	/* Type Offset=1148 */

	/* Return value */

/* 686 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 688 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 690 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure createHtmlBody */

/* 692 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 694 */	NdrFcLong( 0x0 ),	/* 0 */
/* 698 */	NdrFcShort( 0x14 ),	/* 20 */
/* 700 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 704 */	NdrFcShort( 0x8 ),	/* 8 */
/* 706 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter html */

/* 708 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 710 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 712 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter attachments */

/* 714 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 716 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 718 */	NdrFcShort( 0x47c ),	/* Type Offset=1148 */

	/* Return value */

/* 720 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 722 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 724 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure createRelatedBody */

/* 726 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 728 */	NdrFcLong( 0x0 ),	/* 0 */
/* 732 */	NdrFcShort( 0x15 ),	/* 21 */
/* 734 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 736 */	NdrFcShort( 0x6 ),	/* 6 */
/* 738 */	NdrFcShort( 0x8 ),	/* 8 */
/* 740 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x5,		/* 5 */

	/* Parameter html */

/* 742 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 744 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 746 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter pictures */

/* 748 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 750 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 752 */	NdrFcShort( 0x47c ),	/* Type Offset=1148 */

	/* Parameter attachments */

/* 754 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 756 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 758 */	NdrFcShort( 0x47c ),	/* Type Offset=1148 */

	/* Parameter use_cid */

/* 760 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 762 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 764 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 766 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 768 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 770 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure createAlternativeBodyF */

/* 772 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 774 */	NdrFcLong( 0x0 ),	/* 0 */
/* 778 */	NdrFcShort( 0x16 ),	/* 22 */
/* 780 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 784 */	NdrFcShort( 0x8 ),	/* 8 */
/* 786 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter textFile */

/* 788 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 790 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 792 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter htmlFile */

/* 794 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 796 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 798 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter attachments */

/* 800 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 802 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 804 */	NdrFcShort( 0x47c ),	/* Type Offset=1148 */

	/* Return value */

/* 806 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 808 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure createTextBodyF */

/* 812 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 814 */	NdrFcLong( 0x0 ),	/* 0 */
/* 818 */	NdrFcShort( 0x17 ),	/* 23 */
/* 820 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 824 */	NdrFcShort( 0x8 ),	/* 8 */
/* 826 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter textFile */

/* 828 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 830 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 832 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter attachments */

/* 834 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 836 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 838 */	NdrFcShort( 0x47c ),	/* Type Offset=1148 */

	/* Return value */

/* 840 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 842 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 844 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure createHtmlBodyF */

/* 846 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 848 */	NdrFcLong( 0x0 ),	/* 0 */
/* 852 */	NdrFcShort( 0x18 ),	/* 24 */
/* 854 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 858 */	NdrFcShort( 0x8 ),	/* 8 */
/* 860 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter htmlFile */

/* 862 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 864 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 866 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter attachments */

/* 868 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 870 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 872 */	NdrFcShort( 0x47c ),	/* Type Offset=1148 */

	/* Return value */

/* 874 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 876 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 878 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure createRelatedBodyF */

/* 880 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 882 */	NdrFcLong( 0x0 ),	/* 0 */
/* 886 */	NdrFcShort( 0x19 ),	/* 25 */
/* 888 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 890 */	NdrFcShort( 0x6 ),	/* 6 */
/* 892 */	NdrFcShort( 0x8 ),	/* 8 */
/* 894 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x5,		/* 5 */

	/* Parameter htmlFile */

/* 896 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 898 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 900 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter pictures */

/* 902 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 904 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 906 */	NdrFcShort( 0x47c ),	/* Type Offset=1148 */

	/* Parameter attachments */

/* 908 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 910 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 912 */	NdrFcShort( 0x47c ),	/* Type Offset=1148 */

	/* Parameter use_cid */

/* 914 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 916 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 918 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 920 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 922 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 924 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure generateId */

/* 926 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 928 */	NdrFcLong( 0x0 ),	/* 0 */
/* 932 */	NdrFcShort( 0x1a ),	/* 26 */
/* 934 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 938 */	NdrFcShort( 0x8 ),	/* 8 */
/* 940 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 942 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 944 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_contentType */

/* 948 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 950 */	NdrFcLong( 0x0 ),	/* 0 */
/* 954 */	NdrFcShort( 0x1b ),	/* 27 */
/* 956 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 960 */	NdrFcShort( 0x8 ),	/* 8 */
/* 962 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 964 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 966 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 968 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 970 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 972 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 974 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_filename */

/* 976 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 978 */	NdrFcLong( 0x0 ),	/* 0 */
/* 982 */	NdrFcShort( 0x1c ),	/* 28 */
/* 984 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 988 */	NdrFcShort( 0x8 ),	/* 8 */
/* 990 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 992 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 994 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 996 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 998 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1000 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1002 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_extname */

/* 1004 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1006 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1010 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1012 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1014 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1016 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1018 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1020 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1022 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1024 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 1026 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1028 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_item */

/* 1032 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1034 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1038 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1040 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1042 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1044 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1046 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x3,		/* 3 */

	/* Parameter index */

/* 1048 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1050 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1052 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1054 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1056 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1058 */	NdrFcShort( 0x486 ),	/* Type Offset=1158 */

	/* Return value */

/* 1060 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1062 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1064 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_count */


	/* Procedure get_count */

/* 1066 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1068 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1072 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1074 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1078 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1080 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 1082 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1084 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1086 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1088 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1090 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1092 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure clear */

/* 1094 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1096 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1100 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1102 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1106 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1108 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 1110 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1112 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1114 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure erase */

/* 1116 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1118 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1122 */	NdrFcShort( 0xa ),	/* 10 */
/* 1124 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1126 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1128 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1130 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter index */

/* 1132 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1134 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1140 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get__NewEnum */

/* 1144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1150 */	NdrFcShort( 0xb ),	/* 11 */
/* 1152 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1158 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1160 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1162 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1164 */	NdrFcShort( 0x49c ),	/* Type Offset=1180 */

	/* Return value */

/* 1166 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1168 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1170 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure add */

/* 1172 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1174 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1178 */	NdrFcShort( 0xc ),	/* 12 */
/* 1180 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1184 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1186 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter content */

/* 1188 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1190 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1192 */	NdrFcShort( 0x48a ),	/* Type Offset=1162 */

	/* Return value */

/* 1194 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1196 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1198 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_to */

/* 1200 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1202 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1206 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1208 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1212 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1214 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1216 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1218 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1220 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 1222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1224 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_cc */

/* 1228 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1234 */	NdrFcShort( 0xb ),	/* 11 */
/* 1236 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1240 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1242 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1244 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1246 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1248 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 1250 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1252 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1254 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_cc */

/* 1256 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1258 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1262 */	NdrFcShort( 0xc ),	/* 12 */
/* 1264 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1268 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1270 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 1272 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1274 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1276 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Return value */

/* 1278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1280 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_bcc */

/* 1284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1290 */	NdrFcShort( 0xd ),	/* 13 */
/* 1292 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1298 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1300 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1302 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1304 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 1306 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1308 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1310 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_bcc */

/* 1312 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1314 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1318 */	NdrFcShort( 0xe ),	/* 14 */
/* 1320 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1324 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1326 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 1328 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1330 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1332 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Return value */

/* 1334 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1336 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_content */

/* 1340 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1342 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1346 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1348 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1352 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1354 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1356 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1358 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1360 */	NdrFcShort( 0x486 ),	/* Type Offset=1158 */

	/* Return value */

/* 1362 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1364 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1366 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_date */

/* 1368 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1370 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1374 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1376 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1380 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1382 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1384 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1386 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1388 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 1390 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1392 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_date */

/* 1396 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1398 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1402 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1404 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1406 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1408 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1410 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 1412 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1414 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1416 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 1418 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1420 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1422 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_item */

/* 1424 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1426 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1430 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1432 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1434 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1436 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1438 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x3,		/* 3 */

	/* Parameter index */

/* 1440 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1442 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1444 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1446 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1448 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1450 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 1452 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1454 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1456 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure contact */


	/* Procedure contact */

/* 1458 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1460 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1464 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1466 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1468 */	NdrFcShort( 0xe ),	/* 14 */
/* 1470 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1472 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x5,		/* 5 */

	/* Parameter host */


	/* Parameter host */

/* 1474 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1476 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1478 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter port */


	/* Parameter port */

/* 1480 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1482 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1484 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter use_ssl */


	/* Parameter use_ssl */

/* 1486 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1488 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1490 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 1492 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1494 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1496 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1498 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1500 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1502 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure quit */


	/* Procedure quit */

/* 1504 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1506 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1510 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1512 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1516 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1518 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 1520 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1522 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1524 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1526 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1528 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure auth */


	/* Procedure auth */

/* 1532 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1534 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1538 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1540 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1542 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1544 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1546 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x5,		/* 5 */

	/* Parameter username */


	/* Parameter username */

/* 1548 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1550 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1552 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter password */


	/* Parameter password */

/* 1554 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1556 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1558 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter authType */


	/* Parameter authType */

/* 1560 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1562 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1564 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 1566 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1568 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1570 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1572 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1574 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1576 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_authTypes */

/* 1578 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1580 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1584 */	NdrFcShort( 0xa ),	/* 10 */
/* 1586 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1590 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1592 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1594 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1596 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1598 */	NdrFcShort( 0x4b6 ),	/* Type Offset=1206 */

	/* Return value */

/* 1600 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1602 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1604 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure hello */

/* 1606 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1608 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1612 */	NdrFcShort( 0xb ),	/* 11 */
/* 1614 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1618 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1620 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1622 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1624 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1626 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1628 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1630 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1632 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure starttls */

/* 1634 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1636 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1640 */	NdrFcShort( 0xc ),	/* 12 */
/* 1642 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1646 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1648 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1650 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1652 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1654 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1656 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1658 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1660 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure reset */

/* 1662 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1664 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1668 */	NdrFcShort( 0xd ),	/* 13 */
/* 1670 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1674 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1676 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1678 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1680 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1682 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1684 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1686 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1688 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure starttls */


	/* Procedure noop */

/* 1690 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1692 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1696 */	NdrFcShort( 0xe ),	/* 14 */
/* 1698 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1702 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1704 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 1706 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1708 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1710 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1712 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1714 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1716 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure expand */

/* 1718 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1720 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1724 */	NdrFcShort( 0xf ),	/* 15 */
/* 1726 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1730 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1732 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter mailingList */

/* 1734 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1736 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1738 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter mails */

/* 1740 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1742 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1744 */	NdrFcShort( 0x4d4 ),	/* Type Offset=1236 */

	/* Parameter pVal */

/* 1746 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1748 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1750 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1752 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1754 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1756 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure verify */

/* 1758 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1760 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1764 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1766 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1770 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1772 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter name */

/* 1774 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1776 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1778 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter mail */

/* 1780 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1782 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1784 */	NdrFcShort( 0x4d4 ),	/* Type Offset=1236 */

	/* Parameter pVal */

/* 1786 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1788 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1790 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1792 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1794 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1796 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_enable8Bit */

/* 1798 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1800 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1804 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1806 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1810 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1812 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1814 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1816 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1818 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1820 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1822 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1824 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure noop */


	/* Procedure get_enableStartTls */

/* 1826 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1828 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1832 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1834 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1838 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1840 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 1842 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1844 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1846 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1848 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1850 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1852 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure reset */


	/* Procedure get_enablePipling */

/* 1854 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1856 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1860 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1862 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1866 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1868 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 1870 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1872 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1874 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1876 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1878 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1880 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_maxMailSize */

/* 1882 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1884 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1888 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1890 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1894 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1896 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1898 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1900 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1902 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1904 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1906 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1908 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure mailFrom */

/* 1910 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1912 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1916 */	NdrFcShort( 0x15 ),	/* 21 */
/* 1918 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1922 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1924 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter mailAddress */

/* 1926 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1928 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1930 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter pVal */

/* 1932 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1934 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1936 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1938 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1940 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1942 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure rcptTo */

/* 1944 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1946 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1950 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1952 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1954 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1956 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1958 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter mailAddress */

/* 1960 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1962 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1964 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter pVal */

/* 1966 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1968 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1970 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1972 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1974 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1976 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure addressesByMail */

/* 1978 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1980 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1984 */	NdrFcShort( 0x17 ),	/* 23 */
/* 1986 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1990 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1992 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter mail */

/* 1994 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1996 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1998 */	NdrFcShort( 0x4de ),	/* Type Offset=1246 */

	/* Parameter pVal */

/* 2000 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2002 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2004 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2006 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2008 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2010 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure sendMail */

/* 2012 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2014 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2018 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2020 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2024 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2026 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter mail */

/* 2028 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2030 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2032 */	NdrFcShort( 0x4de ),	/* Type Offset=1246 */

	/* Parameter pVal */

/* 2034 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2036 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2038 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2040 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2042 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2044 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure capability */

/* 2046 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2048 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2052 */	NdrFcShort( 0xa ),	/* 10 */
/* 2054 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2058 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2060 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 2062 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2064 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2066 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2068 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2070 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2072 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure list */

/* 2074 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2076 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2080 */	NdrFcShort( 0xb ),	/* 11 */
/* 2082 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2086 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2088 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x3,		/* 3 */

	/* Parameter mailIndex */

/* 2090 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2092 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2094 */	NdrFcShort( 0x4d4 ),	/* Type Offset=1236 */

	/* Parameter pVal */

/* 2096 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2098 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2100 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2102 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2104 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure uidl */

/* 2108 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2114 */	NdrFcShort( 0xc ),	/* 12 */
/* 2116 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2120 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2122 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x3,		/* 3 */

	/* Parameter uidIndex */

/* 2124 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2126 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2128 */	NdrFcShort( 0x4d4 ),	/* Type Offset=1236 */

	/* Parameter pVal */

/* 2130 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2132 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2134 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2136 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2138 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2140 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure stat */

/* 2142 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2144 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2148 */	NdrFcShort( 0xd ),	/* 13 */
/* 2150 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2154 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2156 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x4,		/* 4 */

	/* Parameter mailCount */

/* 2158 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2160 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2162 */	NdrFcShort( 0x4d4 ),	/* Type Offset=1236 */

	/* Parameter totalSize */

/* 2164 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2166 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2168 */	NdrFcShort( 0x4d4 ),	/* Type Offset=1236 */

	/* Parameter pVal */

/* 2170 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2172 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2174 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2176 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2178 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure returnMailHeader */

/* 2182 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2184 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2188 */	NdrFcShort( 0xf ),	/* 15 */
/* 2190 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2192 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2194 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2196 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x3,		/* 3 */

	/* Parameter id */

/* 2198 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2200 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pMail */

/* 2204 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2206 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2208 */	NdrFcShort( 0x4f0 ),	/* Type Offset=1264 */

	/* Return value */

/* 2210 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2212 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2214 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure returnMail */

/* 2216 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2218 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2222 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2224 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2226 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2228 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2230 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x3,		/* 3 */

	/* Parameter id */

/* 2232 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2234 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pMail */

/* 2238 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2240 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2242 */	NdrFcShort( 0x4f0 ),	/* Type Offset=1264 */

	/* Return value */

/* 2244 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2246 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2248 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure deleteMail */

/* 2250 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2252 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2256 */	NdrFcShort( 0x11 ),	/* 17 */
/* 2258 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2260 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2262 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2264 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter id */

/* 2266 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2268 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 2272 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2274 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2276 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2280 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_authTypes */

/* 2284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2290 */	NdrFcShort( 0x14 ),	/* 20 */
/* 2292 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2298 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 2300 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2302 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2304 */	NdrFcShort( 0x4b6 ),	/* Type Offset=1206 */

	/* Return value */

/* 2306 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2308 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2310 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_enableStartTls */

/* 2312 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2314 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2318 */	NdrFcShort( 0x15 ),	/* 21 */
/* 2320 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2324 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2326 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 2328 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2330 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2332 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2334 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2336 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/*  4 */	NdrFcShort( 0x1a ),	/* Offset= 26 (30) */
/*  6 */	
			0x13, 0x0,	/* FC_OP */
/*  8 */	NdrFcShort( 0xc ),	/* Offset= 12 (20) */
/* 10 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 12 */	NdrFcShort( 0x2 ),	/* 2 */
/* 14 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 16 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 18 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 20 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 22 */	NdrFcShort( 0x8 ),	/* 8 */
/* 24 */	NdrFcShort( 0xfff2 ),	/* Offset= -14 (10) */
/* 26 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 28 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 30 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 32 */	NdrFcShort( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0x4 ),	/* 4 */
/* 36 */	NdrFcShort( 0x0 ),	/* 0 */
/* 38 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (6) */
/* 40 */	
			0x12, 0x0,	/* FC_UP */
/* 42 */	NdrFcShort( 0xffea ),	/* Offset= -22 (20) */
/* 44 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x4 ),	/* 4 */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (40) */
/* 54 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 56 */	NdrFcShort( 0x2 ),	/* Offset= 2 (58) */
/* 58 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 60 */	NdrFcLong( 0x4d9b8fe2 ),	/* 1302040546 */
/* 64 */	NdrFcShort( 0xe781 ),	/* -6271 */
/* 66 */	NdrFcShort( 0x4b07 ),	/* 19207 */
/* 68 */	0x90,		/* 144 */
			0xa4,		/* 164 */
/* 70 */	0xf5,		/* 245 */
			0xa1,		/* 161 */
/* 72 */	0x18,		/* 24 */
			0xda,		/* 218 */
/* 74 */	0xcf,		/* 207 */
			0x55,		/* 85 */
/* 76 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 78 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 80 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 82 */	NdrFcShort( 0x2 ),	/* Offset= 2 (84) */
/* 84 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 86 */	NdrFcLong( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 96 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 98 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 100 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 102 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 104 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 106 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 108 */	NdrFcShort( 0x2 ),	/* Offset= 2 (110) */
/* 110 */	
			0x12, 0x0,	/* FC_UP */
/* 112 */	NdrFcShort( 0x3aa ),	/* Offset= 938 (1050) */
/* 114 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 116 */	NdrFcShort( 0x18 ),	/* 24 */
/* 118 */	NdrFcShort( 0xa ),	/* 10 */
/* 120 */	NdrFcLong( 0x8 ),	/* 8 */
/* 124 */	NdrFcShort( 0x58 ),	/* Offset= 88 (212) */
/* 126 */	NdrFcLong( 0xd ),	/* 13 */
/* 130 */	NdrFcShort( 0x78 ),	/* Offset= 120 (250) */
/* 132 */	NdrFcLong( 0x9 ),	/* 9 */
/* 136 */	NdrFcShort( 0xa6 ),	/* Offset= 166 (302) */
/* 138 */	NdrFcLong( 0xc ),	/* 12 */
/* 142 */	NdrFcShort( 0x29a ),	/* Offset= 666 (808) */
/* 144 */	NdrFcLong( 0x24 ),	/* 36 */
/* 148 */	NdrFcShort( 0x2c2 ),	/* Offset= 706 (854) */
/* 150 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 154 */	NdrFcShort( 0x2de ),	/* Offset= 734 (888) */
/* 156 */	NdrFcLong( 0x10 ),	/* 16 */
/* 160 */	NdrFcShort( 0x2f6 ),	/* Offset= 758 (918) */
/* 162 */	NdrFcLong( 0x2 ),	/* 2 */
/* 166 */	NdrFcShort( 0x30e ),	/* Offset= 782 (948) */
/* 168 */	NdrFcLong( 0x3 ),	/* 3 */
/* 172 */	NdrFcShort( 0x326 ),	/* Offset= 806 (978) */
/* 174 */	NdrFcLong( 0x14 ),	/* 20 */
/* 178 */	NdrFcShort( 0x33e ),	/* Offset= 830 (1008) */
/* 180 */	NdrFcShort( 0xffff ),	/* Offset= -1 (179) */
/* 182 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 184 */	NdrFcShort( 0x4 ),	/* 4 */
/* 186 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 190 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 192 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 194 */	NdrFcShort( 0x4 ),	/* 4 */
/* 196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0x1 ),	/* 1 */
/* 200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 204 */	0x12, 0x0,	/* FC_UP */
/* 206 */	NdrFcShort( 0xff46 ),	/* Offset= -186 (20) */
/* 208 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 210 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 212 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 214 */	NdrFcShort( 0x8 ),	/* 8 */
/* 216 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 218 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 220 */	NdrFcShort( 0x4 ),	/* 4 */
/* 222 */	NdrFcShort( 0x4 ),	/* 4 */
/* 224 */	0x11, 0x0,	/* FC_RP */
/* 226 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (182) */
/* 228 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 230 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 232 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 236 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 240 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 244 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 246 */	NdrFcShort( 0xff5e ),	/* Offset= -162 (84) */
/* 248 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 250 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 252 */	NdrFcShort( 0x8 ),	/* 8 */
/* 254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 256 */	NdrFcShort( 0x6 ),	/* Offset= 6 (262) */
/* 258 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 260 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 262 */	
			0x11, 0x0,	/* FC_RP */
/* 264 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (232) */
/* 266 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 268 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 276 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 278 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 280 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 282 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 284 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 288 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 292 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 296 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 298 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (266) */
/* 300 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 302 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 304 */	NdrFcShort( 0x8 ),	/* 8 */
/* 306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 308 */	NdrFcShort( 0x6 ),	/* Offset= 6 (314) */
/* 310 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 312 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 314 */	
			0x11, 0x0,	/* FC_RP */
/* 316 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (284) */
/* 318 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 320 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 322 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 324 */	NdrFcShort( 0x2 ),	/* Offset= 2 (326) */
/* 326 */	NdrFcShort( 0x10 ),	/* 16 */
/* 328 */	NdrFcShort( 0x2f ),	/* 47 */
/* 330 */	NdrFcLong( 0x14 ),	/* 20 */
/* 334 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 336 */	NdrFcLong( 0x3 ),	/* 3 */
/* 340 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 342 */	NdrFcLong( 0x11 ),	/* 17 */
/* 346 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 348 */	NdrFcLong( 0x2 ),	/* 2 */
/* 352 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 354 */	NdrFcLong( 0x4 ),	/* 4 */
/* 358 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 360 */	NdrFcLong( 0x5 ),	/* 5 */
/* 364 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 366 */	NdrFcLong( 0xb ),	/* 11 */
/* 370 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 372 */	NdrFcLong( 0xa ),	/* 10 */
/* 376 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 378 */	NdrFcLong( 0x6 ),	/* 6 */
/* 382 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (614) */
/* 384 */	NdrFcLong( 0x7 ),	/* 7 */
/* 388 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 390 */	NdrFcLong( 0x8 ),	/* 8 */
/* 394 */	NdrFcShort( 0xfe9e ),	/* Offset= -354 (40) */
/* 396 */	NdrFcLong( 0xd ),	/* 13 */
/* 400 */	NdrFcShort( 0xfec4 ),	/* Offset= -316 (84) */
/* 402 */	NdrFcLong( 0x9 ),	/* 9 */
/* 406 */	NdrFcShort( 0xff74 ),	/* Offset= -140 (266) */
/* 408 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 412 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (620) */
/* 414 */	NdrFcLong( 0x24 ),	/* 36 */
/* 418 */	NdrFcShort( 0xd2 ),	/* Offset= 210 (628) */
/* 420 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 424 */	NdrFcShort( 0xcc ),	/* Offset= 204 (628) */
/* 426 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 430 */	NdrFcShort( 0xfa ),	/* Offset= 250 (680) */
/* 432 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 436 */	NdrFcShort( 0xf8 ),	/* Offset= 248 (684) */
/* 438 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 442 */	NdrFcShort( 0xf6 ),	/* Offset= 246 (688) */
/* 444 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 448 */	NdrFcShort( 0xf4 ),	/* Offset= 244 (692) */
/* 450 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 454 */	NdrFcShort( 0xf2 ),	/* Offset= 242 (696) */
/* 456 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 460 */	NdrFcShort( 0xf0 ),	/* Offset= 240 (700) */
/* 462 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 466 */	NdrFcShort( 0xda ),	/* Offset= 218 (684) */
/* 468 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 472 */	NdrFcShort( 0xd8 ),	/* Offset= 216 (688) */
/* 474 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 478 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (704) */
/* 480 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 484 */	NdrFcShort( 0xd8 ),	/* Offset= 216 (700) */
/* 486 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 490 */	NdrFcShort( 0xda ),	/* Offset= 218 (708) */
/* 492 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 496 */	NdrFcShort( 0xd8 ),	/* Offset= 216 (712) */
/* 498 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 502 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (716) */
/* 504 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 508 */	NdrFcShort( 0xd4 ),	/* Offset= 212 (720) */
/* 510 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 514 */	NdrFcShort( 0xda ),	/* Offset= 218 (732) */
/* 516 */	NdrFcLong( 0x10 ),	/* 16 */
/* 520 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 522 */	NdrFcLong( 0x12 ),	/* 18 */
/* 526 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 528 */	NdrFcLong( 0x13 ),	/* 19 */
/* 532 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 534 */	NdrFcLong( 0x15 ),	/* 21 */
/* 538 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 540 */	NdrFcLong( 0x16 ),	/* 22 */
/* 544 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 546 */	NdrFcLong( 0x17 ),	/* 23 */
/* 550 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 552 */	NdrFcLong( 0xe ),	/* 14 */
/* 556 */	NdrFcShort( 0xb8 ),	/* Offset= 184 (740) */
/* 558 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 562 */	NdrFcShort( 0xbc ),	/* Offset= 188 (750) */
/* 564 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 568 */	NdrFcShort( 0xba ),	/* Offset= 186 (754) */
/* 570 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 574 */	NdrFcShort( 0x6e ),	/* Offset= 110 (684) */
/* 576 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 580 */	NdrFcShort( 0x6c ),	/* Offset= 108 (688) */
/* 582 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 586 */	NdrFcShort( 0x6a ),	/* Offset= 106 (692) */
/* 588 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 592 */	NdrFcShort( 0x60 ),	/* Offset= 96 (688) */
/* 594 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 598 */	NdrFcShort( 0x5a ),	/* Offset= 90 (688) */
/* 600 */	NdrFcLong( 0x0 ),	/* 0 */
/* 604 */	NdrFcShort( 0x0 ),	/* Offset= 0 (604) */
/* 606 */	NdrFcLong( 0x1 ),	/* 1 */
/* 610 */	NdrFcShort( 0x0 ),	/* Offset= 0 (610) */
/* 612 */	NdrFcShort( 0xffff ),	/* Offset= -1 (611) */
/* 614 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 616 */	NdrFcShort( 0x8 ),	/* 8 */
/* 618 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 620 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 622 */	NdrFcShort( 0x2 ),	/* Offset= 2 (624) */
/* 624 */	
			0x12, 0x0,	/* FC_UP */
/* 626 */	NdrFcShort( 0x1a8 ),	/* Offset= 424 (1050) */
/* 628 */	
			0x12, 0x0,	/* FC_UP */
/* 630 */	NdrFcShort( 0x1e ),	/* Offset= 30 (660) */
/* 632 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 634 */	NdrFcLong( 0x2f ),	/* 47 */
/* 638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 642 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 644 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 646 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 648 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 650 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 652 */	NdrFcShort( 0x1 ),	/* 1 */
/* 654 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 656 */	NdrFcShort( 0x4 ),	/* 4 */
/* 658 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 660 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 662 */	NdrFcShort( 0x10 ),	/* 16 */
/* 664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 666 */	NdrFcShort( 0xa ),	/* Offset= 10 (676) */
/* 668 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 670 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 672 */	NdrFcShort( 0xffd8 ),	/* Offset= -40 (632) */
/* 674 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 676 */	
			0x12, 0x0,	/* FC_UP */
/* 678 */	NdrFcShort( 0xffe4 ),	/* Offset= -28 (650) */
/* 680 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 682 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 684 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 686 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 688 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 690 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 692 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 694 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 696 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 698 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 700 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 702 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 704 */	
			0x12, 0x0,	/* FC_UP */
/* 706 */	NdrFcShort( 0xffa4 ),	/* Offset= -92 (614) */
/* 708 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 710 */	NdrFcShort( 0xfd62 ),	/* Offset= -670 (40) */
/* 712 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 714 */	NdrFcShort( 0xfd8a ),	/* Offset= -630 (84) */
/* 716 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 718 */	NdrFcShort( 0xfe3c ),	/* Offset= -452 (266) */
/* 720 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 722 */	NdrFcShort( 0x2 ),	/* Offset= 2 (724) */
/* 724 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 726 */	NdrFcShort( 0x2 ),	/* Offset= 2 (728) */
/* 728 */	
			0x12, 0x0,	/* FC_UP */
/* 730 */	NdrFcShort( 0x140 ),	/* Offset= 320 (1050) */
/* 732 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 734 */	NdrFcShort( 0x2 ),	/* Offset= 2 (736) */
/* 736 */	
			0x12, 0x0,	/* FC_UP */
/* 738 */	NdrFcShort( 0x14 ),	/* Offset= 20 (758) */
/* 740 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 742 */	NdrFcShort( 0x10 ),	/* 16 */
/* 744 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 746 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 748 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 750 */	
			0x12, 0x0,	/* FC_UP */
/* 752 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (740) */
/* 754 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 756 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 758 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 760 */	NdrFcShort( 0x20 ),	/* 32 */
/* 762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 764 */	NdrFcShort( 0x0 ),	/* Offset= 0 (764) */
/* 766 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 768 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 770 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 772 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 774 */	NdrFcShort( 0xfe38 ),	/* Offset= -456 (318) */
/* 776 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 778 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 780 */	NdrFcShort( 0x4 ),	/* 4 */
/* 782 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 786 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 788 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 790 */	NdrFcShort( 0x4 ),	/* 4 */
/* 792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 794 */	NdrFcShort( 0x1 ),	/* 1 */
/* 796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 800 */	0x12, 0x0,	/* FC_UP */
/* 802 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (758) */
/* 804 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 806 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 808 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 810 */	NdrFcShort( 0x8 ),	/* 8 */
/* 812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 814 */	NdrFcShort( 0x6 ),	/* Offset= 6 (820) */
/* 816 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 818 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 820 */	
			0x11, 0x0,	/* FC_RP */
/* 822 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (778) */
/* 824 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 826 */	NdrFcShort( 0x4 ),	/* 4 */
/* 828 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 832 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 834 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 836 */	NdrFcShort( 0x4 ),	/* 4 */
/* 838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 840 */	NdrFcShort( 0x1 ),	/* 1 */
/* 842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 846 */	0x12, 0x0,	/* FC_UP */
/* 848 */	NdrFcShort( 0xff44 ),	/* Offset= -188 (660) */
/* 850 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 852 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 854 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 856 */	NdrFcShort( 0x8 ),	/* 8 */
/* 858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 860 */	NdrFcShort( 0x6 ),	/* Offset= 6 (866) */
/* 862 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 864 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 866 */	
			0x11, 0x0,	/* FC_RP */
/* 868 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (824) */
/* 870 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 872 */	NdrFcShort( 0x8 ),	/* 8 */
/* 874 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 876 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 878 */	NdrFcShort( 0x10 ),	/* 16 */
/* 880 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 882 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 884 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (870) */
			0x5b,		/* FC_END */
/* 888 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 890 */	NdrFcShort( 0x18 ),	/* 24 */
/* 892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 894 */	NdrFcShort( 0xa ),	/* Offset= 10 (904) */
/* 896 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 898 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 900 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (876) */
/* 902 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 904 */	
			0x11, 0x0,	/* FC_RP */
/* 906 */	NdrFcShort( 0xfd5e ),	/* Offset= -674 (232) */
/* 908 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 910 */	NdrFcShort( 0x1 ),	/* 1 */
/* 912 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 916 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 918 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 920 */	NdrFcShort( 0x8 ),	/* 8 */
/* 922 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 924 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 926 */	NdrFcShort( 0x4 ),	/* 4 */
/* 928 */	NdrFcShort( 0x4 ),	/* 4 */
/* 930 */	0x12, 0x0,	/* FC_UP */
/* 932 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (908) */
/* 934 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 936 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 938 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 940 */	NdrFcShort( 0x2 ),	/* 2 */
/* 942 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 946 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 948 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 950 */	NdrFcShort( 0x8 ),	/* 8 */
/* 952 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 954 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 956 */	NdrFcShort( 0x4 ),	/* 4 */
/* 958 */	NdrFcShort( 0x4 ),	/* 4 */
/* 960 */	0x12, 0x0,	/* FC_UP */
/* 962 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (938) */
/* 964 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 966 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 968 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 970 */	NdrFcShort( 0x4 ),	/* 4 */
/* 972 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 976 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 978 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 980 */	NdrFcShort( 0x8 ),	/* 8 */
/* 982 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 984 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 986 */	NdrFcShort( 0x4 ),	/* 4 */
/* 988 */	NdrFcShort( 0x4 ),	/* 4 */
/* 990 */	0x12, 0x0,	/* FC_UP */
/* 992 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (968) */
/* 994 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 996 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 998 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 1000 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1002 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1006 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1008 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1010 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1012 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1014 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1016 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1018 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1020 */	0x12, 0x0,	/* FC_UP */
/* 1022 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (998) */
/* 1024 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1026 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1028 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 1030 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1032 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1034 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1036 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1038 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1040 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 1042 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 1044 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1046 */	NdrFcShort( 0xffee ),	/* Offset= -18 (1028) */
/* 1048 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1050 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1052 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1054 */	NdrFcShort( 0xffee ),	/* Offset= -18 (1036) */
/* 1056 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1056) */
/* 1058 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1060 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1062 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1064 */	NdrFcShort( 0xfc4a ),	/* Offset= -950 (114) */
/* 1066 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1068 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1070 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1072 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1076 */	NdrFcShort( 0xfc36 ),	/* Offset= -970 (106) */
/* 1078 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1080 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1082) */
/* 1082 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1084 */	NdrFcLong( 0x883a711e ),	/* -2009435874 */
/* 1088 */	NdrFcShort( 0x6c77 ),	/* 27767 */
/* 1090 */	NdrFcShort( 0x4acf ),	/* 19151 */
/* 1092 */	0x80,		/* 128 */
			0x4f,		/* 79 */
/* 1094 */	0x76,		/* 118 */
			0x7c,		/* 124 */
/* 1096 */	0xfc,		/* 252 */
			0xd,		/* 13 */
/* 1098 */	0xc5,		/* 197 */
			0xa,		/* 10 */
/* 1100 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1102 */	NdrFcShort( 0xa ),	/* Offset= 10 (1112) */
/* 1104 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1106 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1108) */
/* 1108 */	
			0x13, 0x0,	/* FC_OP */
/* 1110 */	NdrFcShort( 0xffc4 ),	/* Offset= -60 (1050) */
/* 1112 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1114 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1116 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1120 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (1104) */
/* 1122 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1124 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1126) */
/* 1126 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1128 */	NdrFcLong( 0x3716a914 ),	/* 924231956 */
/* 1132 */	NdrFcShort( 0x91e2 ),	/* -28190 */
/* 1134 */	NdrFcShort( 0x4034 ),	/* 16436 */
/* 1136 */	0x84,		/* 132 */
			0xe6,		/* 230 */
/* 1138 */	0x2d,		/* 45 */
			0xeb,		/* 235 */
/* 1140 */	0x11,		/* 17 */
			0x4f,		/* 79 */
/* 1142 */	0xc5,		/* 197 */
			0x54,		/* 84 */
/* 1144 */	
			0x12, 0x0,	/* FC_UP */
/* 1146 */	NdrFcShort( 0xfe7c ),	/* Offset= -388 (758) */
/* 1148 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1150 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1152 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1156 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1144) */
/* 1158 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1160 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1162) */
/* 1162 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1164 */	NdrFcLong( 0x798f3451 ),	/* 2039428177 */
/* 1168 */	NdrFcShort( 0x59a0 ),	/* 22944 */
/* 1170 */	NdrFcShort( 0x4f09 ),	/* 20233 */
/* 1172 */	0x92,		/* 146 */
			0x68,		/* 104 */
/* 1174 */	0xc7,		/* 199 */
			0x30,		/* 48 */
/* 1176 */	0x33,		/* 51 */
			0x4c,		/* 76 */
/* 1178 */	0x38,		/* 56 */
			0x4c,		/* 76 */
/* 1180 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1182 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1184) */
/* 1184 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1186 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1194 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1196 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1198 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1200 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1202 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1204 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 1206 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1208 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1210) */
/* 1210 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1212 */	NdrFcLong( 0x3278d320 ),	/* 846779168 */
/* 1216 */	NdrFcShort( 0x60c2 ),	/* 24770 */
/* 1218 */	NdrFcShort( 0x43b4 ),	/* 17332 */
/* 1220 */	0xab,		/* 171 */
			0x95,		/* 149 */
/* 1222 */	0xfe,		/* 254 */
			0xaa,		/* 170 */
/* 1224 */	0x8a,		/* 138 */
			0x17,		/* 23 */
/* 1226 */	0xd6,		/* 214 */
			0x70,		/* 112 */
/* 1228 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1230 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1236) */
/* 1232 */	
			0x13, 0x0,	/* FC_OP */
/* 1234 */	NdrFcShort( 0xfe24 ),	/* Offset= -476 (758) */
/* 1236 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1238 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1240 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1244 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1232) */
/* 1246 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1248 */	NdrFcLong( 0xc19ed2a0 ),	/* -1046556000 */
/* 1252 */	NdrFcShort( 0x7414 ),	/* 29716 */
/* 1254 */	NdrFcShort( 0x474c ),	/* 18252 */
/* 1256 */	0xbb,		/* 187 */
			0x5e,		/* 94 */
/* 1258 */	0x7,		/* 7 */
			0x3a,		/* 58 */
/* 1260 */	0x9d,		/* 157 */
			0xf,		/* 15 */
/* 1262 */	0x2f,		/* 47 */
			0xea,		/* 234 */
/* 1264 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1266 */	NdrFcShort( 0xffec ),	/* Offset= -20 (1246) */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            LPSAFEARRAY_UserSize
            ,LPSAFEARRAY_UserMarshal
            ,LPSAFEARRAY_UserUnmarshal
            ,LPSAFEARRAY_UserFree
            },
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            }

        };



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IMessageHeader, ver. 0.0,
   GUID={0x4D9B8FE2,0xE781,0x4B07,{0x90,0xA4,0xF5,0xA1,0x18,0xDA,0xCF,0x55}} */

#pragma code_seg(".orpc")
static const unsigned short IMessageHeader_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    28,
    56
    };

static const MIDL_STUBLESS_PROXY_INFO IMessageHeader_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IMessageHeader_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMessageHeader_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IMessageHeader_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IMessageHeaderProxyVtbl = 
{
    &IMessageHeader_ProxyInfo,
    &IID_IMessageHeader,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IMessageHeader::get_name */ ,
    (void *) (INT_PTR) -1 /* IMessageHeader::get_text */ ,
    (void *) (INT_PTR) -1 /* IMessageHeader::put_text */
};


static const PRPC_STUB_FUNCTION IMessageHeader_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IMessageHeaderStubVtbl =
{
    &IID_IMessageHeader,
    &IMessageHeader_ServerInfo,
    10,
    &IMessageHeader_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IHeaders, ver. 0.0,
   GUID={0x883A711E,0x6C77,0x4ACF,{0x80,0x4F,0x76,0x7C,0xFC,0x0D,0xC5,0x0A}} */

#pragma code_seg(".orpc")
static const unsigned short IHeaders_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    84,
    118,
    152,
    180,
    202,
    230,
    258,
    292
    };

static const MIDL_STUBLESS_PROXY_INFO IHeaders_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHeaders_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHeaders_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHeaders_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(15) _IHeadersProxyVtbl = 
{
    &IHeaders_ProxyInfo,
    &IID_IHeaders,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IHeaders::get_item */ ,
    (void *) (INT_PTR) -1 /* IHeaders::put_item */ ,
    (void *) (INT_PTR) -1 /* IHeaders::get_count */ ,
    (void *) (INT_PTR) -1 /* IHeaders::clear */ ,
    (void *) (INT_PTR) -1 /* IHeaders::erase */ ,
    (void *) (INT_PTR) -1 /* IHeaders::get__NewEnum */ ,
    (void *) (INT_PTR) -1 /* IHeaders::add */ ,
    (void *) (INT_PTR) -1 /* IHeaders::exist */
};


static const PRPC_STUB_FUNCTION IHeaders_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IHeadersStubVtbl =
{
    &IID_IHeaders,
    &IHeaders_ServerInfo,
    15,
    &IHeaders_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Standard interface: __MIDL_itf_tmailx_0263, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IContent, ver. 0.0,
   GUID={0x798F3451,0x59A0,0x4F09,{0x92,0x68,0xC7,0x30,0x33,0x4C,0x38,0x4C}} */

#pragma code_seg(".orpc")
static const unsigned short IContent_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    326,
    360,
    388,
    422,
    202,
    450,
    478,
    506,
    534,
    562,
    590,
    618,
    658,
    692,
    726,
    772,
    812,
    846,
    880,
    926,
    948,
    976,
    1004
    };

static const MIDL_STUBLESS_PROXY_INFO IContent_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IContent_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IContent_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IContent_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(30) _IContentProxyVtbl = 
{
    &IContent_ProxyInfo,
    &IID_IContent,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IContent::parse */ ,
    (void *) (INT_PTR) -1 /* IContent::save */ ,
    (void *) (INT_PTR) -1 /* IContent::load */ ,
    (void *) (INT_PTR) -1 /* IContent::setBodyText */ ,
    (void *) (INT_PTR) -1 /* IContent::loadBody */ ,
    (void *) (INT_PTR) -1 /* IContent::get_headers */ ,
    (void *) (INT_PTR) -1 /* IContent::get_body */ ,
    (void *) (INT_PTR) -1 /* IContent::put_body */ ,
    (void *) (INT_PTR) -1 /* IContent::getBodyText */ ,
    (void *) (INT_PTR) -1 /* IContent::saveBody */ ,
    (void *) (INT_PTR) -1 /* IContent::get_multiparts */ ,
    (void *) (INT_PTR) -1 /* IContent::createAlternativeBody */ ,
    (void *) (INT_PTR) -1 /* IContent::createTextBody */ ,
    (void *) (INT_PTR) -1 /* IContent::createHtmlBody */ ,
    (void *) (INT_PTR) -1 /* IContent::createRelatedBody */ ,
    (void *) (INT_PTR) -1 /* IContent::createAlternativeBodyF */ ,
    (void *) (INT_PTR) -1 /* IContent::createTextBodyF */ ,
    (void *) (INT_PTR) -1 /* IContent::createHtmlBodyF */ ,
    (void *) (INT_PTR) -1 /* IContent::createRelatedBodyF */ ,
    (void *) (INT_PTR) -1 /* IContent::generateId */ ,
    (void *) (INT_PTR) -1 /* IContent::get_contentType */ ,
    (void *) (INT_PTR) -1 /* IContent::get_filename */ ,
    (void *) (INT_PTR) -1 /* IContent::get_extname */
};


static const PRPC_STUB_FUNCTION IContent_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IContentStubVtbl =
{
    &IID_IContent,
    &IContent_ServerInfo,
    30,
    &IContent_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IContents, ver. 0.0,
   GUID={0x3716A914,0x91E2,0x4034,{0x84,0xE6,0x2D,0xEB,0x11,0x4F,0xC5,0x54}} */

#pragma code_seg(".orpc")
static const unsigned short IContents_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1032,
    1066,
    1094,
    1116,
    1144,
    1172
    };

static const MIDL_STUBLESS_PROXY_INFO IContents_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IContents_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IContents_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IContents_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IContentsProxyVtbl = 
{
    &IContents_ProxyInfo,
    &IID_IContents,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IContents::get_item */ ,
    (void *) (INT_PTR) -1 /* IContents::get_count */ ,
    (void *) (INT_PTR) -1 /* IContents::clear */ ,
    (void *) (INT_PTR) -1 /* IContents::erase */ ,
    (void *) (INT_PTR) -1 /* IContents::get__NewEnum */ ,
    (void *) (INT_PTR) -1 /* IContents::add */
};


static const PRPC_STUB_FUNCTION IContents_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IContentsStubVtbl =
{
    &IID_IContents,
    &IContents_ServerInfo,
    13,
    &IContents_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IMail, ver. 0.0,
   GUID={0xC19ED2A0,0x7414,0x474C,{0xBB,0x5E,0x07,0x3A,0x9D,0x0F,0x2F,0xEA}} */

#pragma code_seg(".orpc")
static const unsigned short IMail_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    360,
    1200,
    422,
    1228,
    1256,
    1284,
    1312,
    534,
    562,
    1340,
    1368,
    1396
    };

static const MIDL_STUBLESS_PROXY_INFO IMail_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IMail_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMail_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IMail_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(20) _IMailProxyVtbl = 
{
    &IMail_ProxyInfo,
    &IID_IMail,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IMail::get_from */ ,
    (void *) (INT_PTR) -1 /* IMail::put_from */ ,
    (void *) (INT_PTR) -1 /* IMail::get_to */ ,
    (void *) (INT_PTR) -1 /* IMail::put_to */ ,
    (void *) (INT_PTR) -1 /* IMail::get_cc */ ,
    (void *) (INT_PTR) -1 /* IMail::put_cc */ ,
    (void *) (INT_PTR) -1 /* IMail::get_bcc */ ,
    (void *) (INT_PTR) -1 /* IMail::put_bcc */ ,
    (void *) (INT_PTR) -1 /* IMail::get_subject */ ,
    (void *) (INT_PTR) -1 /* IMail::put_subject */ ,
    (void *) (INT_PTR) -1 /* IMail::get_content */ ,
    (void *) (INT_PTR) -1 /* IMail::get_date */ ,
    (void *) (INT_PTR) -1 /* IMail::put_date */
};


static const PRPC_STUB_FUNCTION IMail_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IMailStubVtbl =
{
    &IID_IMail,
    &IMail_ServerInfo,
    20,
    &IMail_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Standard interface: __MIDL_itf_tmailx_0266, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IOptions, ver. 0.0,
   GUID={0x3278D320,0x60C2,0x43B4,{0xAB,0x95,0xFE,0xAA,0x8A,0x17,0xD6,0x70}} */

#pragma code_seg(".orpc")
static const unsigned short IOptions_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1424,
    1066
    };

static const MIDL_STUBLESS_PROXY_INFO IOptions_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IOptions_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOptions_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IOptions_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IOptionsProxyVtbl = 
{
    &IOptions_ProxyInfo,
    &IID_IOptions,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IOptions::get_item */ ,
    (void *) (INT_PTR) -1 /* IOptions::get_count */
};


static const PRPC_STUB_FUNCTION IOptions_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IOptionsStubVtbl =
{
    &IID_IOptions,
    &IOptions_ServerInfo,
    9,
    &IOptions_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ISmtp, ver. 0.0,
   GUID={0x44A1A6DF,0xEC33,0x430C,{0x99,0xF3,0x5A,0x68,0x57,0xE2,0x04,0x8E}} */

#pragma code_seg(".orpc")
static const unsigned short ISmtp_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1458,
    1504,
    1532,
    1578,
    1606,
    1634,
    1662,
    1690,
    1718,
    1758,
    1798,
    1826,
    1854,
    1882,
    1910,
    1944,
    1978,
    2012
    };

static const MIDL_STUBLESS_PROXY_INFO ISmtp_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ISmtp_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ISmtp_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ISmtp_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(25) _ISmtpProxyVtbl = 
{
    &ISmtp_ProxyInfo,
    &IID_ISmtp,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* ISmtp::contact */ ,
    (void *) (INT_PTR) -1 /* ISmtp::quit */ ,
    (void *) (INT_PTR) -1 /* ISmtp::auth */ ,
    (void *) (INT_PTR) -1 /* ISmtp::get_authTypes */ ,
    (void *) (INT_PTR) -1 /* ISmtp::hello */ ,
    (void *) (INT_PTR) -1 /* ISmtp::starttls */ ,
    (void *) (INT_PTR) -1 /* ISmtp::reset */ ,
    (void *) (INT_PTR) -1 /* ISmtp::noop */ ,
    (void *) (INT_PTR) -1 /* ISmtp::expand */ ,
    (void *) (INT_PTR) -1 /* ISmtp::verify */ ,
    (void *) (INT_PTR) -1 /* ISmtp::get_enable8Bit */ ,
    (void *) (INT_PTR) -1 /* ISmtp::get_enableStartTls */ ,
    (void *) (INT_PTR) -1 /* ISmtp::get_enablePipling */ ,
    (void *) (INT_PTR) -1 /* ISmtp::get_maxMailSize */ ,
    (void *) (INT_PTR) -1 /* ISmtp::mailFrom */ ,
    (void *) (INT_PTR) -1 /* ISmtp::rcptTo */ ,
    (void *) (INT_PTR) -1 /* ISmtp::addressesByMail */ ,
    (void *) (INT_PTR) -1 /* ISmtp::sendMail */
};


static const PRPC_STUB_FUNCTION ISmtp_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ISmtpStubVtbl =
{
    &IID_ISmtp,
    &ISmtp_ServerInfo,
    25,
    &ISmtp_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IPop3, ver. 0.0,
   GUID={0x7DA5678A,0x76A1,0x4278,{0xB2,0x89,0xD4,0xBD,0x95,0xF3,0x86,0x0B}} */

#pragma code_seg(".orpc")
static const unsigned short IPop3_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1458,
    1504,
    1532,
    2046,
    2074,
    2108,
    2142,
    1690,
    2182,
    2216,
    2250,
    1826,
    1854,
    2284,
    2312
    };

static const MIDL_STUBLESS_PROXY_INFO IPop3_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IPop3_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IPop3_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IPop3_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(22) _IPop3ProxyVtbl = 
{
    &IPop3_ProxyInfo,
    &IID_IPop3,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IPop3::contact */ ,
    (void *) (INT_PTR) -1 /* IPop3::quit */ ,
    (void *) (INT_PTR) -1 /* IPop3::auth */ ,
    (void *) (INT_PTR) -1 /* IPop3::capability */ ,
    (void *) (INT_PTR) -1 /* IPop3::list */ ,
    (void *) (INT_PTR) -1 /* IPop3::uidl */ ,
    (void *) (INT_PTR) -1 /* IPop3::stat */ ,
    (void *) (INT_PTR) -1 /* IPop3::starttls */ ,
    (void *) (INT_PTR) -1 /* IPop3::returnMailHeader */ ,
    (void *) (INT_PTR) -1 /* IPop3::returnMail */ ,
    (void *) (INT_PTR) -1 /* IPop3::deleteMail */ ,
    (void *) (INT_PTR) -1 /* IPop3::noop */ ,
    (void *) (INT_PTR) -1 /* IPop3::reset */ ,
    (void *) (INT_PTR) -1 /* IPop3::get_authTypes */ ,
    (void *) (INT_PTR) -1 /* IPop3::get_enableStartTls */
};


static const PRPC_STUB_FUNCTION IPop3_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IPop3StubVtbl =
{
    &IID_IPop3,
    &IPop3_ServerInfo,
    22,
    &IPop3_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x600016e, /* MIDL Version 6.0.366 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0   /* Reserved5 */
    };

const CInterfaceProxyVtbl * _tmailx_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IContentsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHeadersProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOptionsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IContentProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IPop3ProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IMailProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISmtpProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IMessageHeaderProxyVtbl,
    0
};

const CInterfaceStubVtbl * _tmailx_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IContentsStubVtbl,
    ( CInterfaceStubVtbl *) &_IHeadersStubVtbl,
    ( CInterfaceStubVtbl *) &_IOptionsStubVtbl,
    ( CInterfaceStubVtbl *) &_IContentStubVtbl,
    ( CInterfaceStubVtbl *) &_IPop3StubVtbl,
    ( CInterfaceStubVtbl *) &_IMailStubVtbl,
    ( CInterfaceStubVtbl *) &_ISmtpStubVtbl,
    ( CInterfaceStubVtbl *) &_IMessageHeaderStubVtbl,
    0
};

PCInterfaceName const _tmailx_InterfaceNamesList[] = 
{
    "IContents",
    "IHeaders",
    "IOptions",
    "IContent",
    "IPop3",
    "IMail",
    "ISmtp",
    "IMessageHeader",
    0
};

const IID *  _tmailx_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _tmailx_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _tmailx, pIID, n)

int __stdcall _tmailx_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _tmailx, 8, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _tmailx, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _tmailx, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _tmailx, 8, *pIndex )
    
}

const ExtendedProxyFileInfo tmailx_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _tmailx_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _tmailx_StubVtblList,
    (const PCInterfaceName * ) & _tmailx_InterfaceNamesList,
    (const IID ** ) & _tmailx_BaseIIDList,
    & _tmailx_IID_Lookup, 
    8,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

