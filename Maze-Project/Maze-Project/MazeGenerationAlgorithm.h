#pragma once

#define SIZE 22
class MazeGenerationAlgorithm
{
private:
	enum Positions {
		ARROW_LEFT = 75,
		ARROW_RIGHT = 77,
		ARROW_UP = 72,
		ARROW_DOWN = 80,
		GRIDSYMB = 177,
	};

public:
	struct Cell
	{
		bool isVisited;

		bool topWall;
		bool bottomWall;
		bool leftWall;
		bool rightWall;

		char symb;
	};
};

