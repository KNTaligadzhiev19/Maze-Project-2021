#include "../Header Files/MediumLevelMaze.h"

MediumLevelMaze::MediumLevelMaze()
{
	//Set diffictuly to level 1
	level = 1;

	//Setting the default pictures to print
	t1.loadFromFile("Images and Fonts/WallMedium.png");
	t2.loadFromFile("Images and Fonts/Hedgehog.png");
	t3.loadFromFile("Images and Fonts/Apple.png");

	initializeCell();

	generateMaze();

	initializeArray();
}