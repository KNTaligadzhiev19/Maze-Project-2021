#include "../Header Files/EasyLevelMaze.h"

EasyLevelMaze::EasyLevelMaze()
{
	// Set difficulty to level 2
	level = 2;

	// Setting the default pictures to print
	t1.loadFromFile("Images and Fonts/WallEasy.png");
	t2.loadFromFile("Images and Fonts/Rabbit.png");
	t3.loadFromFile("Images and Fonts/Carrots.png");

	initializeCell();

	generateMaze();

	initializeArray();
}