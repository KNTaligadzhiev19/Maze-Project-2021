#include "../Header Files/LoginSystem.h"
#include "../../Interface/Header Files/FrontEnd.h"

LoginSystem::LoginSystem(sf::String name, sf::String password)
{
	this->name = name;
	this->password = password;
}

// Checking if data is correct or else
bool LoginSystem::checkLoginData()
{
	userDataIn.open("User Data.txt", std::ios::in | std::ios::app);

	if (userDataIn.is_open())
	{
		std::string text;

		while (getline(userDataIn, text))
		{
			if (text.find(name) != std::string::npos)
			{
				text.erase(text.find(name), name.getSize() + 1);

				if (text == password)
				{
					saveCoinData(name);
					return true;
				}
			}
		}
	}

	userDataIn.close();

	return false;
}