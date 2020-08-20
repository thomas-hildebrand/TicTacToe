/*
Author: Thomas Hildebrand
Date: August 12, 2020
Description: Simple console based Tic Tac Toe game between two players.
*/

#include "Log.h"
#include <windows.h>

#define _WIN32_WINNT 0x0500
bool shouldContinue = true;

/*
Function Name: setWindow
Description: Sets custom window attributes
*/
void setWindow()
{
	HWND console = GetConsoleWindow();
	SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX); //Disables Window Resizing
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 625, 400, TRUE); //Sets Window Size
	SetConsoleTitle(TEXT("Tic Tac Toe")); // Sets Title on Console Window
}

int main()
{
	setWindow();

	//Local Variables
	Log log = Log();

	//Main Game loop
	while (shouldContinue)
	{
		shouldContinue = log.menuScreen();
	}
}