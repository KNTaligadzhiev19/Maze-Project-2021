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

void inputLoginAndRegisterData(string& name, string& password)
{
	system("cls");
	char passSymbol;
	cout << "Enter a name: ";
	for (int i = 0;;) {
		char passSymbol = _getch();
		if (i == 0 && passSymbol > 90) {
			cout << char(passSymbol - 32);
		}
		else {
			cout << passSymbol;
		}
		if (passSymbol == ENTER) {
			break;
		}
		i++;
	}
	
	cout << "\nEnter a password: "; getline(cin, password);
	
	

}

string printRowLine(char sign)
{
	string wholeLine = "";
	for (int i = 0; i <= 30; i++)
	{
		wholeLine += sign;
	}
	return wholeLine;
}

void printRules()
{
	char angle[4] = { char(218), char(191), char(192), char(217) };
	char rowLine = char(196), colLine = char(179);

	cout << "\n\n" << setw(33) << angle[0] << printRowLine(rowLine) << angle[1] << endl;
	cout << setw(33) << colLine << setw(20) << "R U L E S" << setw(12) << colLine << endl;
	cout << setw(33) << angle[2] << printRowLine(rowLine) << angle[3] << endl;

	cout << setw(33) << angle[0] << printRowLine(rowLine) << angle[1] << endl;
	cout << setw(33) << colLine << setw(26) << "X  -  Your Position" << setw(6) << colLine << endl;
	cout << setw(33) << colLine << setw(22) << "Y  -  Your Goal" << setw(10) << colLine << endl;
	cout << setw(33) << char(195) << printRowLine(rowLine) << char(180) << endl;

	cout << setw(33) << colLine << setw(20) << "W  -  Move Up" << setw(12) << colLine << endl;
	cout << setw(33) << colLine << setw(22) << "A  -  Move Left" << setw(10) << colLine << endl;
	cout << setw(33) << colLine << setw(22) << "S  -  Move Down" << setw(10) << colLine << endl;
	cout << setw(33) << colLine << setw(23) << "D  -  Move Right" << setw(9) << colLine << endl;
	cout << setw(33) << char(195) << rowLine << rowLine << rowLine;
	cout << setw(26) << rowLine << rowLine << rowLine << char(180) << endl;
	cout << setw(33) << colLine << setw(25) << "You can use Arrows" << setw(7) << colLine << endl;
	cout << setw(33) << angle[2] << printRowLine(rowLine) << angle[3] << endl;

	cout << setw(33) << angle[0] << printRowLine(rowLine) << angle[1] << endl;
	cout << setw(33) << colLine << setw(23) << "ESC - Leave Game" << setw(9) << colLine << endl;
	cout << setw(33) << angle[2] << printRowLine(rowLine) << angle[3] << endl;
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
		cout << "\n\n\n\n\n\n" << setw(33) << char(218) << printRowLine(char(196)) << char(191) << endl;
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
		cout << setw(33) << char(192) << printRowLine(char(196)) << char(217) << endl;

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
		cout << "\n\n\n\n\n\n" << setw(33) << char(218) << printRowLine(char(196)) << char(191) << endl;
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
		cout << setw(33) << char(192) << printRowLine(char(196)) << char(217) << endl;

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