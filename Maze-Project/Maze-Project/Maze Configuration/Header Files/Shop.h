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

public:

	void safeCoinData();

	class StartFigure {

	};

	class EndFigure {

	};

	class Background {

	};
};

