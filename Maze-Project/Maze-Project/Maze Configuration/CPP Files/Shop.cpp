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