#include "Log.h"

/*
Function Name: Log::line
Description: Prints a line of LINE_CHAR's to output equal in length to the LINE_LENGTH.
	Used mainly for UI formatting.
*/
void Log::line()
{
	for (int i = 0 ; i < LINE_LENGTH ; i++)
	{
		std::cout << LINE_CHAR;
	}
	
	std::cout << std::endl;
}

/*
Function Name: Log::lineText
Description:  Prints the given string in the middle of a line with a LINE_CHAR on either end.
	Used mainly for UI formatting to create headers.
*/
void Log::lineText(std::string s)
{
	//Local Variables
	int numSpaces = (LINE_LENGTH - (s.length() + 2)) / 2; //Number of spaces to print on either side of given string
	
	//Print the beginning LINE_CHAR
	std::cout << LINE_CHAR;

	//Print the spaces before the text
	for (int i = 0 ; i < numSpaces ; i++)
	{
		std::cout << " ";
	}

	//Print the text in the center
	std::cout << s;

	//Print the spaces after the text
	if (s.length() % 2 != 0) numSpaces++;
	for (int i = 0; i < numSpaces; i++)
	{
		std::cout << " ";
	}

	//Print the end LINE_CHAR and go to new line
	std::cout << LINE_CHAR << std::endl;

}

void Log::header(std::string s)
{
	system("CLS");
	line();
	lineText(s);
	line();
}

void Log::TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/*
Function Name: Log::validateOption
Description: Checks if the given string is a valid menu option
*/
bool Log::validateOption(std::string s)
{
	if (s.length() != 1) return false;

	char c = s[0];

	if (c < 49 || c > 51) return false;

	return true;
}

/*
Function Name: Log::menu
Description:  Displays main menu to output.
*/
bool Log::menuScreen()
{
	//Local Variables
	std::string choice = "";
	bool invalidChoice = false;

	while (!validateOption(choice))
	{
		//Clear screen and print header
		header("Main Menu");

		//Print menu options
		std::cout << "1. 1 - Player Game (NOT YET IMPLEMENTED)" << std::endl;
		std::cout << "2. 2 - Player Game (WORK IN PROGRESS)" << std::endl;
		std::cout << "3. Exit" << std::endl;

		//Prompt user input, if previously invalid choice was made prompt again
		if (invalidChoice) {
			TextColor(TEXT_COLOR_RED);
			std::cout << "Invalid Choice! Please Choose again: ";
			TextColor(TEXT_COLOR_WHITE);
		}
		else
		{
			std::cout << "Please choose from the above options: ";
		}

		//Capture user choice and validate input
		std::getline(std::cin, choice);
		
		invalidChoice = true;
	}

	if (choice == "1") onePlayerScreen();
	else if (choice == "2") twoPlayerMode();
	else if (choice == "3") return exitScreen();
}

//TODO
void Log::onePlayerScreen()
{
	header("One Player Mode");
	
	std::cout << "This feature has not yet been implemented. \nPlease press any key to return to the main menu.\n";
	system("PAUSE");
}

/*
Function Name: Log::twoPlayerMode
Description: Handles the text based output for the two player mode UI
*/
void Log::twoPlayerMode()
{
	twoPlayerWelcome();
}

/*
Function Name: Log::twoPlayerWelcome()
Description: This is the inital starting screen for two player mode that will welcome and explain the game to the 
	players.
*/
void Log::twoPlayerWelcome()
{
	header("Two Player Mode");

	std::cout << "Welcome to two player mode!  In this mode two players will compete\n";
	std::cout << "against each other in a turn based fashion.\n";
	std::cout << "Player X will go first by first entering the row number, second the\n";
	std::cout << "column number, of an empty position on the game board.  A 'X' marker will\n";
	std::cout << "than be placed on the game board at that position.\n";
	std::cout << "\n";
	system("PAUSE");

	header("Two Player Mode");
	GameBoard b = GameBoard();

	std::cout << "For example: \n\n";
	b.printBoard();
	std::cout << "If Player X would like to place the first marker in the upper left corner\n";
	std::cout << "then Player X would enter '1' for the row and '1' for the column.  Then\n";
	std::cout << "a 'X' marker will appear as follows: \n\n";
	b.placeMarker('X', "1", "1");
	b.printBoard();
	system("PAUSE");

	header("Two Player Mode");
	std::cout << "If Player X would instead like to place the first marker in the second row\n";
	std::cout << "and first column, then Player X would enter '2' for the row and '1' for\n";
	std::cout << "column.  Then a 'X' marker will aperar as follows: \n\n";
	b.clearBoard();
	b.placeMarker('X', "2", "1");
	b.printBoard();
	pause("Press any key to begin game...");


}

bool Log::exitScreen()
{
	std::string choice = "";
	bool invalidchoice = false;

	while (choice != "Y" && choice != "y" && choice != "N" && choice != "n") {
		header("Exit Program");

		std::cout << "Are you sure you wish to exit?\n\n"; 
		if (invalidchoice) {
			TextColor(TEXT_COLOR_RED);
			std::cout << "Invalid Choice! Please Choose again!" << std::endl;
			TextColor(TEXT_COLOR_WHITE);
		}
		
		std::cout << "Enter 'Y' to exit or 'N' to return to the main menu: " << std::endl;

		//Capture user choice and validate input
		std::getline(std::cin, choice);

		invalidchoice = true;
	}

	if (choice == "Y" || choice == "y") return false;
}

void Log::pause(std::string s)
{
	std::cout << s << std::endl;
	char c = _getch();
}
