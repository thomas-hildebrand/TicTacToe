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

*/
void setWindow()
{
	HWND console = GetConsoleWindow();
	SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX); //Disables Window Resizing
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 625, 400, TRUE); //Sets Window Size
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