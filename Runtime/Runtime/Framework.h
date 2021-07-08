#pragma once

#include <Windows.h>
#include <math.h>


#define FAILED(hr) (((HRESULT)(hr)) < 0)
#define FAIL_RETURN(hr) if(((HRESULT)(hr)) < 0) return hr