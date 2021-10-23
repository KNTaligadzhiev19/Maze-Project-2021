#include "../Header Files/FrontEnd.h"
#include "../../Maze Configuration/Header Files/EasyLevelMaze.h"
#include "../../Maze Configuration/Header Files/MediumLevelMaze.h"
#include "../../Maze Configuration/Header Files/HardLevelMaze.h"
#include "../../Sign System/Header Files/RegistrationSystem.h"
#include "../../Sign System/Header Files/LoginSystem.h"
#include <iostream>
#include <iomanip>
#include <conio.h>

#define LEFT_UP_ANGLE 218
#define RIGHT_UP_ANGLE 191
#define LEFT_DOWN_ANGLE 192
#define RIGHT_DOWN_ANGLE 217
#define ROW_LINE 196
#define COLUMN_LINE 179

std::string printRowLine(char sign, int size)
{
	std::string wholeLine = "";
	for (int i = 0; i <= size; i++)
	{
		wholeLine += sign;
	}
	return wholeLine;
}

void inputLoginAndRegisterData(std::string &name, std::string &password)
{
	system("cls");

	std::cout << "\n\n" << std::setw(33) << char(LEFT_UP_ANGLE) << printRowLine(char(ROW_LINE), 30) << char(RIGHT_UP_ANGLE) << std::endl;
	std::cout << std::setw(33) << char(COLUMN_LINE) << std::setw(24) << "W E L C O M E !" << std::setw(8) << char(COLUMN_LINE) << std::endl;
	std::cout << std::setw(33) << char(LEFT_DOWN_ANGLE) << printRowLine(char(ROW_LINE), 30) << char(RIGHT_DOWN_ANGLE) << std::endl;
	std::cout << std::setw(33) << char(LEFT_UP_ANGLE) << printRowLine(char(ROW_LINE), 30) << char(RIGHT_UP_ANGLE) << std::endl;
	std::cout << std::setw(33) << char(COLUMN_LINE) << "  Enter a name: ";

	std::getline(std::cin, name);

	std::cout << std::setw(33) << char(LEFT_UP_ANGLE) << printRowLine(char(ROW_LINE), 30) << char(RIGHT_UP_ANGLE) << std::endl;
	std::cout << std::setw(33) << char(COLUMN_LINE) << "  Enter a password: ";

	std::getline(std::cin, password);
}

void printRules()
{
	std::cout << "\n\n" << std::setw(33) << char(LEFT_UP_ANGLE) << printRowLine(char(ROW_LINE), 30) << char(RIGHT_UP_ANGLE) << std::endl;
	std::cout << std::setw(33) << char(COLUMN_LINE) << std::setw(20) << "R U L E S" << std::setw(12) << char(COLUMN_LINE) << std::endl;
	std::cout << std::setw(33) << char(LEFT_DOWN_ANGLE) << printRowLine(char(ROW_LINE), 30) << char(RIGHT_DOWN_ANGLE) << std::endl;

	std::cout << std::setw(33) << char(LEFT_UP_ANGLE) << printRowLine(char(ROW_LINE), 30) << char(RIGHT_UP_ANGLE) << std::endl;
	std::cout << std::setw(33) << char(COLUMN_LINE) << std::setw(26) << "X  -  Your Position" << std::setw(6) << char(COLUMN_LINE) << std::endl;
	std::cout << std::setw(33) << char(COLUMN_LINE) << std::setw(22) << "Y  -  Your Goal" << std::setw(10) << char(COLUMN_LINE) << std::endl;
	std::cout << std::setw(33) << char(195) << printRowLine(char(ROW_LINE), 30) << char(180) << std::endl;

	std::cout << std::setw(33) << char(COLUMN_LINE) << std::setw(20) << "W  -  Move Up" << std::setw(12) << char(COLUMN_LINE) << std::endl;
	std::cout << std::setw(33) << char(COLUMN_LINE) << std::setw(22) << "A  -  Move Left" << std::setw(10) << char(COLUMN_LINE) << std::endl;
	std::cout << std::setw(33) << char(COLUMN_LINE) << std::setw(22) << "S  -  Move Down" << std::setw(10) << char(COLUMN_LINE) << std::endl;
	std::cout << std::setw(33) << char(COLUMN_LINE) << std::setw(23) << "D  -  Move Right" << std::setw(9) << char(COLUMN_LINE) << std::endl;
	std::cout << std::setw(33) << char(195) << char(ROW_LINE) << char(ROW_LINE) << char(ROW_LINE);
	std::cout << std::setw(26) << char(ROW_LINE) << char(ROW_LINE) << char(ROW_LINE) << char(180) << std::endl;
	std::cout << std::setw(33) << char(COLUMN_LINE) << std::setw(25) << "You can use Arrows" << std::setw(7) << char(COLUMN_LINE) << std::endl;
	std::cout << std::setw(33) << char(LEFT_DOWN_ANGLE) << printRowLine(char(ROW_LINE), 30) << char(RIGHT_DOWN_ANGLE) << std::endl;

	std::cout << std::setw(33) << char(LEFT_UP_ANGLE) << printRowLine(char(ROW_LINE), 30) << char(RIGHT_UP_ANGLE) << std::endl;
	std::cout << std::setw(33) << char(COLUMN_LINE) << std::setw(23) << "ESC - Leave Game" << std::setw(9) << char(COLUMN_LINE) << std::endl;
	std::cout << std::setw(33) << char(LEFT_DOWN_ANGLE) << printRowLine(char(ROW_LINE), 30) << char(RIGHT_DOWN_ANGLE) << std::endl;
}

//Function for moving around a menu
int returnChoice(char choice, int& position, std::vector<std::string>& options)
{

	switch (choice)
	{
	case 'S': case 's': case ARROW_DOWN:
		position++;
		if (position == options.size())
		{
			position = 0;
		}
		break;
	case 'W': case 'w': case ARROW_UP:
		position--;
		if (position == -1)
		{
			position = options.size() - 1;
		}
		break;
	case ENTER:
		return position;
	}

	return position;
}

int choice1 = 0;

void printMenu()
{
	std::vector<std::string> options = { " S I G N  U P ", " S I G N  I N " , " Q U I T " };
	std::vector<int> ident = { 22,22,19, 10,10,13 };
	std::vector<int> ident2 = { 8, 8, 10, 9, 9, 12 };
	int position = 0;

	while (true)
	{

		system("cls");
		std::cout << "\n\n\n\n\n\n" << std::setw(33) << char(218) << printRowLine(char(196), 30) << char(191) << std::endl;
		for (int i = 0; i < options.size(); i++)
		{
			if (position == i)
			{
				std::cout << std::setw(33) << char(179) << std::setw(ident2[i]) << char(175) << options[i] << char(174) << std::setw(ident2[i + 3]) << char(179) << std::endl;
			}
			else {
				std::cout << std::setw(33) << char(179) << std::setw(ident[i]) << options[i] << std::setw(ident[i + 3]) << char(179) << std::endl;
			}
		}
		std::cout << std::setw(33) << char(192) << printRowLine(char(196), 30) << char(217) << std::endl;

		//_getch() accepts a character
		char input = _getch();

		if (input != ENTER)
			returnChoice(input, position, options);

		else {
			choice1 = returnChoice(input, position, options);
			break;
		}
			
		

	}
}

int choice2;

void printGameMenu() 
{
	std::vector<std::string> options = { " Easy Level ", " Medium Level " , " Hard Level ", " Rules ", " Quit " };

	std::vector<int> ident = { 22,23,22, 19,18,10,9,10, 13,14 };
	std::vector<int> ident2 = { 10, 9, 10, 12, 12,9, 8, 9, 12, 13 };

	int position = 0;

	while (true)
	{
		system("cls");
		std::cout << "\n\n\n\n\n\n" << std::setw(33) << char(218) << printRowLine(char(196), 30) << char(191) << std::endl;
		for (int i = 0; i < options.size(); i++)
		{
			if (position == i)
			{
				std::cout << std::setw(33) << char(179) << std::setw(ident2[i]) << char(175) << options[i] << char(174) << std::setw(ident2[i + 5]) << char(179) << std::endl;
			}
			else {
				std::cout << std::setw(33) << char(179) << std::setw(ident[i]) << options[i] << std::setw(ident[i + 5]) << char(179) << std::endl;
			}
		}
		std::cout << std::setw(33) << char(192) << printRowLine(char(196), 30) << char(217) << std::endl;

		//_getch() accepts a character
		char input = _getch();

		if (input != ENTER)
		{
			returnChoice(input, position, options);
		}
		else {
			choice2 = returnChoice(input, position, options);
			break;
		}

	}
}

void printPlayerMenu()
{
	printGameMenu();

	switch (choice2)
	{
		//Case for easy level maze
		case 0:
		{
			EasyLevelMaze* easyMaze = new EasyLevelMaze;
			system("cls");
			easyMaze->startGame();

			delete easyMaze;
			printPlayerMenu();
			break;
		}
		//Case for medium level maze
		case 1:
		{
			MediumLevelMaze* mediumMaze = new MediumLevelMaze;
			system("cls");
			mediumMaze->startGame();

			delete mediumMaze;
			printPlayerMenu();
			break;
		}
		//Case for hard level maze
		case 2:
		{
			HardLevelMaze* hardMaze = new HardLevelMaze;
			system("cls");
			hardMaze->startGame();

			delete hardMaze;
			printPlayerMenu();
			break;
		}
		//Case for print rules
		case 3:
		{
			system("cls");
			printRules();
			std::cin.get();
			printPlayerMenu();
			break;
		}
		//Case for sign out
		case 4:
		{
			printUserMenu();
		}

	}
}

void printUserMenu()
{
	system("cls");

	RegistrationSystem* registration;
	LoginSystem* login;

	std::string* name = new std::string, * password = new std::string,* statsName=new std::string;
	printMenu();

	switch (choice1)
	{
		//Case for registrating a user
		case 0:
		{
			inputLoginAndRegisterData(*name, *password);
			registration = new RegistrationSystem(*name, *password);

			delete registration;
			delete name;
			delete password;
			printUserMenu();
			break;
		}
		//Case for loogin as a user
		case 1:
		{
			inputLoginAndRegisterData(*name, *password);
			*statsName = *name;
			login = new LoginSystem(*name, *password);

			//Checking for correct data
			if (login->checkLoginData())
			{
				delete login;
				delete name;
				delete password;
				printPlayerMenu();
			}
			//Otherwise
			else {
				delete login;
				delete name;
				delete password;
				printUserMenu();
			}
			
			break;
		}
		case 2:
		{
			exit(1);
		}
		
	}
}