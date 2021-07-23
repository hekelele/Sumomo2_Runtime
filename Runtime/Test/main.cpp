#include <Sumomo2.h>
#include <D3D_FreeCanvas.h>
#include <iostream>
#include <D3D_Framework.h>
#include <D3D_Renderer.h>

using namespace std;
using namespace Sumomo2::Render::D3D;

struct Vertex
{
	XMFLOAT3 pos;
};

class  MyD3dCanvas: public D3D_FreeCanvas
{
public:
	 MyD3dCanvas();
	~ MyD3dCanvas();

private:
	void Render();
	bool CreateResources();
	void ReleaseResources();

	ID3D11VertexShader* m_pVSGreenColor;
	ID3D11PixelShader* m_pPSGreenColor;
	ID3D11InputLayout* m_pInputLayout;
	ID3D11Buffer* m_pVertexBuffer;
};

 MyD3dCanvas:: MyD3dCanvas()
{
	 m_pVSGreenColor = NULL;
	 m_pPSGreenColor = NULL;
	 m_pInputLayout = NULL;
	 m_pVertexBuffer = NULL;
}

 MyD3dCanvas::~ MyD3dCanvas()
{
}

 void MyD3dCanvas::Render()
 {
	 // Check if D3D is ready
	 if (m_Context == NULL)
		 return;

	 // Clear back buffer
	 float color[4] = { 0.0f, 0.0f, 0.5f, 1.0f };
	 m_Context->ClearRenderTargetView(m_RenterTargetView, color);


	 // Stride and offset
	 UINT stride = sizeof(Vertex);
	 UINT offset = 0;

	 // Set vertex buffer
	 m_Context->IASetInputLayout(m_pInputLayout);
	 m_Context->IASetVertexBuffers(0, 1, &m_pVertexBuffer, &stride, &offset);
	 m_Context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	 // Set shaders
	 m_Context->VSSetShader(m_pVSGreenColor, 0, 0);
	 m_Context->PSSetShader(m_pPSGreenColor, 0, 0);

	 // Draw triangle
	 m_Context->Draw(3, 0);


	 // Present back buffer to display
	 m_SwapChain->Present(0, 0);
 }

 bool MyD3dCanvas::CreateResources()
 {
	 // Compile vertex shader
	 ID3DBlob* pVSBuffer = NULL;
	 bool res = D3D_Renderer::CompileShader(L"ShaderGreenColor.fx", "VS_Main", "vs_4_0", &pVSBuffer);
	 if (res == false) {
		 ::MessageBox(NULL, L"Unable to load vertex shader", L"ERROR", MB_OK);
		 return false;
	 }

	 // Create vertex shader
	 HRESULT hr;
	 hr = m_Device->CreateVertexShader(
		 pVSBuffer->GetBufferPointer(),
		 pVSBuffer->GetBufferSize(),
		 0, &m_pVSGreenColor);
	 if (FAILED(hr)) {
		 if (pVSBuffer)
			 pVSBuffer->Release();
		 return false;
	 }

	 // Define input layout
	 D3D11_INPUT_ELEMENT_DESC shaderInputLayout[] =
	 {
		 { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	 };
	 UINT numLayoutElements = ARRAYSIZE(shaderInputLayout);

	 // Create input layout
	 hr = m_Device->CreateInputLayout(
		 shaderInputLayout, numLayoutElements,
		 pVSBuffer->GetBufferPointer(),
		 pVSBuffer->GetBufferSize(),
		 &m_pInputLayout);
	 if (FAILED(hr)) {
		 return false;
	 }

	 // Release VS buffer
	 pVSBuffer->Release();
	 pVSBuffer = NULL;

	 // Compile pixel shader
	 ID3DBlob* pPSBuffer = NULL;
	 res = D3D_Renderer::CompileShader(L"ShaderGreenColor.fx", "PS_Main", "ps_4_0", &pPSBuffer);
	 if (res == false) {
		 ::MessageBox(m_hWnd, L"Unable to load pixel shader", L"ERROR", MB_OK);
		 return false;
	 }

	 // Create pixel shader
	 hr = m_Device->CreatePixelShader(
		 pPSBuffer->GetBufferPointer(),
		 pPSBuffer->GetBufferSize(),
		 0, &m_pPSGreenColor);
	 if (FAILED(hr)) {
		 return false;
	 }

	 // Cleanup PS buffer
	 pPSBuffer->Release();
	 pPSBuffer = NULL;

	 // Define triangle
	 Vertex vertices[] =
	 {
		 XMFLOAT3(0.0f,  0.5f, 0.5f),
		 XMFLOAT3(0.5f, -0.5f, 0.5f),
		 XMFLOAT3(-0.5f, -0.5f, 0.5f)
	 };

	 // Vertex description
	 D3D11_BUFFER_DESC vertexDesc;
	 ::ZeroMemory(&vertexDesc, sizeof(vertexDesc));
	 vertexDesc.Usage = D3D11_USAGE_DEFAULT;
	 vertexDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	 vertexDesc.ByteWidth = sizeof(Vertex) * 3;

	 // Resource data
	 D3D11_SUBRESOURCE_DATA resourceData;
	 ZeroMemory(&resourceData, sizeof(resourceData));
	 resourceData.pSysMem = vertices;

	 // Create vertex buffer
	 hr = m_Device->CreateBuffer(&vertexDesc, &resourceData, &m_pVertexBuffer);
	 if (FAILED(hr)) {
		 return false;
	 }

	 return true;
 }

 void MyD3dCanvas::ReleaseResources()
 {
 }


int APIENTRY WinMain(HINSTANCE  hInstance, HINSTANCE  hPrevInstance, LPSTR  lpCmdLine, int  nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	
	SumomoGame game(hInstance);

	if (SUCCEEDED(game.Initialize()))
	{
		game.Add_D3D_Canvas((D3D_FreeCanvas*)(new MyD3dCanvas()));
		game.Run();
	}

	game.Shutdown();

	return 0;
}