#include "GDI_Renderer.h"

namespace Sumomo2::Render 
{
	HRESULT GDI_Renderer::Initialize()
	{
		return S_OK;
	}

	void GDI_Renderer::Render(HWND hWnd)
	{
		PAINTSTRUCT paintStruct;
		HDC hdc = BeginPaint(hWnd,&paintStruct);
		// do something
		RECT rect;
		GetClientRect(hWnd, &rect);
		DrawText(hdc, TEXT("This is a skeleton application!"), -1, &rect,
			DT_SINGLELINE | DT_CENTER | DT_VCENTER);

		EndPaint(hWnd, &paintStruct);
	}

	void GDI_Renderer::Cleanup()
	{

	}
}