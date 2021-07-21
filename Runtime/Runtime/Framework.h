#pragma once

#include <Windows.h>
#include <math.h>


#define FAILED(hr) (((HRESULT)(hr)) < 0)
#define SUCCEED(hr) (((HRESULT)(hr)) >= 0)
#define FAIL_RETURN(hr) if(((HRESULT)(hr)) < 0) return hr
#define BOOL_TO_HR(bo) bo?S_OK:E_FAIL

template<class Interface>
inline void SafeRelease(
	Interface **ppInterfaceToRelease
)
{
	if (*ppInterfaceToRelease != NULL)
	{
		(*ppInterfaceToRelease)->Release();

		(*ppInterfaceToRelease) = NULL;
	}
}
