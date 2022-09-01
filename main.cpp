#include <Windows.h>
#include <chrono>
#include <thread>

//Define screen width & height.
#define SCR_W = 1920
#define SCR_H = 1080

HICON icons[] = { // Load icons
	LoadIcon(NULL, IDI_ERROR),
	LoadIcon(NULL, IDI_WARNING),
	LoadIcon(NULL, IDI_INFORMATION),
	LoadIcon(NULL, IDI_QUESTION)
};

size_t S_ICONS = sizeof(icons);

void drawIcons() {
	HWND hWND = GetDesktopWindow();
	HDC hDC = GetWindowDC(hWND);
  
  //Draw icons at random positions on the screen.
	DrawIcon(hDC, (rand() % SCR_W), (rand() % SCR_H), icons[rand() % S_ICONS]);
  
	ReleaseDC(hWND, hDC);
}

int main() {
  //Hide the console.
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
  
	drawIcons()
  
	return 0;
}
