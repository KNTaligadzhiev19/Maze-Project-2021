#include "../Header Files/HardLevelMaze.h"

HardLevelMaze::HardLevelMaze()
{
	//Set diffictuly to level 3
	level = 3;

	initializeCell();

	generateMaze(positionX, positionY, finalPointX, finalPointY);
}