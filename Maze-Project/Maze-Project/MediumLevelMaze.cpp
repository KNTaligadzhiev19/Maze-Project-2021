#include "MediumLevelMaze.h"

MediumLevelMaze::MediumLevelMaze()
{
	level = 2;

	initializeCell();

	generateMaze(positionX, positionY, finalPointX, finalPointY);
}