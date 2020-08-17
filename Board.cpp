#include "Board.h"

void GameBoard::printBoard()
{
	
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			std::cout << board[i][j];
			if(j < board[0].size() - 1) std::cout << VERTICAL_BORDER;
		}

		std::cout << std::endl;

		for (int k = 0; k < board[0].size() && i < board.size() - 1; k++)
		{
			std::cout << HORIZONTAL_BORDER;
			if (k < board[0].size() - 1) std::cout << '+';

		}

		std::cout << std::endl;
	}

}

/*
Function Name: GameBoard::clearBoard
Description: Clears the board of all player markers.
*/
void GameBoard::clearBoard()
{
	board = { { ' ', ' ', ' ' } , { ' ', ' ', ' ' } , { ' ', ' ', ' ' } };
}

/*
Function Name: GameBoard::placeMarker
Description:  If possible set the 
*/
bool GameBoard::placeMarker(char marker, std::string row, std::string col)
{
	if (!isValidPos(row, col)) return false;

	int r = row[0] - ROW_COL_OFFSET;
	int c = col[0] - ROW_COL_OFFSET;

	if (board[r][c] != ' ') return false;

	board[r][c] = marker;

	return true;
}

/*
Function Name: GameBoard::isValidPos
Description: Ensures given input is a valid position on the board.
*/
bool GameBoard::isValidPos(std::string row, std::string col)
{
	if (row.length() != 1 || col.length() != 1) return false;
    
	char r = row[0];
	char c = col[0];

	if (r > 51 || r < 49 || c > 51 || c < 49) return false;

	return true;
}



