#pragma once
#include "SumomoRenderer.h"
#include <vector>

namespace Sumomo2::Render::GDI
{
	class GDI_FreeCanvas;
	class GDI_Renderer: virtual public SumomoRenderer
	{
	public:
		HRESULT Initialize();
		void Render(HWND hWnd);
		void Cleanup();

		void AddCanvas(GDI_FreeCanvas* canvas);

	private:
		HWND m_hWnd;
		std::vector<GDI_FreeCanvas*> m_CanvasList;
	};
}
