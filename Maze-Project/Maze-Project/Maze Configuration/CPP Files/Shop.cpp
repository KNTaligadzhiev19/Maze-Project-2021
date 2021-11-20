#include "../Header Files/Shop.h"

void Shop::safeCoinData()
{
	statusDataIn.open("Status User Data.txt", std::ios::in | std::ios::app);

	if (statusDataIn.is_open())
	{
		std::string text;

		while (getline(statusDataIn, text))
		{
			if (text.find("Coins:") != std::string::npos)
			{
				text.erase(text.find("Coins:"), 7);

				coins = std::stoi(text);
			}
		}
	}

	statusDataIn.close();
}

void Shop::Symbols::safeSymbolStatusData()
{
	statusDataIn.open("Status User Data.txt", std::ios::in | std::ios::app);

	if (statusDataIn.is_open())
	{
		std::string text;

		while (getline(statusDataIn, text))
		{
			if (text.find("Symbol:") != std::string::npos)
			{
				text.erase(text.find("Symbol:"), 8);

				symbolStatus = std::stoi(text);
			}
		}
	}

	statusDataIn.close();
}

void Shop::Background::safeBackgroundStatusData()
{
	statusDataIn.open("Status User Data.txt", std::ios::in | std::ios::app);

	if (statusDataIn.is_open())
	{
		std::string text;

		while (getline(statusDataIn, text))
		{
			if (text.find("Background:") != std::string::npos)
			{
				text.erase(text.find("Background:"), 12);

				backgroundStatus = std::stoi(text);
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

void Shop::Symbols::chooseSymb()
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

void Shop::Background::chooseBackground()
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