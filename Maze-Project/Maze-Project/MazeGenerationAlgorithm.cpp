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

void MazeGenerationAlgorithm::startGame(Cell currentCell[][SIZE])
{
	int positionX = 0, positionY = 0;
	int finalPointX = 0, finalPointY = 0;

	while (true)
	{
		for (int i = 0; i < (SIZE * 3) + 4; i++)
		{
			cout << char(GRIDSYMB);
		}

		for (int i = 0; i < SIZE; i++)
		{
			cout << endl;
			cout << char(GRIDSYMB) << char(GRIDSYMB);
			for (int j = 0; j < SIZE; j++)
			{
				if (currentCell[i][j].symb == 'S')
				{
					positionX = i;
					positionY = j;
					cout << " " << currentCell[i][j].symb << " ";
				}
				else if (currentCell[i][j].symb == 'E')
				{
					finalPointX = i;
					finalPointY = j;
					cout << " " << currentCell[i][j].symb << " ";
				}
				else
				{
					cout << currentCell[i][j].symb << currentCell[i][j].symb << currentCell[i][j].symb;
				}
			}
			cout << char(GRIDSYMB) << char(GRIDSYMB);
		}
		cout << endl;
		for (int i = 0; i < (SIZE * 3) + 4; i++)
		{
			cout << char(GRIDSYMB);
		}

		switch (_getch())
		{
		case ARROW_LEFT: case 'a': case 'A':
			if (currentCell[positionX][positionY - 1].symb == ' ')
			{
				swap(currentCell[positionX][positionY], currentCell[positionX][positionY - 1]);
				positionY--;
			}
			else if (currentCell[positionX][positionY - 1].symb == 'E')
			{
				swap(currentCell[positionX][positionY], currentCell[positionX][positionY - 1]);
				currentCell[positionX][positionY].symb = ' ';
				positionY++;
			}
			break;
		case ARROW_DOWN: case 's': case 'S':
			if (currentCell[positionX + 1][positionY].symb == ' ')
			{
				swap(currentCell[positionX][positionY], currentCell[positionX + 1][positionY]);
				positionX++;
			}
			else if (currentCell[positionX + 1][positionY].symb == 'E')
			{
				swap(currentCell[positionX][positionY], currentCell[positionX + 1][positionY]);
				currentCell[positionX][positionY].symb = ' ';
				positionX--;
			}
			break;
		case ARROW_RIGHT: case 'd': case 'D':
			if (currentCell[positionX][positionY + 1].symb == ' ')
			{
				swap(currentCell[positionX][positionY], currentCell[positionX][positionY + 1]);
				positionY++;
			}
			else if (currentCell[positionX][positionY + 1].symb == 'E')
			{
				swap(currentCell[positionX][positionY], currentCell[positionX][positionY + 1]);
				currentCell[positionX][positionY].symb = ' ';
				positionY--;
			}
			break;
		case ARROW_UP: case 'w': case 'W':
			if (currentCell[positionX - 1][positionY].symb == ' ')
			{
				swap(currentCell[positionX][positionY], currentCell[positionX - 1][positionY]);
				positionX--;
			}
			else if (currentCell[positionX - 1][positionY].symb == 'E')
			{
				swap(currentCell[positionX][positionY], currentCell[positionX - 1][positionY]);
				currentCell[positionX][positionY].symb = ' ';
				positionX++;
			}
			break;
		}

		if ((finalPointX == positionX) && (finalPointY == positionY))
		{
			cout << "\nYou win!\n";
			break;
		}

		system("cls");
	}
}

void MazeGenerationAlgorithm::generateMaze(Cell currentCell[][SIZE],int& positionX, int& positionY, int& finalPointX, int& finalPointY)
{
	srand((unsigned int)time(0));

	int randomNumber;
	int randomXCordinate = ((2 * rand()) + 1) % (SIZE - 1);
	int randomYCordinate = ((2 * rand()) + 1) % (SIZE - 1);
	
	positionX = randomXCordinate;
	positionY = randomYCordinate;

	int visitedCells = 1;

	int totalCells = ((SIZE - 1) / 2) * ((SIZE - 1) / 2);

	vector<int> xTrack, yTrack;

	currentCell[randomYCordinate][randomXCordinate].symb = 'S';
	currentCell[randomYCordinate][randomXCordinate].isVisited = true;

	while (visitedCells < totalCells)
	{
		if (((currentCell[randomYCordinate - 2][randomXCordinate].isVisited == false) && (currentCell[randomYCordinate][randomXCordinate].topWall == true) && (currentCell[randomYCordinate - 2][randomXCordinate].bottomWall == true)) ||
			((currentCell[randomYCordinate + 2][randomXCordinate].isVisited == false) && (currentCell[randomYCordinate][randomXCordinate].bottomWall == true) && (currentCell[randomYCordinate + 2][randomXCordinate].topWall == true)) ||
			((currentCell[randomYCordinate][randomXCordinate - 2].isVisited == false) && (currentCell[randomYCordinate][randomXCordinate].leftWall==true) && (currentCell[randomYCordinate][randomXCordinate - 2].rightWall==true)) ||
			((currentCell[randomYCordinate][randomXCordinate + 2].isVisited == false) && (currentCell[randomYCordinate][randomXCordinate].rightWall == true) && (currentCell[randomYCordinate][randomXCordinate + 2].leftWall == true)))
		{
			randomNumber = (rand() % 4) + 1;

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
			else if ((randomNumber == 2) && (randomYCordinate < SIZE - 2))
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
			else if ((randomNumber == 4) && (randomXCordinate < SIZE - 2))
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
		else {

			randomXCordinate = xTrack.back();
			xTrack.pop_back();

			randomYCordinate = yTrack.back();
			yTrack.pop_back();
		}
	}
	finalPointX = randomXCordinate;
	finalPointY = randomYCordinate;

	currentCell[finalPointY][finalPointX].symb = 'E';

	system("cls");

	startGame(currentCell);

}