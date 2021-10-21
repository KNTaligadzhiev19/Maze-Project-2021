#pragma once
#include <windows.h>
#include <string>
using namespace std;

enum KeyBinds {
	ENTER = 13,
	ARROW_LEFT = 75,
	ARROW_RIGHT = 77,
	ARROW_UP = 72,
	ARROW_DOWN = 80,
};

bool setColor(WORD newColor);

void printRules();

void printEnterChoice();

void printMenu();

void printGameMenu();