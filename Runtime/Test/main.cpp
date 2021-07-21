#include <Sumomo2.h>
#include <iostream>
#include <GDI_FreeCanvas.h>
using namespace std;
using namespace Sumomo2::Render::D3D;

class  MyD3dCanvas: public D3D_FreeCanvas
{
public:
	 MyD3dCanvas();
	~ MyD3dCanvas();

private:
	void Render(ID3D11DeviceContext*	m_Context,
		ID3D11RenderTargetView* m_RenterTargetView,
		IDXGISwapChain*			m_SwapChain);
};

 MyD3dCanvas:: MyD3dCanvas()
{
}

 MyD3dCanvas::~ MyD3dCanvas()
{
}

 void MyD3dCanvas::Render(ID3D11DeviceContext * m_Context, ID3D11RenderTargetView * m_RenterTargetView, IDXGISwapChain * m_SwapChain)
 {
	 // Check if D3D is ready
	 if (m_Context == NULL)
		 return;

	 // Clear back buffer
	 float color[4] = { 0.0f, 0.0f, 0.5f, 1.0f };
	 m_Context->ClearRenderTargetView(m_RenterTargetView, color);

	 // Present back buffer to display
	 m_SwapChain->Present(0, 0);
 }


int APIENTRY WinMain(HINSTANCE  hInstance, HINSTANCE  hPrevInstance, LPSTR  lpCmdLine, int  nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	SumomoGame game(hInstance);
	game.Add_D3D_Canvas((D3D_FreeCanvas*)(new MyD3dCanvas()));
		/*
#ifndef NDEBUG
#endif
	}*/

	if (SUCCEEDED(game.Initialize()))
	{
		game.Run();
	}
	return 0;
}