#pragma once
#include <windows.h>
#include <string>
using namespace std;

enum KeyBinds {
	ENTER = 13,
	UP = 24,
	DOWN = 25,
	RIGHT = 26,
	LEFT = 27,
};

bool setColor(WORD newColor);

void printRules();

void printEnterChoice();

void printMenu();