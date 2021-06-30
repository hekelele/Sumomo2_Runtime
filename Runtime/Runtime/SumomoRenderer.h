#pragma once
#include "Framework.h"

namespace Sumomo2::Render {
	class SumomoRenderer
	{
	public:
		virtual HRESULT Initialize() = 0;
		virtual void Render(HWND hWnd) = 0;
		virtual void Cleanup() = 0;
	};
}



