#include "SumomoGame.h"
#include "Sumomo2.h"

using namespace Sumomo2::Render;

namespace Sumomo2::Core {
	SumomoGame::SumomoGame(HINSTANCE hInstance)
		:m_hWnd(NULL), m_hInstance(hInstance)
	{
	}

	SumomoGame::~SumomoGame()
	{
	}

	HRESULT SumomoGame::Initialize()
	{
		FAIL_RETURN(CheckGameInstance());
		FAIL_RETURN(RegisterGameWindow());
		FAIL_RETURN(CreateGameWindow());
		FAIL_RETURN(InitializeSubSystems());
		ShowGameWindow();

		return S_OK;
	}
	void SumomoGame::Run()
	{
		MSG msg = { 0 };
		while (msg.message != WM_QUIT) {
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				Update();
				Render();
			}
		}
	}

	void SumomoGame::Shutdown()
	{
		UnregisterClass(L"SumomoWndClass", m_hInstance);
	}

	void SumomoGame::Add_D3D_Canvas(Sumomo2::Render::D3D::D3D_FreeCanvas * canvas)
	{
		m_Renderer.AddCanvas(canvas);
	}
	
	/*
	void SumomoGame::AddGDI_Canvas(Sumomo2::Render::GDI::GDI_FreeCanvas* canvas)
	{
		//m_Renderer.AddCanvas(canvas);
	}
	*/

	HRESULT SumomoGame::CheckGameInstance()
	{
		if (Sumomo2::Global::Game == NULL) {
			Sumomo2::Global::Game = this;
			return S_OK;
		}
		else
		{
			return E_FAIL;
		}
	}


	HRESULT SumomoGame::RegisterGameWindow()
	{
		WNDCLASSEX wcex = { 0 };
		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = SumomoGame::WndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = m_hInstance;
		wcex.hIcon = NULL;
		wcex.hCursor = LoadCursor(NULL, IDI_APPLICATION);
		wcex.hbrBackground = NULL;
		wcex.lpszMenuName = NULL;
		wcex.lpszClassName = L"SumomoWndClass";

		// If Register Failed
		if (!RegisterClassEx(&wcex)) {
			return E_FAIL;
		}

		return S_OK;
	}

	HRESULT SumomoGame::CreateGameWindow()
	{
		m_hWnd = CreateWindow(
			L"SumomoWndClass",
			L"Sumomo Game",
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			640,				// window width
			480,				// window height
			NULL,
			NULL,
			m_hInstance,
			NULL);


		return m_hWnd ? S_OK : E_FAIL;
	}

	HRESULT SumomoGame::InitializeSubSystems()
	{
		bool bo = m_Renderer.Initialize(m_hWnd);
		return BOOL_TO_HR(bo);
	}

	void SumomoGame::ShowGameWindow()
	{
		ShowWindow(m_hWnd, SW_SHOWNORMAL);
		UpdateWindow(m_hWnd);
	}

	LRESULT SumomoGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
		case WM_PAINT:
			Sumomo2::Global::Game->Render();
			ValidateRect(hWnd,NULL);
			break;
		case WM_KEYDOWN:
			if (wParam == VK_ESCAPE) {
				DestroyWindow(hWnd);
			}
			break;

		case WM_DESTROY:
			Sumomo2::Global::Game->Cleanup();
			PostQuitMessage(0);
			break;

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}

		return 0;
	}

	void SumomoGame::Render()
	{
		m_Renderer.Render();
	}

	void SumomoGame::Update()
	{
	}

	void SumomoGame::Cleanup()
	{
		m_Renderer.Terminate();
		Sumomo2::Global::Game = NULL;
	}
}