#pragma once
#include "D3D_Framework.h"
#include "D3D_FreeCanvas.h"

namespace Sumomo2::Render::D3D {
	class D3D_Renderer: virtual public SumomoRenderer
	{
	public:
		D3D_Renderer();
		virtual ~D3D_Renderer();
		bool Initialize(HWND hWnd);
		void Render();
		void Terminate();
		void AddCanvas(D3D_FreeCanvas* canvas);
		static bool CompileShader(LPCWSTR szFilePath, LPCSTR szFunc, LPCSTR szShaderModel, ID3DBlob** buffer);
	protected:
		bool CreateResources();
		void ReleaseResources();
	private:
		ID3D11Device*			m_Device;
		ID3D11DeviceContext*	m_Context;
		ID3D11RenderTargetView* m_RenterTargetView;
		IDXGISwapChain*			m_SwapChain;

		std::vector<D3D_FreeCanvas*> m_CanvasList;
	};

}


