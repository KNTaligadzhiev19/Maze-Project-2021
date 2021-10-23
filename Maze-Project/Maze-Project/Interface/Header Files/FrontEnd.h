#pragma once
#include <windows.h>
#include <string>

//Key Binds for entering data in a menu
enum KeyBinds {
	ENTER = 13,
	ARROW_LEFT = 75,
	ARROW_RIGHT = 77,
	ARROW_UP = 72,
	ARROW_DOWN = 80,
};

void inputLoginAndRegisterData(std::string& name, std::string& password);

void printRules();

void printMenu();

void printGameMenu();

void printPlayerMenu();

void printUserMenu();