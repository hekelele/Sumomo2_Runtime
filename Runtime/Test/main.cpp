#include <Sumomo2.h>
#include <iostream>
#include <GDI_FreeCanvas.h>
using namespace std;
using namespace Sumomo2::Render::GDI;

class  MyCanvas: public GDI_FreeCanvas
{
public:
	void Draw(HDC hdc) {
		HPEN gPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
		SelectObject(hdc, gPen);
		MoveToEx(hdc, 20, 20, NULL);
		LineTo(hdc, 100, 100);
		LineTo(hdc, 400, 20);
		LineTo(hdc, 20, 20);
		DeleteObject(gPen);
	}
};



int APIENTRY WinMain(HINSTANCE  hInstance, HINSTANCE  hPrevInstance, LPSTR  lpCmdLine, int  nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	SumomoGame game(hInstance);
	game.AddGDI_Canvas(new MyCanvas());
	
		/*
#ifndef NDEBUG
#endif
	}*/

	if (SUCCEEDED(game.Initialize()))
	{
		game.Run();
	}
	return 0;
}