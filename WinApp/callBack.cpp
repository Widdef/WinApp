#include "callBack.h"
#include "upperMenu.h"
#include "gameWindow.h"
#include "callbackThreads.h"


LRESULT CALLBACK WindowProcessMessages(HWND hWnd, UINT msg, WPARAM param, LPARAM lparam)
{
	switch (msg)
	{
	case WM_COMMAND:
		switch (param)
		{
		case MENU_FILE_SAVE:
			break;
		case MENU_FILE_MENU:
			MessageBox(NULL, "HELLO WORLD", "Moje okno", MB_OK);
			break;
		case MENU_FILE_EXIT:
			DestroyWindow(hWnd);
			break;
		}
		break;
	case WM_CREATE:
		menuThread = new std::thread(AddMenus,hWnd);
		windowThread = new std::thread(GameWindow,hWnd,gameScreenThread);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd, msg, param, lparam);
	}
}