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

void inputLoginAndRegisterData(string& name, string& password);

void printRules();

void printMenu();

void printGameMenu();

void printPlayerMenu();

void printUserMenu();