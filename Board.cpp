#include "Board.h"

void GameBoard::print()
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
Function Name: GameBoard::clear
Description: Clears the board of all player markers.
*/
void GameBoard::clear()
{
	board = { { ' ', ' ', ' ' } , { ' ', ' ', ' ' } , { ' ', ' ', ' ' } };
}

/*
Function Name: GameBoard::placeMarker
Description:  If possible place the marker on the game board at the given row and col
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

/*
Function Name: GameBoard::hasWinner
Description: Checks if a win has occurred.
*/
bool GameBoard::hasWinner(int row, int col)
{
	//Get Marker
	char marker = board[row][col];

	int r = row;
	int c = col;

	//Check Across
	if (board[row][++c % 3] == marker && board[row][++c % 3] == marker) return true;

	//Check Down
	if (board[++r % 3][col] == marker && board[++r % 3][col] == marker) return true;

	//Check Diagonal if Corner position
	if (row != 1 && col != 1)
	{
		row = (row == 0) ? 2 : 0;
		col = (col == 0) ? 2 : 0;

		if (board[1][1] == marker && board[row][col] == marker) return true;
	}

	//Check Diagonals if Middle position
	if ((row == 1 && col == 1) && ((board[0][0] == marker && board[2][2] == marker) || (board[0][2] == marker && board[2][0] == marker))) return true;

	return false;
}



