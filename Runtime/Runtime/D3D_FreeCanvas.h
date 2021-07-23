#pragma once
#include "D3D_Framework.h"

namespace Sumomo2::Render::D3D {
	class D3D_FreeCanvas
	{
	public:
		virtual void Render() = 0;
		virtual bool CreateResources() = 0;
		virtual void ReleaseResources() = 0;

	protected:
		HWND					m_hWnd;
		ID3D11Device*			m_Device;
		ID3D11DeviceContext *   m_Context;
		ID3D11RenderTargetView* m_RenterTargetView;
		IDXGISwapChain*			m_SwapChain;

	private:
		void SetRendererInfo(HWND _Hwnd,
			ID3D11DeviceContext * _Context,
			ID3D11Device*		_Device,
			ID3D11RenderTargetView * _RenderTargetView,
			IDXGISwapChain * _SwapChain);
		friend class D3D_Renderer;
	};
}

