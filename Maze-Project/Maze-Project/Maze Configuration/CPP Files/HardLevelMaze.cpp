#include "../Header Files/HardLevelMaze.h"

HardLevelMaze::HardLevelMaze()
{
	//Set diffictuly to level 0
	level = 0;

	//Setting the default pictures to print
	t1.loadFromFile("Images and Fonts/WallHard.png");
	t2.loadFromFile("Images and Fonts/Bee.png");
	t3.loadFromFile("Images and Fonts/Honey.png");

	initializeCell();

	generateMaze();

	initializeArray();
}