#pragma once
#include <string>

class Player
{
	std::string name;
	char marker;


public:
	
	Player(std::string playerName, char mark) : name(playerName), marker(mark) {}
	
	std::string getName();
	char getMarker();

};