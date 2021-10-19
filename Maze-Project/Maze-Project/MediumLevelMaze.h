#pragma once
#include "MazeGenerationAlgorithm.h"

class MediumLevelMaze : public MazeGenerationAlgorithm
{
public:
	MediumLevelMaze()
	{
		level = 2;

		initializeCell();

		generateMaze(positionX, positionY, finalPointX, finalPointY);
	}
};

