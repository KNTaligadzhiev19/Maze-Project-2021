#include <iostream>
#include "MazeGenerationAlgorithm.h"

int main()
{
	MazeGenerationAlgorithm maze;
	int a, b, c, d;

	MazeGenerationAlgorithm::Cell currenctCell[SIZE][SIZE];

	maze.initializeCell(currenctCell);
	maze.generateMaze(currenctCell,a,b,c,d);
}