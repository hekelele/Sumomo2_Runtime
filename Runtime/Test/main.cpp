#include <Sumomo2.h>
#include <iostream>
using namespace std;

int WINAPI WinMain(HINSTANCE  hInstance, HINSTANCE  hPrevInstance, LPSTR  lpCmdLine, int  nCmdShow)
{
	SumomoGame game(hInstance);
	
	for (int i = 0; i < 10; i++) {
		float a = RandomRange(0, 100);
#ifndef NDEBUG
		std::cout << a << std::endl;
#endif
	}
	


	

	if (SUCCEEDED(game.Initialize()))
	{
		game.Run();
	}
	return 0;
}