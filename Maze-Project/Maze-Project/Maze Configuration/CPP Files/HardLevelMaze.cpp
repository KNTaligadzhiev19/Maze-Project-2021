#include "../Header Files/HardLevelMaze.h"

HardLevelMaze::HardLevelMaze()
{
	// Set difficulty to level 0
	level = 0;

	//Set chance for spawining a coin
	chance = 60;

	// Setting the default pictures to print
	t1.loadFromFile("Images, Fonts and Music/WallHard.png");
	t2.loadFromFile("Images, Fonts and Music/Bee.png");
	t3.loadFromFile("Images, Fonts and Music/Honey.png");
	t4.loadFromFile("Images, Fonts and Music/CoinHard.png");

	initializeCell();

	generateMaze();

	initializeArray();
}