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

sf::String loginEmail;
sf::String loginPassword;

sf::String registerEmail;
sf::String registerPassword;

void printLoginAndRegisterMenu(sf::RenderWindow& window)
{

	sf::Text loginText, passwordText;
	sf::Texture t1, t2, t3, t4, t5, t6;
	sf::Font myFont;
	myFont.loadFromFile("arial.ttf");

	t1.loadFromFile("Submit.png");
	t2.loadFromFile("Password.png");
	t3.loadFromFile("Email.png");
	t5.loadFromFile("WhiteSection.png");
	loginText.setFont(myFont);
	loginText.setCharacterSize(25);
	loginText.setPosition(290, 340);
	loginText.setFillColor(sf::Color::Black);
	passwordText.setFont(myFont);
	passwordText.setCharacterSize(25);
	passwordText.setPosition(333, 439);
	passwordText.setFillColor(sf::Color::Black);

	if (checkValues::logOrReg)
	{
		t6.loadFromFile("LoginTitle.png");
		t4.loadFromFile("LoginBack.png");
		loginText.setString(loginEmail);
		passwordText.setString(loginPassword);
	}

	else
	{
		t6.loadFromFile("RegisterTitle.png");
		t4.loadFromFile("RegisterBack.png");
		loginText.setString(registerEmail);
		passwordText.setString(registerPassword);
	}

	sf::Sprite Submit(t1);
	sf::Sprite Password(t2);
	sf::Sprite Email(t3);
	sf::Sprite Back(t4);
	sf::Sprite Section(t5);
	sf::Sprite LoginTitle(t6);

	window.clear(sf::Color(0, 128, 128));
	Section.setPosition(120, 20);
	window.draw(Section);
	if (checkValues::logOrReg)
	{
		Back.setPosition(180, 190);
		window.draw(Back);
	}
	else
	{
		Back.setPosition(187, 200);
		window.draw(Back);
	}
	Email.setPosition(188, 320);
	window.draw(Email);
	Password.setPosition(188, 420);
	window.draw(Password);
	Submit.setPosition(188, 535);
	window.draw(Submit);
	LoginTitle.setPosition(270, 100);
	window.draw(LoginTitle);
	window.draw(loginText);
	window.draw(passwordText);
}

void printPlayerMenu(sf::RenderWindow& window)
{
	window.clear(sf::Color(0, 128, 128));

	sf::Texture t1, t2, t3, t4, t5, t6;

	t1.loadFromFile("EasyLevel.png");
	t2.loadFromFile("MediumLevel.png");
	t3.loadFromFile("HardLevel.png");
	t4.loadFromFile("Logo.png");
	t5.loadFromFile("Back.png");
	t6.loadFromFile("Rules.png");

	sf::Sprite Easy(t1);
	sf::Sprite Medium(t2);
	sf::Sprite Hard(t3);
	sf::Sprite Logo(t4);
	sf::Sprite GoBack(t5);
	sf::Sprite Rules(t6);

	GoBack.setPosition(30, 15);
	window.draw(GoBack);
	Rules.setPosition(700, 15);
	window.draw(Rules);
	Logo.setPosition(200, 50);
	window.draw(Logo);
	Easy.setPosition(200, 310);
	window.draw(Easy);
	Medium.setPosition(205, 435);
	window.draw(Medium);
	Hard.setPosition(205, 560);
	window.draw(Hard);
}