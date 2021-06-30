#pragma once
#include "SumomoRenderer.h"

namespace Sumomo2::Render 
{
	class GDI_Renderer: virtual public SumomoRenderer
	{
	public:
		HRESULT Initialize();
		void Render(HWND hWnd);
		void Cleanup();
	private:
		HWND m_hWnd;
	};
}
