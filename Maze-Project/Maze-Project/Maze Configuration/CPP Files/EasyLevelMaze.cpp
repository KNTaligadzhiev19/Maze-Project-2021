#include "../Header Files/EasyLevelMaze.h"

EasyLevelMaze::EasyLevelMaze()
{
	// Set difficulty to level 2
	level = 2;

	//Set chance for spawining a coin
	chance = 16;

	//Save status for symbol and background
	safeSymbolStatusData();
	safeBackgroundStatusData();

	// Setting the default pictures to print
	chooseSymb();

	initializeCell();

	generateMaze();

	initializeArray();
}