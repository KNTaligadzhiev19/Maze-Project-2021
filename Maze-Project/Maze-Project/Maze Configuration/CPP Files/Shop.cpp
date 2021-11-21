#include "../Header Files/Shop.h"
#include "../../Interface/Header Files/FrontEnd.h"
#include <iostream>

void Shop::safeCoinData()
{
	statusDataIn.open("Owned Figures.txt", std::ios::in | std::ios::app);

	sf::String email = returnSafeEmail();

	std::vector<std::string> v1;

	if (statusDataIn.is_open())
	{
		std::string text,text1;

		while (getline(statusDataIn, text))
		{
			v1.push_back(text);
		}

		for (size_t i = 0; i < v1.size(); i++)
		{
			if (v1.at(i) == email)
			{
				v1.at(i + 1).erase(v1.at(i + 1).find("Coins:"), 7);
				coins = std::stoi(v1.at(i + 1));
			}
		}
	}

	statusDataIn.close();
}

void Shop::Symbols::safeSymbolStatusData()
{
	statusDataIn.open("Owned Figures.txt", std::ios::in | std::ios::app);

	sf::String email = returnSafeEmail();

	std::vector<std::string> v1;

	if (statusDataIn.is_open())
	{
		std::string text;

		while (getline(statusDataIn, text))
		{
			v1.push_back(text);
		}

		for (size_t i = 0; i < v1.size(); i++)
		{
			if (v1.at(i) == email)
			{
				v1.at(i+2).erase(v1.at(i+2).find("Symbol:"), 8);
				symbolStatus = std::stoi(v1.at(i+2));
			}
		}
	}

	statusDataIn.close();
}

void Shop::Background::safeBackgroundStatusData()
{
	statusDataIn.open("Status User Data.txt", std::ios::in | std::ios::app);

	sf::String email = returnSafeEmail();

	std::vector<std::string> v1;

	if (statusDataIn.is_open())
	{
		std::string text;

		while (getline(statusDataIn, text))
		{
			v1.push_back(text);
		}

		for (size_t i = 0; i < v1.size(); i++)
		{
			if (v1.at(i) == email)
			{
				v1.at(i + 3).erase(v1.at(i + 3).find("Symbol:"), 12);
				backgroundStatus = std::stoi(v1.at(i + 3));
			}
		}
	}

	statusDataIn.close();
}

void Shop::levelSetter()
{
	symbol.level = this->level;
	background.level = this->level;
}

void Shop::Symbols::setSymb()
{
	switch (this->level)
	{
		//Easy Level
	case 2:
		switch (this->symbolStatus)
		{
		case 1:
			t2.loadFromFile("Images, Fonts and Music/RabbitEasy.png");
			t3.loadFromFile("Images, Fonts and Music/CarrotEasy.png");
			t4.loadFromFile("Images, Fonts and Music/CoinEasy.png");
				break;
		case 2:
			t2.loadFromFile("Images, Fonts and Music/HedgehogEasy.png");
			t3.loadFromFile("Images, Fonts and Music/AppleEasy.png");
			t4.loadFromFile("Images, Fonts and Music/CoinEasy.png");
			break;
		case 3:
			t2.loadFromFile("Images, Fonts and Music/BeeEasy.png");
			t3.loadFromFile("Images, Fonts and Music/HoneyEasy.png");
			t4.loadFromFile("Images, Fonts and Music/CoinEasy.png");
			break;
		case 4:
			t2.loadFromFile("Images, Fonts and Music/anelidEasy.png");
			t3.loadFromFile("Images, Fonts and Music/apple-houseEasy.png");
			t4.loadFromFile("Images, Fonts and Music/CoinEasy.png");
			break;
		case 5:
			t2.loadFromFile("Images, Fonts and Music/frogEasy.png");
			t3.loadFromFile("Images, Fonts and Music/flyEasy.png");
			t4.loadFromFile("Images, Fonts and Music/CoinEasy.png");
			break;
		case 6:
			t2.loadFromFile("Images, Fonts and Music/squirrelEasy.png");
			t3.loadFromFile("Images, Fonts and Music/acornEasy.png");
			t4.loadFromFile("Images, Fonts and Music/CoinEasy.png");
			break;
		case 7:
			t2.loadFromFile("Images, Fonts and Music/duckEasy.png");
			t3.loadFromFile("Images, Fonts and Music/cornEasy.png");
			t4.loadFromFile("Images, Fonts and Music/CoinEasy.png");
			break;
		case 8:
			t2.loadFromFile("Images, Fonts and Music/mouseEasy.png");
			t3.loadFromFile("Images, Fonts and Music/cheeseEasy.png");
			t4.loadFromFile("Images, Fonts and Music/CoinEasy.png");
			break;
		}
		break;

		//Hard Level
	case 0:
		switch (this->symbolStatus)
		{
		case 1:
			t2.loadFromFile("Images, Fonts and Music/RabbitHard.png");
			t3.loadFromFile("Images, Fonts and Music/CarrotHard.png");
			t4.loadFromFile("Images, Fonts and Music/CoinHard.png");
				break;
		case 2:
			t2.loadFromFile("Images, Fonts and Music/HedgehogHard.png");
			t3.loadFromFile("Images, Fonts and Music/AppleHard.png");
			t4.loadFromFile("Images, Fonts and Music/CoinHard.png");
			break;
		case 3:
			t2.loadFromFile("Images, Fonts and Music/BeeHard.png");
			t3.loadFromFile("Images, Fonts and Music/HoneyHard.png");
			t4.loadFromFile("Images, Fonts and Music/CoinHard.png");
			break;
		case 4:
			t2.loadFromFile("Images, Fonts and Music/anelidHard.png");
			t3.loadFromFile("Images, Fonts and Music/apple-houseHard.png");
			t4.loadFromFile("Images, Fonts and Music/CoinHard.png");
			break;
		case 5:
			t2.loadFromFile("Images, Fonts and Music/frogHard.png");
			t3.loadFromFile("Images, Fonts and Music/flyHard.png");
			t4.loadFromFile("Images, Fonts and Music/CoinHard.png");
			break;
		case 6:
			t2.loadFromFile("Images, Fonts and Music/squirrelHard.png");
			t3.loadFromFile("Images, Fonts and Music/acornHard.png");
			t4.loadFromFile("Images, Fonts and Music/CoinHard.png");
			break;
		case 7:
			t2.loadFromFile("Images, Fonts and Music/duckHard.png");
			t3.loadFromFile("Images, Fonts and Music/cornHard.png");
			t4.loadFromFile("Images, Fonts and Music/CoinHard.png");
			break;
		case 8:
			t2.loadFromFile("Images, Fonts and Music/mouseHard.png");
			t3.loadFromFile("Images, Fonts and Music/cheeseHard.png");
			t4.loadFromFile("Images, Fonts and Music/CoinHard.png");
			break;
		}
		break;

		//Medium Level
	case 1:
		switch (this->symbolStatus)
		{
		case 1:
			t2.loadFromFile("Images, Fonts and Music/RabbitMedium.png");
			t3.loadFromFile("Images, Fonts and Music/CarrotMedium.png");
			t4.loadFromFile("Images, Fonts and Music/CoinMedium.png");
				break;
		case 2:
			t2.loadFromFile("Images, Fonts and Music/HedgehogMedium.png");
			t3.loadFromFile("Images, Fonts and Music/AppleMedium.png");
			t4.loadFromFile("Images, Fonts and Music/CoinMedium.png");
			break;
		case 3:
			t2.loadFromFile("Images, Fonts and Music/BeeMedium.png");
			t3.loadFromFile("Images, Fonts and Music/HoneyMedium.png");
			t4.loadFromFile("Images, Fonts and Music/CoinMedium.png");
			break;
		case 4:
			t2.loadFromFile("Images, Fonts and Music/anelidMedium.png");
			t3.loadFromFile("Images, Fonts and Music/apple-houseMedium.png");
			t4.loadFromFile("Images, Fonts and Music/CoinMedium.png");
			break;
		case 5:
			t2.loadFromFile("Images, Fonts and Music/frogMedium.png");
			t3.loadFromFile("Images, Fonts and Music/flyMedium.png");
			t4.loadFromFile("Images, Fonts and Music/CoinMedium.png");
			break;
		case 6:
			t2.loadFromFile("Images, Fonts and Music/squirrelMedium.png");
			t3.loadFromFile("Images, Fonts and Music/acornMedium.png");
			t4.loadFromFile("Images, Fonts and Music/CoinMedium.png");
			break;
		case 7:
			t2.loadFromFile("Images, Fonts and Music/duckMedium.png");
			t3.loadFromFile("Images, Fonts and Music/cornMedium.png");
			t4.loadFromFile("Images, Fonts and Music/CoinMedium.png");
			break;
		case 8:
			t2.loadFromFile("Images, Fonts and Music/mouseMedium.png");
			t3.loadFromFile("Images, Fonts and Music/cheeseMedium.png");
			t4.loadFromFile("Images, Fonts and Music/CoinMedium.png");
			break;
		}
		break;
	}
}

void Shop::Background::setBackground()
{
	switch (this->level)
	{
		//Easy Level
	case 2:
		switch (this->backgroundStatus)
		{
		case 1:
			t1.loadFromFile("Images, Fonts and Music/WallEasy.png");
			break;
		case 2:
			t1.loadFromFile("Images, Fonts and Music/WallEasy.png");
			break;
		case 3:
			t1.loadFromFile("Images, Fonts and Music/WallEasy.png");
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		}
		break;

		//Hard Level
	case 0:
		switch (this->backgroundStatus)
		{
		case 1:
			t1.loadFromFile("Images, Fonts and Music/WallHard.png");
			break;
		case 2:
			t1.loadFromFile("Images, Fonts and Music/WallHard.png");
			break;
		case 3:
			t1.loadFromFile("Images, Fonts and Music/WallHard.png");
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		}
		break;

		//Medium Level
	case 1:
		switch (this->backgroundStatus)
		{
		case 1:
			t1.loadFromFile("Images, Fonts and Music/WallMedium.png");
			break;
		case 2:
			t1.loadFromFile("Images, Fonts and Music/WallMedium.png");
			break;
		case 3:
			t1.loadFromFile("Images, Fonts and Music/WallMedium.png");
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		}
		break;
	}
}