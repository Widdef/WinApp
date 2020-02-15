#include "upperMenu.h"

void AddMenus(HWND hWnd)
{
	HMENU hMenu = CreateMenu();
	HMENU hFileMenu = CreateMenu();
	HMENU hSettingsMenu = CreateMenu();
	HMENU hSettingsResolution = CreateMenu();


	//File submenu
	AppendMenu(hFileMenu, MF_STRING, MENU_FILE_MENU, "Menu");
	AppendMenu(hFileMenu, MF_STRING, MENU_FILE_SAVE, "Save");
	AppendMenu(hFileMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hFileMenu, MF_STRING, MENU_FILE_EXIT, "Exit");

	//Settings submenu
	AppendMenu(hSettingsMenu, MF_POPUP, (UINT_PTR)hSettingsResolution, "Resolution");
	AppendMenu(hSettingsResolution, MF_STRING, RESOLUTION_800_600, "800x600");


	//Main menus
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "File");
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSettingsMenu, "Settings");
	SetMenu(hWnd, hMenu);
}