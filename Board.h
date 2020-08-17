#pragma once

#include <iostream>
#include <vector>

class GameBoard {
	const char VERTICAL_BORDER = '|';
	const char HORIZONTAL_BORDER = '-';
	const char ROW_COL_OFFSET = 49;

	std::vector<std::vector<char>> board;

	bool isValidPos(std::string row, std::string col);
public:
	GameBoard() : board ({ { ' ', ' ', ' ' } , { ' ', ' ', ' ' } , { ' ', ' ', ' ' } }) {}
	void printBoard();
	void clearBoard();
	bool placeMarker(char marker, std::string row, std::string col);
	
};