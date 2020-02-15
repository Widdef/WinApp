#include "gameWindow.h"


void GameWindow(HWND hWnd, bool& runningMenu)
{
	LPCWSTR gameName = GAME_NAME.c_str();
	RECT rc;
	GetWindowRect(hWnd, &rc);
	int wHeight = rc.bottom - rc.top;
	int halfWHeight = wHeight / 2;
	int wWidth = rc.right - rc.left;
	int halfWWidth = wWidth / 2;
	CreateWindowExW(WS_EX_ACCEPTFILES,L"static",gameName,
		WS_VISIBLE | WS_CHILD | SS_CENTER,
		halfWWidth-100, halfWHeight-250,
		200,100,
		hWnd,NULL,NULL,NULL);
	const auto waitDuration = std::chrono::milliseconds(WAIT_TIME);
	while (runningMenu)
	{
		std::this_thread::sleep_for(waitDuration);
	}
}