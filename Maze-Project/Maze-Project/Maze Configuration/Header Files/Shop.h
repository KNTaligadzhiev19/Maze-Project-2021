#pragma once
#pragma once
#include <string>
#include <fstream>
#include "SFML/Graphics.hpp"

class Shop
{
protected:
	std::ifstream statusDataIn;
	std::ofstream statusDataOut;

	int coins=0;
	
	int symbolStatus=1;

	int backgroundStatus=1;

	sf::Texture t1, t2, t3, t4;

	//Integer as a counter for setting what difficulty of level player will play
	int level = 0;

public:

	void safeCoinData();

	void safeSymbolStatusData();

	void safeBackgroundStatusData();

	void chooseSymb();

	//void chooseBackground();

	class Symbols {

	};

	class Background {

	};
};

