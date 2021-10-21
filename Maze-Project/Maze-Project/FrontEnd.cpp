#include "FrontEnd.h"
#include <iostream>
#include <iomanip>
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


