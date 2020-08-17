#pragma once

/*
Author: Thomas Hildebrand
Date: August 12, 2020
File: Log.h
Description: Log class will be used for messages for the user as well as the text based UI.
*/

#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include "Board.h"

class Log {
	const int LINE_LENGTH = 74;
	const char LINE_CHAR = '*';
	const int TEXT_COLOR_BLUE = 1;
	const int TEXT_COLOR_CYAN = 3;
	const int TEXT_COLOR_RED = 4;
	const int TEXT_COLOR_WHITE = 7;
	
	void line();
	void lineText(std::string s);
	void header(std::string s);
	void TextColor(int color);

	bool validateOption(std::string s);

public:
	bool menuScreen();
	void onePlayerScreen();
	void twoPlayerMode();
	void twoPlayerWelcome();
	bool exitScreen();
	void pause(std::string s);
};
