#include "../Header Files/MediumLevelMaze.h"

MediumLevelMaze::MediumLevelMaze()
{
	// Set difficulty to level 1
	level = 1;

	//Set chance for spawining a coin
	chance = 40;

	//Save status for symbol and background
	safeSymbolStatusData();
	safeBackgroundStatusData();

	// Setting the default pictures to print
	chooseSymb();

	initializeCell();

	generateMaze();

	initializeArray();
}