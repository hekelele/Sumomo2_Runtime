#pragma once
#include "D3D_Framework.h"

namespace Sumomo2::Render::D3D {
	class D3D_FreeCanvas
	{
	public:
		virtual void Render(ID3D11DeviceContext*	m_Context,
			ID3D11RenderTargetView* m_RenterTargetView,
			IDXGISwapChain*			m_SwapChain);
	};
}

