#pragma once
#include "../../Interface/Header Files/FrontEnd.h"

#define HARD_SIZE 16

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

	// Structure for each cell
	struct Cell
	{
		bool isVisited;

		bool topWall;
		bool bottomWall;
		bool leftWall;
		bool rightWall;

		char symb;
	};

	//Integer as a counter for setting what difficulty of level player will play
	int level = 0;

	sf::Texture t1, t2, t3;

public:

	Cell currentCell[16][16];

	char consoleGrid[16][16];

	int chooseSize(int level);

	int movePixelSize(int level);

	void initializeCell();

	void initializeArray();

	void generateMaze();

	void printMaze(sf::RenderWindow& window);

	void moveOnClick(sf::RenderWindow& window, sf::Event& event1, int& check, bool& inGame, bool& congratsMenu, int& classChoice);
};

