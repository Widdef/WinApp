#include "upperMenu.h"
#include "definedValues.h"

void AddMenus(HWND hWnd)
{
	HMENU hMenu = CreateMenu();
	HMENU hFileMenu = CreateMenu();

	AppendMenu(hFileMenu, MF_STRING, MENU_FILE_SAVE, "Menu");
	AppendMenu(hFileMenu, MF_STRING, MENU_FILE_SAVE, "Save");
	AppendMenu(hFileMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hFileMenu, MF_STRING, MENU_FILE_EXIT, "Exit");

	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "File");
	SetMenu(hWnd, hMenu);
}