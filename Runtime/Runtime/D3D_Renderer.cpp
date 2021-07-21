#include "D3D_Renderer.h"


namespace Sumomo2::Render::D3D {
	D3D_Renderer::D3D_Renderer()
	{
		m_hWnd = NULL;
		m_Device = NULL;
		m_Context = NULL;
		m_RenterTargetView = NULL;
		m_SwapChain = NULL;
	}
	
	D3D_Renderer::~D3D_Renderer()
	{
	}

	bool D3D_Renderer::Initialize(HWND hWnd)
	{
		m_hWnd = hWnd;
		RECT rc;
		::GetClientRect(hWnd, &rc);
		UINT nWidth = rc.right - rc.left;
		UINT nHeight = rc.bottom - rc.top;

		// Swap chain structure
		DXGI_SWAP_CHAIN_DESC swapChainDesc;
		::ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
		swapChainDesc.BufferCount = 1;
		swapChainDesc.BufferDesc.Width = nWidth;
		swapChainDesc.BufferDesc.Height = nHeight;
		swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
		swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.OutputWindow = (HWND)hWnd;
		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.SampleDesc.Quality = 0;
		swapChainDesc.Windowed = true;

		// Supported feature levels
		D3D_FEATURE_LEVEL featureLevel;
		D3D_FEATURE_LEVEL featureLevels[] =
		{
			D3D_FEATURE_LEVEL_11_0,
			D3D_FEATURE_LEVEL_10_1,
			D3D_FEATURE_LEVEL_10_0
		};
		UINT numFeatureLevels = ARRAYSIZE(featureLevels);

		// Supported driver levels
		D3D_DRIVER_TYPE driverTypes[] =
		{
			D3D_DRIVER_TYPE_HARDWARE, D3D_DRIVER_TYPE_WARP,
			D3D_DRIVER_TYPE_REFERENCE, D3D_DRIVER_TYPE_SOFTWARE
		};
		UINT numDriverTypes = ARRAYSIZE(driverTypes);

		// Flags
		UINT flags = 0;

#ifndef NDEBUG
		flags = D3D11_CREATE_DEVICE_DEBUG;
#endif // !NDEBUG

		// Create the D3D device and the swap chain
		HRESULT hr = ::D3D11CreateDeviceAndSwapChain(
			NULL,
			D3D_DRIVER_TYPE_HARDWARE,
			NULL,
			flags,
			featureLevels,
			numFeatureLevels,
			D3D11_SDK_VERSION,
			&swapChainDesc,
			&m_SwapChain,
			&m_Device,
			&featureLevel,
			&m_Context
		);

		// Check device
		if (FAILED(hr)) {
			MessageBox(hWnd, TEXT("A DX11 Video Card is Required"), TEXT("ERROR"), MB_OK);
			return false;
		}

		// Get the back buffer from the swapchain
		ID3D11Texture2D *pBackBuffer;
		hr = m_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
		if (FAILED(hr)) {
			MessageBox(hWnd, TEXT("Unable to get back buffer"), TEXT("ERROR"), MB_OK);
			return false;
		}

		// Create the render target view
		hr = m_Device->CreateRenderTargetView(pBackBuffer, NULL, &m_RenterTargetView);

		// Release the back buffer
		if (pBackBuffer != NULL)
			pBackBuffer->Release();

		// Check render target view
		if (FAILED(hr)) {
			MessageBox(hWnd, TEXT("Unable to create render target view"), TEXT("ERROR"), MB_OK);
			return false;
		}

		// Set the render target
		m_Context->OMSetRenderTargets(1, &m_RenterTargetView, NULL);

		// Set the viewport
		D3D11_VIEWPORT viewPort;
		viewPort.Width = (float)nWidth;
		viewPort.Height = (float)nHeight;
		viewPort.MinDepth = 0.0f;
		viewPort.MaxDepth = 1.0f;
		viewPort.TopLeftX = 0;
		viewPort.TopLeftY = 0;
		m_Context->RSSetViewports(1, &viewPort);

		return CreateResources();
	}

	void D3D_Renderer::Render()
	{
		for (unsigned int i = 0; i < m_CanvasList.size(); i++) {
			this->m_CanvasList[i]->Render(m_Context, m_RenterTargetView, m_SwapChain);
		}
	}

	void D3D_Renderer::Terminate()
	{
		ReleaseResources();
		
		SafeRelease(&m_RenterTargetView);
		SafeRelease(&m_SwapChain);
		SafeRelease(&m_Context);
		SafeRelease(&m_Device);
	}

	void D3D_Renderer::AddCanvas(D3D_FreeCanvas * canvas)
	{
		m_CanvasList.push_back(canvas);
	}

	bool D3D_Renderer::CreateResources()
	{
		return true;
	}

	void D3D_Renderer::ReleaseResources()
	{
	}
}