#include "../Header Files/FrontEnd.h"
#include "SFML/Graphics.hpp"
#include "../../Sign System/Header Files/RegistrationSystem.h"
#include "../../Sign System/Header Files/LoginSystem.h"
#include "../../Sign System/Header Files/SHA256.h"
#include "../../Maze Configuration/Header Files/EasyLevelMaze.h"
#include "../../Maze Configuration/Header Files/MediumLevelMaze.h"
#include "../../Maze Configuration/Header Files/HardLevelMaze.h"

//Storing the check values which are used for controlling the temp of the program
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

	sf::String loginEmail;
	sf::String loginPassword;

	sf::String registerEmail;
	sf::String registerPassword;

	EasyLevelMaze* easyMaze = NULL;
	MediumLevelMaze* mediumMaze = NULL;
	HardLevelMaze* hardMaze = NULL;
};

void printMenu(sf::RenderWindow& window)
{
	sf::Texture t1, t2, t3;

	t1.loadFromFile("Images and Fonts/Login.png");
	t2.loadFromFile("Images and Fonts/Register.png");
	t3.loadFromFile("Images and Fonts/Logo.png");

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

void printLoginAndRegisterMenu(sf::RenderWindow& window)
{

	sf::Text loginText, passwordText;
	sf::Texture t1, t2, t3, t4, t5, t6;
	sf::Font myFont;
	myFont.loadFromFile("Images and Fonts/arial.ttf");

	t1.loadFromFile("Images and Fonts/Submit.png");
	t2.loadFromFile("Images and Fonts/Password.png");
	t3.loadFromFile("Images and Fonts/Email.png");
	t5.loadFromFile("Images and Fonts/WhiteSection.png");
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
		t6.loadFromFile("Images and Fonts/LoginTitle.png");
		t4.loadFromFile("Images and Fonts/LoginBack.png");
		loginText.setString(checkValues::loginEmail);
		passwordText.setString(checkValues::loginPassword);
	}

	else
	{
		t6.loadFromFile("Images and Fonts/RegisterTitle.png");
		t4.loadFromFile("Images and Fonts/RegisterBack.png");
		loginText.setString(checkValues::registerEmail);
		passwordText.setString(checkValues::registerPassword);
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

	t1.loadFromFile("Images and Fonts/EasyLevel.png");
	t2.loadFromFile("Images and Fonts/MediumLevel.png");
	t3.loadFromFile("Images and Fonts/HardLevel.png");
	t4.loadFromFile("Images and Fonts/Logo.png");
	t5.loadFromFile("Images and Fonts/Back.png");
	t6.loadFromFile("Images and Fonts/Rules.png");

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
			
			if ((sf::Mouse::getPosition(window).x >= 194 && sf::Mouse::getPosition(window).x <= 586) 
				&& (sf::Mouse::getPosition(window).y >= 329 && sf::Mouse::getPosition(window).y <= 387)) // Email
			{
				checkValues::emailCheck = true;
				checkValues::passwordCheck = false;
			}
			else if ((sf::Mouse::getPosition(window).x >= 194 && sf::Mouse::getPosition(window).x <= 586) 
				&& (sf::Mouse::getPosition(window).y >= 427 && sf::Mouse::getPosition(window).y <= 487)) // Password
			{
				checkValues::passwordCheck = true;
				checkValues::emailCheck = false;
			}
			else if ((sf::Mouse::getPosition(window).x >= 391 && sf::Mouse::getPosition(window).x <= 583) 
				&& (sf::Mouse::getPosition(window).y >= 226 && sf::Mouse::getPosition(window).y <= 283))
			{
				checkValues::userMenuEventClick = true;
				checkValues::loginAndRegisterEventClick = false;
				checkValues::status = 1;
				checkValues::emailCheck = false;
				checkValues::passwordCheck = false;
			}
			else if ((sf::Mouse::getPosition(window).x >= 194 && sf::Mouse::getPosition(window).x <= 584) 
				&& (sf::Mouse::getPosition(window).y >= 542 && sf::Mouse::getPosition(window).y <= 599)) // Submit and login
			{
				if (checkValues::logOrReg)
				{
					checkValues::loginPassword = sha256(checkValues::loginPassword);
					LoginSystem* login = new LoginSystem(checkValues::loginEmail, checkValues::loginPassword);

					if (login->checkLoginData())
					{
						delete login;
						checkValues::loginEmail = "";
						checkValues::loginPassword = "";
						checkValues::registerEmail = "";
						checkValues::registerPassword = "";
						checkValues::checkIn = true;
						checkValues::status = 4;
						checkValues::userMenuEventClick = false;
						checkValues::loginAndRegisterEventClick = false;
					}
					else {
						delete login;
						checkValues::loginPassword = "";
						window.clear(sf::Color(0, 128, 128));
					}
				}
				// Register
				else
				{
					RegistrationSystem* register1 = new RegistrationSystem(checkValues::registerEmail, checkValues::registerPassword, checkValues::userMenuEventClick, checkValues::loginAndRegisterEventClick, checkValues::status);
					delete register1;
					checkValues::registerEmail = "";
					checkValues::registerPassword = "";
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
			if (event1.text.unicode == '\b' && checkValues::loginEmail.getSize() > 0)
			{
				checkValues::loginEmail.erase(checkValues::loginEmail.getSize() - 1, 1);
			}
			else if (event1.text.unicode != '\b' && event1.text.unicode < 128 && checkValues::loginEmail.getSize() <= 21)
			{
				checkValues::loginEmail += static_cast<char>(event1.text.unicode);
				if (checkValues::loginEmail.getSize() >= 2 && checkValues::loginEmail[checkValues::loginEmail.getSize() - 1] == checkValues::loginEmail[checkValues::loginEmail.getSize() - 2])
				{
					checkValues::loginEmail.erase(checkValues::loginEmail.getSize() - 1, 1);
				}

			}
		}

	}

	if (checkValues::passwordCheck)
	{
		if (event1.type == sf::Event::TextEntered)
		{
			if (event1.text.unicode == '\b' && checkValues::loginPassword.getSize() > 0)
			{
				checkValues::loginPassword.erase(checkValues::loginPassword.getSize() - 1, 1);
			}
			else if (event1.text.unicode != '\b' && event1.text.unicode < 128 && checkValues::loginPassword.getSize() <= 18)
			{
				checkValues::loginPassword += static_cast<char>(event1.text.unicode);
				if (checkValues::loginPassword.getSize() >= 2 && checkValues::loginPassword[checkValues::loginPassword.getSize() - 1] == checkValues::loginPassword[checkValues::loginPassword.getSize() - 2])
				{
					checkValues::loginPassword.erase(checkValues::loginPassword.getSize() - 1, 1);
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
			if (event1.text.unicode == '\b' && checkValues::registerEmail.getSize() > 0)
			{
				checkValues::registerEmail.erase(checkValues::registerEmail.getSize() - 1, 1);
			}
			else if (event1.text.unicode != '\b' && event1.text.unicode < 128 && checkValues::registerEmail.getSize() <= 21)
			{
				checkValues::registerEmail += static_cast<char>(event1.text.unicode);
				if (checkValues::registerEmail.getSize() >= 2 && checkValues::registerEmail[checkValues::registerEmail.getSize() - 1] == checkValues::registerEmail[checkValues::registerEmail.getSize() - 2])
				{
					checkValues::registerEmail.erase(checkValues::registerEmail.getSize() - 1, 1);
				}

			}
		}

	}

	if (checkValues::passwordCheck)
	{
		if (event1.type == sf::Event::TextEntered)
		{
			if (event1.text.unicode == '\b' && checkValues::registerPassword.getSize() > 0)
			{
				checkValues::registerPassword.erase(checkValues::registerPassword.getSize() - 1, 1);
			}
			else if (event1.text.unicode != '\b' && event1.text.unicode < 128 && checkValues::registerPassword.getSize() <= 18)
			{
				checkValues::registerPassword += static_cast<char>(event1.text.unicode);
				if (checkValues::registerPassword.getSize() >= 2 && checkValues::registerPassword[checkValues::registerPassword.getSize() - 1] == checkValues::registerPassword[checkValues::registerPassword.getSize() - 2])
				{
					checkValues::registerPassword.erase(checkValues::registerPassword.getSize() - 1, 1);
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
			if ((sf::Mouse::getPosition(window).x >= 30 && sf::Mouse::getPosition(window).x <= 90) 
				&& (sf::Mouse::getPosition(window).y >= 14 && sf::Mouse::getPosition(window).y <= 75)) // Back
			{
				checkValues::status = 1;
				checkValues::userMenuEventClick = true;
				checkValues::loginAndRegisterEventClick = false;
				checkValues::checkIn = false;
			}
			
			else if ((sf::Mouse::getPosition(window).x >= 702 && sf::Mouse::getPosition(window).x <= 751) 
				&& (sf::Mouse::getPosition(window).y >= 17 && sf::Mouse::getPosition(window).y <= 74)) // Rules
			{
				checkValues::status = 5;
				checkValues::printableRulesTable = true;
				checkValues::userMenuEventClick = false;
				checkValues::loginAndRegisterEventClick = false;
				checkValues::checkIn = false;
			}
			
			else if ((sf::Mouse::getPosition(window).x >= 210 && sf::Mouse::getPosition(window).x <= 585) 
				&& (sf::Mouse::getPosition(window).y >= 318 && sf::Mouse::getPosition(window).y <= 422)) // Easy level maze
			{
				checkValues::modeChoice = 1;
				checkValues::status = 6;
				checkValues::printableRulesTable = false;
				checkValues::userMenuEventClick = false;
				checkValues::loginAndRegisterEventClick = false;
				checkValues::checkIn = false;
				checkValues::inGame = true;
			}
			
			else if ((sf::Mouse::getPosition(window).x >= 210 && sf::Mouse::getPosition(window).x <= 585) 
				&& (sf::Mouse::getPosition(window).y >= 446 && sf::Mouse::getPosition(window).y <= 550)) // Medium level maze
			{
				checkValues::modeChoice = 2;
				checkValues::status = 7;
				checkValues::printableRulesTable = false;
				checkValues::userMenuEventClick = false;
				checkValues::loginAndRegisterEventClick = false;
				checkValues::checkIn = false;
				checkValues::inGame = true;
			}
			
			else if ((sf::Mouse::getPosition(window).x >= 210 && sf::Mouse::getPosition(window).x <= 585) 
				&& (sf::Mouse::getPosition(window).y >= 571 && sf::Mouse::getPosition(window).y <= 673)) // Hard level maze
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
	t1.loadFromFile("Images and Fonts/RulesTable.png");

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

void printCongratsMenu(sf::RenderWindow& window)
{
	sf::Texture t1, t2;

	t1.loadFromFile("Images and Fonts/CongratulationsMessage.png");
	t2.loadFromFile("Images and Fonts/Continue.png");
	sf::Sprite Congrats(t1);
	sf::Sprite Continue(t2);

	window.clear(sf::Color(0, 128, 128));

	Congrats.setPosition(60, 100);
	window.draw(Congrats);
	Continue.setPosition(230, 600);
	window.draw(Continue);
}

void onClickCongratsMenu(sf::RenderWindow& window, sf::Event& event1)
{
	while (window.pollEvent(event1))
	{
		if (event1.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event1.key.code == sf::Mouse::Left && event1.type == sf::Event::MouseButtonPressed)
		{
			if ((sf::Mouse::getPosition(window).x >= 239 && sf::Mouse::getPosition(window).x <= 571) && (sf::Mouse::getPosition(window).y >= 609 && sf::Mouse::getPosition(window).y <= 685))
			{
				checkValues::status = 4;
				checkValues::inGame = false;
				checkValues::inCongratsTable = false;
				checkValues::checkIn = true;
			}
		}

	}
}

void setDataValue()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "The Runners - Maze");

	while (window.isOpen())
	{
		sf::Event event1;

		if (checkValues::userMenuEventClick)
		{
			onClickUserMenu(window, event1);
		}

		if (checkValues::loginAndRegisterEventClick)
		{
			onClickLoginAndRegister(window, event1);
		}

		if (checkValues::checkIn)
		{
			onClickPlayerMenu(window, event1);
			if (checkValues::modeChoice == 1)
			{
				checkValues::easyMaze = new EasyLevelMaze;
			}
			else if (checkValues::modeChoice == 2)
			{
				checkValues::mediumMaze = new MediumLevelMaze;
			}
			else if (checkValues::modeChoice == 3)
			{
				checkValues::hardMaze = new HardLevelMaze;
			}
		}

		if (checkValues::printableRulesTable)
		{
			onClickRulesTable(window, event1);
		}

		if (checkValues::inGame)
		{
			if (checkValues::modeChoice == 1)
			{
				checkValues::easyMaze->moveOnClick(window, event1, checkValues::status, checkValues::inGame, checkValues::inCongratsTable, checkValues::modeChoice);
			}
			else if (checkValues::modeChoice == 2)
			{
				checkValues::mediumMaze->moveOnClick(window, event1, checkValues::status, checkValues::inGame, checkValues::inCongratsTable, checkValues::modeChoice);
			}
			else if (checkValues::modeChoice == 3)
			{
				checkValues::hardMaze->moveOnClick(window, event1, checkValues::status, checkValues::inGame, checkValues::inCongratsTable, checkValues::modeChoice);
			}
		}

		if (checkValues::inCongratsTable)
		{
			onClickCongratsMenu(window, event1);
			if (checkValues::modeChoice == 1)
			{
				delete checkValues::easyMaze;
			}
			else if (checkValues::modeChoice == 2)
			{
				delete checkValues::mediumMaze;
			}
			else if (checkValues::modeChoice == 3)
			{
				delete checkValues::hardMaze;
			}
		}

		switch (checkValues::status)
		{
		case 1:
			window.clear(sf::Color(0, 128, 128));
			printMenu(window);
			break;
		case 2: // Login
			checkValues::logOrReg = true;
			window.clear(sf::Color(0, 128, 128));
			printLoginAndRegisterMenu(window);
			inputLoginData(window, event1);
			break;
		case 3: // Register
			checkValues::logOrReg = false;
			window.clear(sf::Color(0, 128, 128));
			printLoginAndRegisterMenu(window);
			inputRegisterData(window, event1);
			break;
		case 4:
			printPlayerMenu(window);
			break;
		case 5:
			printRulesTable(window);
			break;
		case 6: // Easy level
			
			window.clear(sf::Color(0, 128, 128));
			checkValues::easyMaze->printMaze(window);
			break;
		case 7: // Medium level
			window.clear(sf::Color(0, 128, 128));
			checkValues::mediumMaze->printMaze(window);
			break;
		case 8: // Hard level maze
			window.clear(sf::Color(0, 128, 128));
			checkValues::hardMaze->printMaze(window);
			break;
		case 9: // After finishing the maze
			printCongratsMenu(window);
			break;
		}

		window.display();
	}
}