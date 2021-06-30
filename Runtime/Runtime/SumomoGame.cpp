﻿#include "SumomoGame.h"
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
		if (Sumomo2::Global::Game == NULL) {
			Sumomo2::Global::Game = this;
		}
		else
		{
			return E_FAIL;
		}

		HRESULT hr = S_OK;

		hr = m_Renderer.Initialize();

		if (SUCCEEDED(hr))
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

			hr = m_hWnd ? S_OK : E_FAIL;

			if (SUCCEEDED(hr))
			{
				ShowWindow(m_hWnd, SW_SHOWNORMAL);
				UpdateWindow(m_hWnd);
			}
		}

		return hr;
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
		m_Renderer.Render(m_hWnd);
	}

	void SumomoGame::Update()
	{
	}

	void SumomoGame::Cleanup()
	{
		Sumomo2::Global::Game = NULL;
	}
}