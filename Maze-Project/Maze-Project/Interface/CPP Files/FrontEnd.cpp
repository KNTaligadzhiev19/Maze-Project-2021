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

void onClickUserMenu(sf::RenderWindow& window, sf::Event& event1)
{

	while (window.pollEvent(event1))
	{
		if (event1.type == sf::Event::Closed)
		{
			window.close();
		}
		if (event1.key.code == sf::Mouse::Left && event1.type == sf::Event::MouseButtonPressed)
		{
			if ((sf::Mouse::getPosition(window).x >= 303 && sf::Mouse::getPosition(window).x <= 501) && (sf::Mouse::getPosition(window).y >= 392 && sf::Mouse::getPosition(window).y <= 456))
			{
				checkValues::status = 2;
				checkValues::userMenuEventClick = false;
				checkValues::loginAndRegisterEventClick = true;
			}
			else if ((sf::Mouse::getPosition(window).x >= 303 && sf::Mouse::getPosition(window).x <= 501) && (sf::Mouse::getPosition(window).y >= 504 && sf::Mouse::getPosition(window).y <= 568))
			{
				checkValues::status = 3;
				checkValues::userMenuEventClick = false;
				checkValues::loginAndRegisterEventClick = true;
			}
		}
	}
}

void onClickLoginAndRegister(sf::RenderWindow& window, sf::Event& event1)
{
	while (window.pollEvent(event1))
	{
		if (event1.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event1.key.code == sf::Mouse::Left && event1.type == sf::Event::MouseButtonPressed)
		{
			if ((sf::Mouse::getPosition(window).x >= 194 && sf::Mouse::getPosition(window).x <= 586) && (sf::Mouse::getPosition(window).y >= 329 && sf::Mouse::getPosition(window).y <= 387))
			{
				checkValues::emailCheck = true;
				checkValues::passwordCheck = false;
			}

			else if ((sf::Mouse::getPosition(window).x >= 194 && sf::Mouse::getPosition(window).x <= 586) && (sf::Mouse::getPosition(window).y >= 427 && sf::Mouse::getPosition(window).y <= 487))
			{
				checkValues::passwordCheck = true;
				checkValues::emailCheck = false;
			}
			else if ((sf::Mouse::getPosition(window).x >= 391 && sf::Mouse::getPosition(window).x <= 583) && (sf::Mouse::getPosition(window).y >= 226 && sf::Mouse::getPosition(window).y <= 283))
			{
				checkValues::userMenuEventClick = true;
				checkValues::loginAndRegisterEventClick = false;
				checkValues::status = 1;
				checkValues::emailCheck = false;
				checkValues::passwordCheck = false;
			}
			else if ((sf::Mouse::getPosition(window).x >= 194 && sf::Mouse::getPosition(window).x <= 584) && (sf::Mouse::getPosition(window).y >= 542 && sf::Mouse::getPosition(window).y <= 599))
			{
				if (checkValues::logOrReg)
				{
					loginPassword = sha256(loginPassword);
					LoginSystem* login = new LoginSystem(loginEmail, loginPassword);

					if (login->checkLoginData())
					{
						delete login;
						loginEmail = "";
						loginPassword = "";
						registerEmail = "";
						registerPassword = "";
						checkValues::checkIn = true;
						checkValues::status = 4;
						checkValues::userMenuEventClick = false;
						checkValues::loginAndRegisterEventClick = false;
					}
					else {
						delete login;
						loginPassword = "";
						window.clear(sf::Color(0, 128, 128));
					}
				}
				
				else
				{
					RegistrationSystem* register1 = new RegistrationSystem(registerEmail, registerPassword, checkValues::userMenuEventClick, checkValues::loginAndRegisterEventClick, checkValues::status);
					delete register1;
					registerEmail = "";
					registerPassword = "";
					window.clear(sf::Color(0, 128, 128));
				}

			}
			else {
				checkValues::emailCheck = false;
				checkValues::passwordCheck = false;
			}
		}
	}
}

void inputLoginData(sf::RenderWindow& window, sf::Event& event1)
{

	if (checkValues::emailCheck)
	{
		if (event1.type == sf::Event::TextEntered)
		{
			if (event1.text.unicode == '\b' && loginEmail.getSize() > 0)
			{
				loginEmail.erase(loginEmail.getSize() - 1, 1);
			}
			else if (event1.text.unicode != '\b' && event1.text.unicode < 128 && loginEmail.getSize() <= 21)
			{
				loginEmail += static_cast<char>(event1.text.unicode);
				if (loginEmail.getSize() >= 2 && loginEmail[loginEmail.getSize() - 1] == loginEmail[loginEmail.getSize() - 2])
				{
					loginEmail.erase(loginEmail.getSize() - 1, 1);
				}

			}
		}

	}

	if (checkValues::passwordCheck)
	{
		if (event1.type == sf::Event::TextEntered)
		{
			if (event1.text.unicode == '\b' && loginPassword.getSize() > 0)
			{
				loginPassword.erase(loginPassword.getSize() - 1, 1);
			}
			else if (event1.text.unicode != '\b' && event1.text.unicode < 128 && loginPassword.getSize() <= 18)
			{
				loginPassword += static_cast<char>(event1.text.unicode);
				if (loginPassword.getSize() >= 2 && loginPassword[loginPassword.getSize() - 1] == loginPassword[loginPassword.getSize() - 2])
				{
					loginPassword.erase(loginPassword.getSize() - 1, 1);
				}

			}
		}

	}
}

void inputRegisterData(sf::RenderWindow& window, sf::Event& event1)
{

	if (checkValues::emailCheck)
	{
		if (event1.type == sf::Event::TextEntered)
		{
			if (event1.text.unicode == '\b' && registerEmail.getSize() > 0)
			{
				registerEmail.erase(registerEmail.getSize() - 1, 1);
			}
			else if (event1.text.unicode != '\b' && event1.text.unicode < 128 && registerEmail.getSize() <= 21)
			{
				registerEmail += static_cast<char>(event1.text.unicode);
				if (registerEmail.getSize() >= 2 && registerEmail[registerEmail.getSize() - 1] == registerEmail[registerEmail.getSize() - 2])
				{
					registerEmail.erase(registerEmail.getSize() - 1, 1);
				}

			}
		}

	}

	if (checkValues::passwordCheck)
	{
		if (event1.type == sf::Event::TextEntered)
		{
			if (event1.text.unicode == '\b' && registerPassword.getSize() > 0)
			{
				registerPassword.erase(registerPassword.getSize() - 1, 1);
			}
			else if (event1.text.unicode != '\b' && event1.text.unicode < 128 && registerPassword.getSize() <= 18)
			{
				registerPassword += static_cast<char>(event1.text.unicode);
				if (registerPassword.getSize() >= 2 && registerPassword[registerPassword.getSize() - 1] == registerPassword[registerPassword.getSize() - 2])
				{
					registerPassword.erase(registerPassword.getSize() - 1, 1);
				}

			}
		}

	}
}

void onClickPlayerMenu(sf::RenderWindow& window, sf::Event& event1)
{
	while (window.pollEvent(event1))
	{
		if (event1.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event1.key.code == sf::Mouse::Left && event1.type == sf::Event::MouseButtonPressed)
		{
			if ((sf::Mouse::getPosition(window).x >= 30 && sf::Mouse::getPosition(window).x <= 90) && (sf::Mouse::getPosition(window).y >= 14 && sf::Mouse::getPosition(window).y <= 75))
			{
				checkValues::status = 1;
				checkValues::userMenuEventClick = true;
				checkValues::loginAndRegisterEventClick = false;
				checkValues::checkIn = false;
			}
			
			else if ((sf::Mouse::getPosition(window).x >= 702 && sf::Mouse::getPosition(window).x <= 751) && (sf::Mouse::getPosition(window).y >= 17 && sf::Mouse::getPosition(window).y <= 74))
			{
				checkValues::status = 5;
				checkValues::printableRulesTable = true;
				checkValues::userMenuEventClick = false;
				checkValues::loginAndRegisterEventClick = false;
				checkValues::checkIn = false;
			}
			
			else if ((sf::Mouse::getPosition(window).x >= 210 && sf::Mouse::getPosition(window).x <= 585) && (sf::Mouse::getPosition(window).y >= 318 && sf::Mouse::getPosition(window).y <= 422))
			{
				checkValues::modeChoice = 1;
				checkValues::status = 6;
				checkValues::printableRulesTable = false;
				checkValues::userMenuEventClick = false;
				checkValues::loginAndRegisterEventClick = false;
				checkValues::checkIn = false;
				checkValues::inGame = true;
			}
			
			else if ((sf::Mouse::getPosition(window).x >= 210 && sf::Mouse::getPosition(window).x <= 585) && (sf::Mouse::getPosition(window).y >= 446 && sf::Mouse::getPosition(window).y <= 550))
			{
				checkValues::modeChoice = 2;
				checkValues::status = 7;
				checkValues::printableRulesTable = false;
				checkValues::userMenuEventClick = false;
				checkValues::loginAndRegisterEventClick = false;
				checkValues::checkIn = false;
				checkValues::inGame = true;
			}
			
			else if ((sf::Mouse::getPosition(window).x >= 210 && sf::Mouse::getPosition(window).x <= 585) && (sf::Mouse::getPosition(window).y >= 571 && sf::Mouse::getPosition(window).y <= 673))
			{
				checkValues::modeChoice = 3;
				checkValues::status = 8;
				checkValues::printableRulesTable = false;
				checkValues::userMenuEventClick = false;
				checkValues::loginAndRegisterEventClick = false;
				checkValues::checkIn = false;
				checkValues::inGame = true;
			}
		}
	}
}

void printRulesTable(sf::RenderWindow& window)
{
	window.clear(sf::Color(0, 128, 128));

	sf::Texture t1;
	t1.loadFromFile("RulesTable.png");

	sf::Sprite Rules(t1);

	Rules.setPosition(200, 160);
	window.draw(Rules);
}

void onClickRulesTable(sf::RenderWindow& window, sf::Event& event1)
{
	while (window.pollEvent(event1))
	{
		if (event1.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event1.key.code == sf::Mouse::Left && event1.type == sf::Event::MouseButtonPressed)
		{
			if ((sf::Mouse::getPosition(window).x >= 212 && sf::Mouse::getPosition(window).x <= 611) && (sf::Mouse::getPosition(window).y >= 486 && sf::Mouse::getPosition(window).y <= 547))
			{
				checkValues::userMenuEventClick = false;
				checkValues::loginAndRegisterEventClick = false;
				checkValues::checkIn = true;
				checkValues::printableRulesTable = false;
				checkValues::status = 4;
			}
		}
	}
}