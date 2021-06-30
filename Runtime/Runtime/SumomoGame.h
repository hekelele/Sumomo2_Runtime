#pragma once
#include "Framework.h"
#include "GDI_Renderer.h"

namespace Sumomo2::Core {
	class SumomoGame
	{
	public:
		SumomoGame(HINSTANCE hInstance);
		~SumomoGame();

		HRESULT Initialize();
		void Run();
		void Shutdown();

	private:
		HWND m_hWnd;
		HINSTANCE m_hInstance;

		Sumomo2::Render::GDI_Renderer m_Renderer;

		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		void Render();
		void Update();

		void Cleanup();
	};
}


