#pragma once
#include "SumomoRenderer.h"
#include <vector>

namespace Sumomo2::Render::GDI
{
	class GDI_FreeCanvas;
	class GDI_Renderer: virtual public SumomoRenderer
	{
	public:
		bool Initialize(HWND hWnd);
		void Render();
		void Terminate();

		void AddCanvas(GDI_FreeCanvas* canvas);
	protected:
		bool CreateResources();
		void ReleaseResources();

	private:
		std::vector<GDI_FreeCanvas*> m_CanvasList;
	};
}
