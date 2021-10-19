#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>
using namespace std;

#define/* EASY_*/SIZE 16
#define MEDIUM_SIZE 24
#define HARD_SIZE 28


class MazeGenerationAlgorithm
{
private:
	int positionX, positionY, finalPointX, finalPointY;

	enum Positions {
		ARROW_LEFT = 75,
		ARROW_RIGHT = 77,
		ARROW_UP = 72,
		ARROW_DOWN = 80,
		GRIDSYMB = 177,
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


public:
	Cell currentCell[SIZE][SIZE];

	

	void initializeCell();

	void startGame();

	void generateMaze(int& positionX, int& positionY, int& finalPointX, int& finalPointY);

	MazeGenerationAlgorithm()
	{

		initializeCell();
		
		generateMaze(positionX, positionY, finalPointX, finalPointY);
	}

	
};

