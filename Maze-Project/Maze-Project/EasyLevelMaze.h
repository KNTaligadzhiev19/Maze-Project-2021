#pragma once
#include "MazeGenerationAlgorithm.h"
class EasyLevelMaze : public MazeGenerationAlgorithm
{
public:

	EasyLevelMaze()
	{
		level = 1;

		initializeCell();

		generateMaze(positionX, positionY, finalPointX, finalPointY);
	}
};

