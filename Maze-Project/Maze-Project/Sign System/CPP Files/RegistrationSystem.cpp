#include "../Header Files/RegistrationSystem.h"
#include "SHA256.h"
#include <iostream>

RegistrationSystem::RegistrationSystem(sf::String name, sf::String password, bool& userMenuEventClick, bool& loginAndRegisterEventClick, int& status)
{
	this->name = name;
	this->password = password;

	initializeDataIntoIndividualFile(this->name, this->password, userMenuEventClick, loginAndRegisterEventClick, status);
}

bool RegistrationSystem::checkIfUsernameOrPasswordAreEmpty(sf::String name, sf::String password)
{
	std::string name1 = name.toAnsiString();
	std::string password1 = password.toAnsiString();

	if (name1.empty() || password1.empty())
		return false;

	return true;
}

//Pushing user data into a file
void RegistrationSystem::initializeDataIntoIndividualFile(sf::String name, sf::String password, bool& userMenuEventClick, bool& loginAndRegisterEventClick, int& status)
{
	//Hashing the password
	if (!password.isEmpty())
		password = sha256(password);

	std::string name1 = name.toAnsiString();
	std::string password1 = password.toAnsiString();

	userDataOut.open("User Data.txt", std::ios::out | std::ios::app);

	if (userDataOut.is_open())
	{
		if (checkIfUsernameOrPasswordAreEmpty(name, password))
		{
			userDataOut << name1 << " " << password1 << std::endl;

			userMenuEventClick = true;
			loginAndRegisterEventClick = false;
			status = 1;
		}

	}

	userDataOut.close();
}

