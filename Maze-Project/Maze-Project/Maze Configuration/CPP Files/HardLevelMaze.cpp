#include "../Header Files/HardLevelMaze.h"

HardLevelMaze::HardLevelMaze()
{
	level = 0;

	t1.loadFromFile("Images and Fonts/WallHard.png");
	t2.loadFromFile("Images and Fonts/Bee.png");
	t3.loadFromFile("Images and Fonts/Honey.png");

	initializeCell();

	generateMaze();

	initializeArray();
}