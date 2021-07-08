#pragma once
#include "Framework.h"

namespace Sumomo2::Render {
	class SumomoRenderer
	{
	public:
		virtual HRESULT Initialize(HWND hWnd) = 0;
		virtual void Render() = 0;
		virtual void Terminate() = 0;
	protected:
		virtual void CreateResources() = 0;
		virtual void ReleaseResources() = 0;

		HWND m_hWnd;
	};
}



