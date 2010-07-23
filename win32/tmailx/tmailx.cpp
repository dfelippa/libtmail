// TMailCom.cpp : DLL 导出的实现。


#include "stdafx.h"
#include "resource.h"
#include "tmailx.h"
#include "dlldatax.h"
#include <locale.h>


class CTMailModule : public CAtlDllModuleT< CTMailModule >
{
public :
	DECLARE_LIBID(LIBID_TMail)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_TMAILCOM, "{73DBFA87-ABEE-4F9C-A6A1-3DA78960A5CC}")
};

CTMailModule _AtlModule;


#ifdef _MANAGED
#pragma managed(push, off)
#endif

// DLL 入口点
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
#ifdef _MERGE_PROXYSTUB
    if (!PrxDllMain(hInstance, dwReason, lpReserved))
        return FALSE;
#endif
	hInstance;
	setlocale(LC_ALL, "");
    return _AtlModule.DllMain(dwReason, lpReserved); 
}

#ifdef _MANAGED
#pragma managed(pop)
#endif




// 用于确定 DLL 是否可由 OLE 卸载
STDAPI DllCanUnloadNow(void)
{
#ifdef _MERGE_PROXYSTUB
    HRESULT hr = PrxDllCanUnloadNow();
    if (hr != S_OK)
        return hr;
#endif
    return _AtlModule.DllCanUnloadNow();
}


// 返回一个类工厂以创建所请求类型的对象
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
#ifdef _MERGE_PROXYSTUB
    if (PrxDllGetClassObject(rclsid, riid, ppv) == S_OK)
        return S_OK;
#endif
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - 将项添加到系统注册表
STDAPI DllRegisterServer(void)
{
    // 注册对象、类型库和类型库中的所有接口
    HRESULT hr = _AtlModule.DllRegisterServer();
#ifdef _MERGE_PROXYSTUB
    if (FAILED(hr))
        return hr;
    hr = PrxDllRegisterServer();
#endif
	return hr;
}


// DllUnregisterServer - 将项从系统注册表中移除
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer();
#ifdef _MERGE_PROXYSTUB
    if (FAILED(hr))
        return hr;
    hr = PrxDllRegisterServer();
    if (FAILED(hr))
        return hr;
    hr = PrxDllUnregisterServer();
#endif
	return hr;
}

void set_error(const BSTR strDescription, const BSTR strSource)
{
	ICreateErrorInfo *pcerrinfo;
	IErrorInfo *perrinfo;
	HRESULT hr = CreateErrorInfo(&pcerrinfo);
	if(strSource)
	{
		pcerrinfo->SetSource(strSource);
	}
	pcerrinfo->SetDescription(strDescription);
	hr = pcerrinfo->QueryInterface(IID_IErrorInfo, (LPVOID FAR*) &perrinfo);
	if (SUCCEEDED(hr))
	{
		SetErrorInfo(0, perrinfo);
		perrinfo->Release();
	}
	pcerrinfo->Release();
}

SAFEARRAY* variant_to_safearray(VARIANT* var)
{
	if (var->vt & VT_ARRAY)
	{
		if (var->vt & VT_BYREF)
			return *var->pparray;
		else
			return var->parray;
	}
	else if (var->vt == (VT_VARIANT | VT_BYREF))
	{
		return variant_to_safearray(var->pvarVal);
	}
	else
		return 0;
}

BSTR variant_to_bstr(VARIANT* var)
{
	if (var->vt == VT_BSTR)
	{
		return var->bstrVal;
	}
	else if (var->vt == (VT_BSTR | VT_BYREF))
	{
		return *var->pbstrVal;
	}
	else if (var->vt == (VT_VARIANT | VT_BYREF))
	{
		return variant_to_bstr(var->pvarVal);
	}
	else
		return 0;
}


HRESULT get_strings_by_variant(VARIANT* var, std::vector<std::wstring>& vec)
{
	SAFEARRAY* safe_array = variant_to_safearray(var);
	if (safe_array)
	{
		VARTYPE tp = VT_EMPTY;
		HRESULT hr = SafeArrayGetVartype(safe_array, &tp);
		if (FAILED(hr))
			return hr;
		if (tp == VT_BSTR)
		{
			BSTR* str_array = 0;
			hr = SafeArrayAccessData(safe_array, (void**)&str_array);
			if (FAILED(hr))
				return hr;
			for (unsigned long i = 0; i < safe_array->rgsabound[0].cElements; i++)
				vec.push_back(str_array[i]);
			SafeArrayUnaccessData(safe_array);
		}
		else if (tp == VT_VARIANT)
		{
			VARIANT* var_array = 0;
			hr = SafeArrayAccessData(safe_array, (void**)&var_array);
			if (FAILED(hr))
				return hr;
			for (unsigned long i = 0; i < safe_array->rgsabound[0].cElements; i++)
			{
				BSTR bstr = variant_to_bstr(&var_array[i]);
				if (bstr)
					vec.push_back(bstr);
			}
			SafeArrayUnaccessData(safe_array);
		}
	}
	else
	{
		BSTR bstr = variant_to_bstr(var);
		if (bstr)
			vec.push_back(bstr);
	}
	return S_OK;
}