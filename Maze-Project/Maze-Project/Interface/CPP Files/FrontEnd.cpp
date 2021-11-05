#include "../Header Files/FrontEnd.h"
#include "SFML/Graphics.hpp"
#include "../../Sign System/Header Files/RegistrationSystem.h"
#include "../../Sign System/Header Files/LoginSystem.h"
#include "../../Sign System/Header Files/SHA256.h"
#include "../../Maze Configuration/Header Files/EasyLevelMaze.h"
#include "../../Maze Configuration/Header Files/MediumLevelMaze.h"
#include "../../Maze Configuration/Header Files/HardLevelMaze.h"

namespace checkValues {
	int status = 1;
	bool userMenuEventClick = true;
	bool loginAndRegisterEventClick = false;

	bool emailCheck = false;
	bool passwordCheck = false;

	bool logOrReg = false;
	bool checkIn = false;
	bool printableRulesTable = false;
	bool inCongratsTable = false;
	int modeChoice = 0;
	bool inGame = false;

	EasyLevelMaze* easyMaze = NULL;
	MediumLevelMaze* mediumMaze = NULL;
	HardLevelMaze* hardMaze = NULL;
};

void printMenu(sf::RenderWindow& window)
{
	sf::Texture t1, t2, t3;

	t1.loadFromFile("Login.png");
	t2.loadFromFile("Register.png");
	t3.loadFromFile("Logo.png");

	sf::Sprite Login(t1);
	sf::Sprite Register(t2);
	sf::Sprite Logo(t3);

	window.clear(sf::Color(0, 128, 128));
	Logo.setPosition(190, 90);
	window.draw(Logo);
	Login.setPosition(300, 390);
	window.draw(Login);
	Register.setPosition(300, 500);
	window.draw(Register);
}