#include "../Header Files/LoginSystem.h"

LoginSystem::LoginSystem(std::string name, std::string password)
{
	this->name = name;
	this->password = password;
}

bool LoginSystem::checkLoginData()
{
	individualDataIn.open("Individual Data.txt", std::ios::in | std::ios::app);

	if (individualDataIn.is_open())
	{
		std::string text;

		while (getline(individualDataIn, text))
		{
			if (text.find(name) != std::string::npos)
			{
				text.erase(text.find(name), name.size() + 1);

				if (text == password)
				{
					return true;
				}
			}
		}
	}
	individualDataIn.close();

	return false;
}