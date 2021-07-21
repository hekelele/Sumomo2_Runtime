#include "GDI_Renderer.h"
#include "GDI_FreeCanvas.h"

namespace Sumomo2::Render::GDI
{
	bool GDI_Renderer::Initialize(HWND hWnd)
	{
		m_hWnd = hWnd;
		return m_hWnd != NULL;
	}

	void GDI_Renderer::Render()
	{
		PAINTSTRUCT paintStruct;
		HDC hdc = BeginPaint(m_hWnd, &paintStruct);

		for (unsigned int i = 0; i < m_CanvasList.size(); i++) {
			this->m_CanvasList[i]->Draw(hdc);
		}

		EndPaint(m_hWnd, &paintStruct);
	}

	void GDI_Renderer::Terminate()
	{
	}

	void GDI_Renderer::AddCanvas(GDI_FreeCanvas * canvas)
	{
		m_CanvasList.push_back(canvas);
	}

	bool GDI_Renderer::CreateResources()
	{
		return true;
	}

	void GDI_Renderer::ReleaseResources()
	{
	}
}