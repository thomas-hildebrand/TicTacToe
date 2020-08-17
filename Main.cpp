/*
Author: Thomas Hildebrand
Date: August 12, 2020
Description: Simple console based Tic Tac Toe game between two players.
*/

#include "Log.h"

bool shouldContinue = true;

int main()
{

	//Local Variables
	Log log = Log();

	//Main Game loop
	while (shouldContinue)
	{
		shouldContinue = log.menuScreen();


	}
}