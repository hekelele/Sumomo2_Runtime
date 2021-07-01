#pragma once
#include <Windows.h>

namespace Sumomo2::Render {
	struct Color{
		BYTE r;
		BYTE g;
		BYTE b;
		BYTE a;

		Color(BYTE _r, BYTE _g, BYTE _b, BYTE _a) {
			this->r = _r;
			this->g = _g;
			this->b = _b;
			this->a = _a;
		}

		Color(BYTE _r, BYTE _g, BYTE _b) {
			this->r = _r;
			this->g = _g;
			this->b = _b;
			this->a = 255;
		}

		Color(BYTE _c) {
			this->r = _c;
			this->g = _c;
			this->b = _c;
			this->a = 255;
		}

		Color() {
			this->r = 0;
			this->g = 0;
			this->b = 0;
			this->a = 255;
		}

		static const Color White;
	};
}