#pragma once
#include "SumomoRenderer.h"
#include <D3D11.h>
#include <D3DX11.h>
#include <DxErr.h>


namespace Sumomo2::Render::D3D {
	class D3D_Renderer
	{
	public:
		HRESULT Initialize(HWND hWnd);
		void Render();
		void Terminate();
	protected:
		void CreateResources();
		void ReleaseResources();
	};

}


