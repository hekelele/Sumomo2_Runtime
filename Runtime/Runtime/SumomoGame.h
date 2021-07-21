#pragma once
#include "Framework.h"
#include "GDI_Renderer.h"
#include "D3D_Renderer.h"

namespace Sumomo2::Core {
	class SumomoGame
	{
	public:
		SumomoGame(HINSTANCE hInstance);
		~SumomoGame();

		HRESULT Initialize();
		void Run();
		void Shutdown();

		void Add_D3D_Canvas(Sumomo2::Render::D3D::D3D_FreeCanvas* canvas);

	private:
		HWND m_hWnd;
		HINSTANCE m_hInstance;

		//Sumomo2::Render::GDI::GDI_Renderer m_Renderer;
		Sumomo2::Render::D3D::D3D_Renderer m_Renderer;

		HRESULT CheckGameInstance();
		HRESULT RegisterGameWindow();
		HRESULT CreateGameWindow();
		HRESULT InitializeSubSystems();
		void    ShowGameWindow();

		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		void Render();
		void Update();
		void Cleanup();
	};
}


