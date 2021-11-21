#include "../Header Files/HardLevelMaze.h"

HardLevelMaze::HardLevelMaze()
{
	// Set difficulty to level 0
	level = 0;

	//Set chance for spawining a coin
	chance = 60;

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