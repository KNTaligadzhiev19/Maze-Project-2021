#include "../Header Files/FrontEnd.h"
#include "SFML/Graphics.hpp"
#include "../../Sign System/Header Files/RegistrationSystem.h"
#include "../../Sign System/Header Files/LoginSystem.h"
#include "../../Sign System/Header Files/SHA256.h"
#include "../../Maze Configuration/Header Files/EasyLevelMaze.h"
#include "../../Maze Configuration/Header Files/MediumLevelMaze.h"
#include "../../Maze Configuration/Header Files/HardLevelMaze.h"

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

	EasyLevelMaze* easyMaze = NULL;
	MediumLevelMaze* mediumMaze = NULL;
	HardLevelMaze* hardMaze = NULL;
};