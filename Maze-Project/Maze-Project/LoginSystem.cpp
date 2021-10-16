#include "LoginSystem.h"

LoginSystem::LoginSystem(string name, string password)
{
	this->name = name;
	this->password = password;
}

bool LoginSystem::checkLoginData()
{
	individualDataIn.open("Individual Data.txt", ios::in | ios::app);

	if (individualDataIn.is_open())
	{
		string text;

		while (getline(individualDataIn, text))
		{
			if (text.find(name) != string::npos)
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