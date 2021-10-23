#include "../Header Files/EasyLevelMaze.h"

EasyLevelMaze::EasyLevelMaze()
{
	//Set diffictuly to level 1
	level = 1;

	initializeCell();

	generateMaze(positionX, positionY, finalPointX, finalPointY);
}
