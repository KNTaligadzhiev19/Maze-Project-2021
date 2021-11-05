#include "../Header Files/EasyLevelMaze.h"

EasyLevelMaze::EasyLevelMaze()
{
	
	level = 2;

	
	t1.loadFromFile("Images and Fonts/WallEasy.png");
	t2.loadFromFile("Images and Fonts/Rabbit.png");
	t3.loadFromFile("Images and Fonts/Carrots.png");

	initializeCell();

	generateMaze();

	initializeArray();
}