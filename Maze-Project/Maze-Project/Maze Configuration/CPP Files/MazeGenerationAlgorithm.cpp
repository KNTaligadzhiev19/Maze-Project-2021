#include "../Header Files/MazeGenerationAlgorithm.h"

//Set difficulty function
int MazeGenerationAlgorithm::chooseSize()
{
	if (level == 2)
	{
		return 8;
	}
	else if (level == 1)
	{
		return 6;
	}

	return 0;
}

//Set maze pixels to be printed
int MazeGenerationAlgorithm::movePixelSize()
{
	if (level == 2)
	{
		return 100;
	}
	else if (level == 1)
	{
		return 80;
	}

	return 50;
}

void MazeGenerationAlgorithm::initializeCell()
{
	const unsigned int size = HARD_SIZE - chooseSize();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			currentCell[i][j].symb = char(GRIDSYMB);

			currentCell[i][j].isVisited = false;
			currentCell[i][j].topWall = true;
			currentCell[i][j].bottomWall = true;
			currentCell[i][j].leftWall = true;
			currentCell[i][j].rightWall = true;
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			currentCell[i][j].topWall = false;
			currentCell[size - 2][j].bottomWall = false;
			currentCell[i][1].leftWall = false;
			currentCell[i][size - 2].rightWall = false;
		}
	}
}
