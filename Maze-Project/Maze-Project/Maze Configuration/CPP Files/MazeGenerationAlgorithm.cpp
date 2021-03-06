#include "../Header Files/MazeGenerationAlgorithm.h"
#include <iostream>

// Set difficulty function
int MazeGenerationAlgorithm::chooseSize(int level)
{
	if (level == 2)
	{
		return 10;
	}
	else if (level == 1)
	{
		return 4;
	}

	return 0;
}

// Set maze pixels
int MazeGenerationAlgorithm::movePixelSize(int level)
{
	if (level == 2)
	{
		return 80;
	}
	else if (level == 1)
	{
		return 50;
	}

	return 40;
}

void MazeGenerationAlgorithm::initializeCell()
{
	const unsigned int size = HARD_SIZE - chooseSize(this->level);
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

void MazeGenerationAlgorithm::initializeArray()
{
	const int size = HARD_SIZE - chooseSize(this->level);
	int positionX = 0, positionY = 0;
	int finalPointX = 0, finalPointY = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (currentCell[i][j].symb == BEGINSYMB)
			{
				consoleGrid[i][j] = currentCell[i][j].symb;
			}
			else if (currentCell[i][j].symb == ENDSYMB)
			{
				consoleGrid[i][j] = currentCell[i][j].symb;
			}
			else
			{
				consoleGrid[i][j] = currentCell[i][j].symb;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (consoleGrid[i][j]==' ')
			{
				int currentChance = rand() % this->chance;
				if (currentChance == 7)
				{
					consoleGrid[i][j] = (char)COIN;
				}
			}
		}
	}
}

void MazeGenerationAlgorithm::generateMaze()
{
	// Setting the size for the maze
	const int size = HARD_SIZE - chooseSize(this->level);

	int randomNumber;
	int randomXCordinate = ((2 * rand()) + 1) % (size - 1);
	int randomYCordinate = ((2 * rand()) + 1) % (size - 1);

	positionX = randomXCordinate;
	positionY = randomYCordinate;

	int visitedCells = 1;

	int totalCells = ((size - 1) / 2) * ((size - 1) / 2);

	std::vector<int> xTrack, yTrack; // Used for having the reversed path

	currentCell[randomYCordinate][randomXCordinate].symb = BEGINSYMB;
	currentCell[randomYCordinate][randomXCordinate].isVisited = true;

	while (visitedCells < totalCells)
	{
		if (((currentCell[randomYCordinate - 2][randomXCordinate].isVisited == false) 
			&& (currentCell[randomYCordinate][randomXCordinate].topWall == true) 
			&& (currentCell[randomYCordinate - 2][randomXCordinate].bottomWall == true)) ||
			((currentCell[randomYCordinate + 2][randomXCordinate].isVisited == false) 
				&& (currentCell[randomYCordinate][randomXCordinate].bottomWall == true) 
				&& (currentCell[randomYCordinate + 2][randomXCordinate].topWall == true)) ||
			((currentCell[randomYCordinate][randomXCordinate - 2].isVisited == false) 
				&& (currentCell[randomYCordinate][randomXCordinate].leftWall == true) 
				&& (currentCell[randomYCordinate][randomXCordinate - 2].rightWall == true)) ||
			((currentCell[randomYCordinate][randomXCordinate + 2].isVisited == false) 
				&& (currentCell[randomYCordinate][randomXCordinate].rightWall == true) 
				&& (currentCell[randomYCordinate][randomXCordinate + 2].leftWall == true)))
		{
			randomNumber = (rand() % 4) + 1; // Random wall to be removed

			if ((randomNumber == 1) && randomYCordinate > 1)
			{
				if (currentCell[randomYCordinate - 2][randomXCordinate].isVisited == false)
				{
					currentCell[randomYCordinate - 1][randomXCordinate].symb = ' ';
					currentCell[randomYCordinate - 1][randomXCordinate].isVisited = true;
					currentCell[randomYCordinate][randomXCordinate].topWall = false;

					xTrack.push_back(randomXCordinate);
					yTrack.push_back(randomYCordinate);

					randomYCordinate -= 2;
					currentCell[randomYCordinate][randomXCordinate].isVisited = true;
					currentCell[randomYCordinate][randomXCordinate].symb = ' ';
					currentCell[randomYCordinate][randomXCordinate].bottomWall = false;
					visitedCells++;
				}
				else
					continue;
			}
			else if ((randomNumber == 2) && (randomYCordinate < size - 2))
			{
				if (currentCell[randomYCordinate + 2][randomXCordinate].isVisited == false)
				{
					currentCell[randomYCordinate + 1][randomXCordinate].symb = ' ';
					currentCell[randomYCordinate + 1][randomXCordinate].isVisited = true;
					currentCell[randomYCordinate][randomXCordinate].bottomWall = false;

					xTrack.push_back(randomXCordinate);
					yTrack.push_back(randomYCordinate);

					randomYCordinate += 2;
					currentCell[randomYCordinate][randomXCordinate].isVisited = true;
					currentCell[randomYCordinate][randomXCordinate].symb = ' ';
					currentCell[randomYCordinate][randomXCordinate].topWall = false;
					visitedCells++;
				}
				else {
					continue;
				}
			}
			else if ((randomNumber == 3) && (randomXCordinate > 1))
			{
				if (currentCell[randomYCordinate][randomXCordinate - 2].isVisited == false)
				{
					currentCell[randomYCordinate][randomXCordinate - 1].symb = ' ';
					currentCell[randomYCordinate][randomXCordinate - 1].isVisited = true;
					currentCell[randomYCordinate][randomXCordinate].leftWall = false;

					xTrack.push_back(randomXCordinate);
					yTrack.push_back(randomYCordinate);

					randomXCordinate -= 2;

					currentCell[randomYCordinate][randomXCordinate].isVisited = true;
					currentCell[randomYCordinate][randomXCordinate].symb = ' ';
					currentCell[randomYCordinate][randomXCordinate].rightWall = false;

					visitedCells++;
				}
				else
					continue;
			}
			else if ((randomNumber == 4) && (randomXCordinate < size - 2))
			{
				if (currentCell[randomYCordinate][randomXCordinate + 2].isVisited == false)
				{
					currentCell[randomYCordinate][randomXCordinate + 1].symb = ' ';
					currentCell[randomYCordinate][randomXCordinate + 1].isVisited = true;
					currentCell[randomYCordinate][randomXCordinate].rightWall = false;

					xTrack.push_back(randomXCordinate);
					yTrack.push_back(randomYCordinate);

					randomXCordinate += 2;
					currentCell[randomYCordinate][randomXCordinate].isVisited = true;
					currentCell[randomYCordinate][randomXCordinate].symb = ' ';
					currentCell[randomYCordinate][randomXCordinate].leftWall = false;
					visitedCells++;
				}
				else
					continue;
			};
		}
		else 
		{
			if (xTrack.empty() == false && yTrack.empty() == false)
			{
				randomXCordinate = xTrack.back();
				xTrack.pop_back();

				randomYCordinate = yTrack.back();
				yTrack.pop_back();
			}
			else {
				//Returning to the previous page
				reload();
				break;
			}
		}
	}

	finalPointX = randomXCordinate;
	finalPointY = randomYCordinate;

	currentCell[finalPointY][finalPointX].symb = ENDSYMB;
}

void MazeGenerationAlgorithm::printMaze(sf::RenderWindow& window)
{
	background.setColor(window);
	const int size = HARD_SIZE - chooseSize(this->level);

	sf::Sprite Wall(background.t1);
	sf::Sprite Current(symbol.t2);
	sf::Sprite Goal(symbol.t3);
	sf::Sprite Coin1(symbol.t4);

	int cordinateX = 0, cordinateY = 0;

	for (int i = 0; i < size; i++)
	{
		cordinateY = 0;
		for (int j = 0; j < size; j++)
		{
			if (consoleGrid[i][j] == char(GRIDSYMB))
			{
				Wall.setPosition(cordinateX, cordinateY);
				window.draw(Wall);
			}
			else if (consoleGrid[i][j] == char(BEGINSYMB))
			{
				positionX = i;
				positionY = j;
				Current.setPosition(cordinateX, cordinateY);
				window.draw(Current);
			}
			else if (consoleGrid[i][j] == char(ENDSYMB))
			{
				finalPointX = i;
				finalPointY = j;
				Goal.setPosition(cordinateX, cordinateY);
				window.draw(Goal);
			}
			else if (consoleGrid[i][j] == char(COIN))
			{
				Coin1.setPosition(cordinateX, cordinateY);
				window.draw(Coin1);
			}
			cordinateY += movePixelSize(this->level);
		}
		cordinateX += movePixelSize(this->level);
	}
}

void MazeGenerationAlgorithm::moveOnClick(sf::RenderWindow& window, sf::Event& event1, int& check,
	bool& inGaCurrent, bool& congratsCurrentnu, int& classChoice)
{
	safeCoinData();

	statusDataOut.open("Owned Figures.txt", std::ios::out | std::ios::app);

	while (window.pollEvent(event1))
	{
		if (event1.type == sf::Event::KeyPressed)
		{
			if (event1.key.code == sf::Keyboard::S || event1.key.code == sf::Keyboard::Down)
			{
				if (consoleGrid[positionX][positionY + 1] == ENDSYMB)
				{
					std::swap(consoleGrid[positionX][positionY], consoleGrid[positionX][positionY + 1]);
					consoleGrid[positionX][positionY] = ' ';
					positionY--;
				}
				else if (consoleGrid[positionX][positionY + 1] == COIN)
				{
					int randNumber = rand() % 3 + 1;
					consoleGrid[positionX][positionY + 1] = ' ';
					std::swap(consoleGrid[positionX][positionY], consoleGrid[positionX][positionY + 1]);
					positionY++;
					if (randNumber == 2)
					{
						inQuestion();
					}
					else {
						coins++;
					}
				}
				else if (consoleGrid[positionX][positionY + 1] == ' ') {
					std::swap(consoleGrid[positionX][positionY], consoleGrid[positionX][positionY + 1]);
					positionY++;
				}

			}
			else if (event1.key.code == sf::Keyboard::W || event1.key.code == sf::Keyboard::Up)
			{
				if (consoleGrid[positionX][positionY - 1] == ENDSYMB)
				{
					std::swap(consoleGrid[positionX][positionY], consoleGrid[positionX][positionY - 1]);
					consoleGrid[positionX][positionY] = ' ';
					positionY++;
				}
				else if (consoleGrid[positionX][positionY - 1] == COIN)
				{
					int randNumber = rand() % 3 + 1;
					consoleGrid[positionX][positionY - 1] = ' ';
					std::swap(consoleGrid[positionX][positionY], consoleGrid[positionX][positionY - 1]);
					positionY++;
					if (randNumber == 2)
					{
						inQuestion();
					}
					else {
						coins++;
					}
					
				}
				else if (consoleGrid[positionX][positionY - 1] == ' ') {
					std::swap(consoleGrid[positionX][positionY], consoleGrid[positionX][positionY - 1]);
					positionY--;
				}
			}
			else if (event1.key.code == sf::Keyboard::D || event1.key.code == sf::Keyboard::Right)
			{
				if (consoleGrid[positionX + 1][positionY] == ENDSYMB)
				{
					std::swap(consoleGrid[positionX][positionY], consoleGrid[positionX + 1][positionY]);
					consoleGrid[positionX][positionY] = ' ';
					positionX--;
				}
				else if (consoleGrid[positionX + 1][positionY] == COIN)
				{
					int randNumber = rand() % 3 + 1;
					consoleGrid[positionX + 1][positionY] = ' ';
					std::swap(consoleGrid[positionX][positionY], consoleGrid[positionX + 1][positionY]);
					positionX--;
					if (randNumber == 2)
					{
						inQuestion();
					}
					else {
						coins++;
					}
				}
				else if (consoleGrid[positionX + 1][positionY] == ' ') {

					std::swap(consoleGrid[positionX][positionY], consoleGrid[positionX + 1][positionY]);
					positionX++;
				}
			}
			else if (event1.key.code == sf::Keyboard::A || event1.key.code == sf::Keyboard::Left)
			{
				if (consoleGrid[positionX - 1][positionY] == ENDSYMB)
				{
					std::swap(consoleGrid[positionX][positionY], consoleGrid[positionX - 1][positionY]);
					consoleGrid[positionX][positionY] = ' ';
					positionX++;
				}
				else if (consoleGrid[positionX - 1][positionY] == COIN)
				{
					int randNumber = rand() % 3 + 1;
					consoleGrid[positionX - 1][positionY] = ' ';
					std::swap(consoleGrid[positionX][positionY], consoleGrid[positionX - 1][positionY]);
					positionX++;
					if (randNumber == 2)
					{
						inQuestion();
					}
					else {
						coins++;
					}
				}
				else if (consoleGrid[positionX - 1][positionY] == ' ') {
					std::swap(consoleGrid[positionX][positionY], consoleGrid[positionX - 1][positionY]);
					positionX--;
				}
			}
		}
		else if (event1.type == sf::Event::Closed)
		{
			window.close();
		}

		if ((finalPointX == positionX) && (finalPointY == positionY))
		{
			check = 9;
			inGaCurrent = false;
			congratsCurrentnu = true;
			classChoice = 0;
		}
	}

	saveCoinData2(coins);

	statusDataIn.open("Owned Figures.txt", std::ios::in | std::ios::app);

	std::vector<std::string> v1;
	std::string text3,text4;
	sf::String email = returnSafeEmail();

	while (getline(statusDataIn, text3))
	{
		v1.push_back(text3);
	}

	for (size_t i = 0; i < v1.size(); i++)
	{
		if (v1.at(i) == email)
		{
			v1.at(i + 1) = "Coins: " + std::to_string(coins);
		}
	}

	statusDataOut.close();
	statusDataOut.open("Owned Figures.txt", std::ios::out | std::ios::trunc);

	for (std::string i : v1)
	{
		statusDataOut << i << std::endl;
	}

	statusDataIn.close();
	statusDataOut.close();
}