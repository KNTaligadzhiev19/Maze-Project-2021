#include "EasyLevelMaze.h"

EasyLevelMaze::EasyLevelMaze()
{
	level = 1;

	initializeCell();

	generateMaze(positionX, positionY, finalPointX, finalPointY);
}
