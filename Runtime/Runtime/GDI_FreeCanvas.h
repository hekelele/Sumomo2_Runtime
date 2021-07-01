#pragma once
#include "Framework.h"

namespace Sumomo2::Render::GDI {
	class GDI_FreeCanvas
	{
	public:
		GDI_FreeCanvas();
		virtual ~GDI_FreeCanvas();

		virtual void Draw(HDC hdc) = 0;
	};
}


