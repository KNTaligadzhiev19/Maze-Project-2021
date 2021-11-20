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

	//Integer as a counter for setting what difficulty of level player will play
	int level = 0;

public:

	void safeCoinData();

	class Symbols 
	{
		public:
		std::ifstream statusDataIn;
		std::ofstream statusDataOut;
		sf::Texture  t2, t3,t4;
		int symbolStatus = 1;
		int level = 0;

		void safeSymbolStatusData();

		void chooseSymb();
	};

	void levelSetter();

	Symbols symbol;

	class Background 
	{
		public:
		int backgroundStatus = 1;
		std::ifstream statusDataIn;
		std::ofstream statusDataOut;
		sf::Texture t1;
		int level = 0;

		void safeBackgroundStatusData();

		void chooseBackground();
	};

	Background background;
};

