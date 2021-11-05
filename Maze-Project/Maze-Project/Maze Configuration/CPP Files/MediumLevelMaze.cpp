#include "../Header Files/MediumLevelMaze.h"

MediumLevelMaze::MediumLevelMaze()
{
	
	level = 1;

	
	t1.loadFromFile("Images and Fonts/WallMedium.png");
	t2.loadFromFile("Images and Fonts/Hedgehog.png");
	t3.loadFromFile("Images and Fonts/Apple.png");

	initializeCell();

	generateMaze();

	initializeArray();
}