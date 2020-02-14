#include <windows.h>
#include "definedValues.h"
#include "callBack.h"
#include "upperMenu.h"


int WINAPI WinMain(HINSTANCE currentInstance, HINSTANCE previousInstance, PSTR cmdLine, INT cmdCount)
{
	// REJESTROWANIE KLASY
	LPCWSTR CLASS_NAME = L"myWin32WindowClass";
	WNDCLASSEXW wc{};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = currentInstance;
	wc.lpszClassName = CLASS_NAME;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = WindowProcessMessages;
	if (!RegisterClassExW(&wc))
		return -1;

	// TWORZENIE OKNA
	CreateWindowExW(WS_EX_ACCEPTFILES, CLASS_NAME, L"Okno",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,    
		CW_USEDEFAULT, CW_USEDEFAULT,  
		800, 600,                      
		nullptr, nullptr, nullptr, nullptr);

	// PÊTLA OKNA
	MSG msg{};
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}