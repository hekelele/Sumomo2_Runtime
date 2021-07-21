#pragma once
#include "Framework.h"

namespace Sumomo2::Render {
	class SumomoRenderer
	{
	public:
		virtual bool Initialize(HWND hWnd) = 0;
		virtual void Render() = 0;
		virtual void Terminate() = 0;
	protected:
		virtual bool CreateResources() = 0;
		virtual void ReleaseResources() = 0;

		HWND m_hWnd;
	};
}



