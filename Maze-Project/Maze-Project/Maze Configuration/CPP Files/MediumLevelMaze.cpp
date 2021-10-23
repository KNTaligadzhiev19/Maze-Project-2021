#include "../Header Files/MediumLevelMaze.h"

MediumLevelMaze::MediumLevelMaze()
{
	//Set diffictuly to level 2
	level = 2;

	initializeCell();

	generateMaze(positionX, positionY, finalPointX, finalPointY);
}