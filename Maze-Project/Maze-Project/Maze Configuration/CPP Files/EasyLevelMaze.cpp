#include "../Header Files/EasyLevelMaze.h"

EasyLevelMaze::EasyLevelMaze()
{
	// Set difficulty to level 2
	level = 2;

	// Setting the default pictures to print
	t1.loadFromFile("Images, Fonts and Music/WallEasy.png");
	t2.loadFromFile("Images, Fonts and Music/Rabbit.png");
	t3.loadFromFile("Images, Fonts and Music/Carrots.png");

	initializeCell();

	generateMaze();

	initializeArray();
}