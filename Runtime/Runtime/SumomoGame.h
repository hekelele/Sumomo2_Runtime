#pragma once
#include "Framework.h"

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

		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		void Update();
	};
}


