#include "D3D_FreeCanvas.h"
#include "D3D_Renderer.h"

namespace Sumomo2::Render::D3D {
	void D3D_FreeCanvas::SetRendererInfo(HWND _Hwnd, ID3D11DeviceContext * _Context,
		ID3D11Device*		_Device,ID3D11RenderTargetView * _RenderTargetView,
		IDXGISwapChain * _SwapChain)
	{
		m_hWnd = _Hwnd;
		m_Device = _Device;
		m_Context = _Context;
		m_RenterTargetView = _RenderTargetView;
		m_SwapChain = _SwapChain;
	}
}