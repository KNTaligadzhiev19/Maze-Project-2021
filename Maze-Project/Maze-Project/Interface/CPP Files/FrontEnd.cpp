#include "../Header Files/FrontEnd.h"
#include "../../Maze Configuration/Header Files/EasyLevelMaze.h"
#include "../../Maze Configuration/Header Files/MediumLevelMaze.h"
#include "../../Maze Configuration/Header Files/HardLevelMaze.h"
#include "../../Sign System/Header Files/RegistrationSystem.h"
#include "../../Sign System/Header Files/LoginSystem.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <conio.h>

using namespace std;

#define LEFT_UP_ANGLE 218
#define RIGHT_UP_ANGLE 191
#define LEFT_DOWN_ANGLE 192
#define RIGHT_DOWN_ANGLE 217
#define ROW_LINE 196
#define COLUMN_LINE 179

string printRowLine(char sign, int size)
{
	string wholeLine = "";
	for (int i = 0; i <= size; i++)
	{
		wholeLine += sign;
	}
	return wholeLine;
}

void inputLoginAndRegisterData(string& name, string& password)
{
	system("cls");

	cout << "\n\n" << setw(33) << char(LEFT_UP_ANGLE) << printRowLine(char(ROW_LINE), 30) << char(RIGHT_UP_ANGLE) << endl;
	cout << setw(33) << char(COLUMN_LINE) << setw(24) << "W E L C O M E !" << setw(8) << char(COLUMN_LINE) << endl;
	cout << setw(33) << char(LEFT_DOWN_ANGLE) << printRowLine(char(ROW_LINE), 30) << char(RIGHT_DOWN_ANGLE) << endl;
	cout << setw(33) << char(LEFT_UP_ANGLE) << printRowLine(char(ROW_LINE), 30) << char(RIGHT_UP_ANGLE) << endl;
	cout << setw(33) << char(COLUMN_LINE) << "  Enter a name: ";

	getline(cin, name);

	cout << setw(33) << char(LEFT_UP_ANGLE) << printRowLine(char(ROW_LINE), 30) << char(RIGHT_UP_ANGLE) << endl;
	cout << setw(33) << char(COLUMN_LINE) << "  Enter a password: ";

	getline(cin, password);
}



void printRules()
{
	cout << "\n\n" << setw(33) << char(LEFT_UP_ANGLE) << printRowLine(char(ROW_LINE), 30) << char(RIGHT_UP_ANGLE) << endl;
	cout << setw(33) << char(COLUMN_LINE) << setw(20) << "R U L E S" << setw(12) << char(COLUMN_LINE) << endl;
	cout << setw(33) << char(LEFT_DOWN_ANGLE) << printRowLine(char(ROW_LINE), 30) << char(RIGHT_DOWN_ANGLE) << endl;

	cout << setw(33) << char(LEFT_UP_ANGLE) << printRowLine(char(ROW_LINE), 30) << char(RIGHT_UP_ANGLE) << endl;
	cout << setw(33) << char(COLUMN_LINE) << setw(26) << "X  -  Your Position" << setw(6) << char(COLUMN_LINE) << endl;
	cout << setw(33) << char(COLUMN_LINE) << setw(22) << "Y  -  Your Goal" << setw(10) << char(COLUMN_LINE) << endl;
	cout << setw(33) << char(195) << printRowLine(char(ROW_LINE), 30) << char(180) << endl;

	cout << setw(33) << char(COLUMN_LINE) << setw(20) << "W  -  Move Up" << setw(12) << char(COLUMN_LINE) << endl;
	cout << setw(33) << char(COLUMN_LINE) << setw(22) << "A  -  Move Left" << setw(10) << char(COLUMN_LINE) << endl;
	cout << setw(33) << char(COLUMN_LINE) << setw(22) << "S  -  Move Down" << setw(10) << char(COLUMN_LINE) << endl;
	cout << setw(33) << char(COLUMN_LINE) << setw(23) << "D  -  Move Right" << setw(9) << char(COLUMN_LINE) << endl;
	cout << setw(33) << char(195) << char(ROW_LINE) << char(ROW_LINE) << char(ROW_LINE);
	cout << setw(26) << char(ROW_LINE) << char(ROW_LINE) << char(ROW_LINE) << char(180) << endl;
	cout << setw(33) << char(COLUMN_LINE) << setw(25) << "You can use Arrows" << setw(7) << char(COLUMN_LINE) << endl;
	cout << setw(33) << char(LEFT_DOWN_ANGLE) << printRowLine(char(ROW_LINE), 30) << char(RIGHT_DOWN_ANGLE) << endl;

	cout << setw(33) << char(LEFT_UP_ANGLE) << printRowLine(char(ROW_LINE), 30) << char(RIGHT_UP_ANGLE) << endl;
	cout << setw(33) << char(COLUMN_LINE) << setw(23) << "ESC - Leave Game" << setw(9) << char(COLUMN_LINE) << endl;
	cout << setw(33) << char(LEFT_DOWN_ANGLE) << printRowLine(char(ROW_LINE), 30) << char(RIGHT_DOWN_ANGLE) << endl;
}

int returnChoice(char choice, int& position, vector<string>& options)
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
	vector<string> options = { " S I G N  U P ", " S I G N  I N " , " Q U I T " };
	vector<int> ident = { 22,22,19, 10,10,13 };
	vector<int> ident2 = { 8, 8, 10, 9, 9, 12 };
	int position = 0;

	while (true)
	{

		system("cls");
		cout << "\n\n\n\n\n\n" << setw(33) << char(218) << printRowLine(char(196), 30) << char(191) << endl;
		for (int i = 0; i < options.size(); i++)
		{
			if (position == i)
			{
				cout << setw(33) << char(179) << setw(ident2[i]) << char(175) << options[i] << char(174) << setw(ident2[i + 3]) << char(179) << endl;
			}
			else {
				cout << setw(33) << char(179) << setw(ident[i]) << options[i] << setw(ident[i + 3]) << char(179) << endl;
			}
		}
		cout << setw(33) << char(192) << printRowLine(char(196), 30) << char(217) << endl;

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
	vector<string> options = { " Easy Level ", " Medium Level " , " Hard Level ", " Stats ", " Rules ", " Quit " };

	vector<int> ident = { 22,23,22, 19,19,18,10,9,10, 13,13,14 };
	vector<int> ident2 = { 10, 9, 10, 12, 12, 12,9, 8, 9, 12, 12, 13 };

	int position = 0;

	while (true)
	{
		system("cls");
		cout << "\n\n\n\n\n\n" << setw(33) << char(218) << printRowLine(char(196), 30) << char(191) << endl;
		for (int i = 0; i < options.size(); i++)
		{
			if (position == i)
			{
				cout << setw(33) << char(179) << setw(ident2[i]) << char(175) << options[i] << char(174) << setw(ident2[i + 6]) << char(179) << endl;
			}
			else {
				cout << setw(33) << char(179) << setw(ident[i]) << options[i] << setw(ident[i + 6]) << char(179) << endl;
			}
		}
		cout << setw(33) << char(192) << printRowLine(char(196), 30) << char(217) << endl;

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
		case 0:
		{
			EasyLevelMaze* easyMaze = new EasyLevelMaze;
			system("cls");
			easyMaze->startGame();

			delete easyMaze;
			printPlayerMenu();
			break;
		}
		case 1:
		{
			MediumLevelMaze* mediumMaze = new MediumLevelMaze;
			system("cls");
			mediumMaze->startGame();

			delete mediumMaze;
			printPlayerMenu();
			break;
		}
		case 2:
		{
			HardLevelMaze* hardMaze = new HardLevelMaze;
			system("cls");
			hardMaze->startGame();

			delete hardMaze;
			printPlayerMenu();
			break;
		}
		case 3:
		{
			//Unavailable
			break;
		}
		case 4:
		{
			system("cls");
			printRules();
			cin.get();
			printPlayerMenu();
			break;
		}
		case 5:
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

	string* name = new string, * password = new string;
	printMenu();

	switch (choice1)
	{
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
		case 1:
		{
			inputLoginAndRegisterData(*name, *password);
			login = new LoginSystem(*name, *password);

			if (login->checkLoginData())
			{
				delete login;
				delete name;
				delete password;
				printPlayerMenu();
			}
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