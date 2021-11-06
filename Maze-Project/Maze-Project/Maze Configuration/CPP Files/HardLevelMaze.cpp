#include "../Header Files/HardLevelMaze.h"

HardLevelMaze::HardLevelMaze()
{
	// Set difficulty to level 0
	level = 0;

	// Setting the default pictures to print
	t1.loadFromFile("Images, Fonts and Music/WallHard.png");
	t2.loadFromFile("Images, Fonts and Music/Bee.png");
	t3.loadFromFile("Images, Fonts and Music/Honey.png");

	initializeCell();

	generateMaze();

	initializeArray();
}