#include <Sumomo2.h>

int WINAPI WinMain(HINSTANCE  hInstance, HINSTANCE  hPrevInstance, LPSTR  lpCmdLine, int  nCmdShow)
{
	SumomoGame game(hInstance);

	if (SUCCEEDED(game.Initialize()))
	{
		game.Run();
	}

	return 0;
}