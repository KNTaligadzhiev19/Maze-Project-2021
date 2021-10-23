#pragma once
#include <vector>
#include <iostream>
#include "../../Interface/Header Files/FrontEnd.h"

#define HARD_SIZE 28

class MazeGenerationAlgorithm
{
protected:
	int positionX = 0, positionY = 0, finalPointX = 0, finalPointY = 0;

	enum Positions {
		ARROW_LEFT = 75,
		ARROW_RIGHT = 77,
		ARROW_UP = 72,
		ARROW_DOWN = 80,
		GRIDSYMB = 177,
		BEGINSYMB = char(234),
		ENDSYMB = char(233),
	};

	struct Cell
	{
		bool isVisited;

		bool topWall;
		bool bottomWall;
		bool leftWall;
		bool rightWall;

		char symb;
	};

	int level = 0;

public:

	Cell currentCell[HARD_SIZE][HARD_SIZE];

	int chooseSize(int level);

	void initializeCell();

	void startGame();

	void generateMaze(int& positionX, int& positionY, int& finalPointX, int& finalPointY);


};

