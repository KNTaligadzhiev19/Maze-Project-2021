#pragma once
#include "MazeGenerationAlgorithm.h"

class HardLevelMaze : public MazeGenerationAlgorithm
{
public:

	HardLevelMaze()
	{
		level = 3;

		initializeCell();

		generateMaze(positionX, positionY, finalPointX, finalPointY);
	}
};

