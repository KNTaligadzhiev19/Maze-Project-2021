#pragma once
#include "../../Interface/Header Files/FrontEnd.h"
#include "Shop.h"

#define HARD_SIZE 20

class MazeGenerationAlgorithm : public Shop
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
		COIN = 42,
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

	//Integer for storing the chance for coin
	int chance = 0;

	//Integer for storing the chance for gem
	int chance2 = 0;

public:

	Cell currentCell[20][20];

	char consoleGrid[20][20];

	//Choosing Level
	int chooseSize(int level);

	//Setting the images pixels for the level
	int movePixelSize(int level);

	void initializeCell();

	void initializeArray();

	void generateMaze();

	void printMaze(sf::RenderWindow& window);

	void moveOnClick(sf::RenderWindow& window, sf::Event& event1, int& check, bool& inGame, bool& congratsMenu, int& classChoice);
};