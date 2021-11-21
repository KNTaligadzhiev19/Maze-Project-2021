#include "../Header Files/MediumLevelMaze.h"

MediumLevelMaze::MediumLevelMaze()
{
	// Set difficulty to level 1
	level = 1;

	//Set chance for spawining a coin
	chance = 40;

	//Save what pawn the player will play with
	getSymbolStatus();

	//Save status for symbol and background
	symbol.safeSymbolStatusData();
	background.safeBackgroundStatusData();

	levelSetter();

	// Setting the default pictures to print
	symbol.setSymb();
	background.setBackground();

	initializeCell();

	generateMaze();

	initializeArray();
}