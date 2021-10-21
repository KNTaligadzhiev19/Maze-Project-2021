#include "../Header Files/EasyLevelMaze.h"

EasyLevelMaze::EasyLevelMaze()
{
	level = 1;

	initializeCell();

	generateMaze(positionX, positionY, finalPointX, finalPointY);
}
