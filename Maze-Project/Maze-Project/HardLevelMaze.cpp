#include "HardLevelMaze.h"

HardLevelMaze::HardLevelMaze()
{
	level = 3;

	initializeCell();

	generateMaze(positionX, positionY, finalPointX, finalPointY);
}