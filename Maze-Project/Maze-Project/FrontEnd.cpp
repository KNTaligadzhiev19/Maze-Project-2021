#include "FrontEnd.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <conio.h>
using namespace std;

bool setColor(WORD newColor)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hStdOut != INVALID_HANDLE_VALUE)
	{
		return SetConsoleTextAttribute(hStdOut, newColor);
	}

	return false;
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
	cout << setw(33) << colLine << setw(25) << "You can use Buttons" << setw(7) << colLine << endl;
	cout << setw(33) << angle[2] << printRowLine(rowLine) << angle[3] << endl;

	cout << setw(33) << angle[0] << printRowLine(rowLine) << angle[1] << endl;
	cout << setw(33) << colLine << setw(23) << "ESC - Leave Game" << setw(9) << colLine << endl;
	cout << setw(33) << angle[2] << printRowLine(rowLine) << angle[3] << endl;
}

int returnChoice(char choice, int& position, vector<string>& options)
{

	switch (choice)
	{
	case 'S': case 's': case DOWN:
		position++;
		if (position == options.size())
		{
			position = 0;
		}
		break;
	case 'W':
		position--;
		if (position == -1)
		{
			position = options.size() - 1;
		}
		break;
	}

	return position;
}

void printEnterChoice()
{
	cout << 1;
}

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
		{
			returnChoice(input, position, options);
		}
		else {
			printEnterChoice();
			//exit(1);
		}

	}
}

void printGameMenu() {
	vector<string> options = { " Easy Level ", " Medium Level " , " Hard Level ", " Stats ", " Rules ", " Quit " };
	vector<int> ident = {
		22,23,22, 19,19,18,
		10,9,10, 13,13,14 };

	vector<int> ident2 = {
		10, 9, 10, 12, 12, 12,
		9, 8, 9, 12, 12, 13 };

	int position = 0;

	//Function 1
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
			printEnterChoice();
			//exit(1);
		}
	}
}