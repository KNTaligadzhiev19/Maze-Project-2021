#include "MazeGenerationAlgorithm.h"

void MazeGenerationAlgorithm::initializeCell(Cell currentCell[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			currentCell[i][j].symb = char(GRIDSYMB);

			currentCell[i][j].isVisited = false;
			currentCell[i][j].topWall = true;
			currentCell[i][j].bottomWall = true;
			currentCell[i][j].leftWall = true;
			currentCell[i][j].rightWall = true;
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			currentCell[i][j].topWall = false;
			currentCell[SIZE - 2][j].bottomWall = false;
			currentCell[i][1].leftWall = false;
			currentCell[i][SIZE - 2].rightWall = false;
		}
	}
}