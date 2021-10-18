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