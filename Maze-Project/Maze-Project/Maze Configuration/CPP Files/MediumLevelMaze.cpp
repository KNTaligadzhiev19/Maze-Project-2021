#include "../Header Files/MediumLevelMaze.h"

MediumLevelMaze::MediumLevelMaze()
{
	// Set difficulty to level 1
	level = 1;

	//Set chance for spawining a coin
	chance = 40;

	// Setting the default pictures to print
	t1.loadFromFile("Images, Fonts and Music/WallMedium.png");
	t2.loadFromFile("Images, Fonts and Music/Hedgehog.png");
	t3.loadFromFile("Images, Fonts and Music/Apple.png");
	t4.loadFromFile("Images, Fonts and Music/CoinMedium.png");

	initializeCell();

	generateMaze();

	initializeArray();
}