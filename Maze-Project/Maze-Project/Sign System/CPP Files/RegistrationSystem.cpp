#include "../Header Files/RegistrationSystem.h"
#include "../../Sign System/Header Files/SHA256.h"
#include <iostream>

RegistrationSystem::RegistrationSystem(std::string name, std::string password)
{
	this->name = name;
	this->password = password;

	initializeDataIntoIndividualFile(this->name, this->password);
}

bool RegistrationSystem::checkIfUsernameOrPasswordAreEmpty(std::string name, std::string password)
{
	if (name.empty() || password.empty())
		return false;

	return true;
}

void RegistrationSystem::printErrorMessage()
{
	system("cls");

	printf("Please Enter valid data!\n");
	printf("Press Enter to continue: ");
	
	std::cin.get();
}

//Pushing user data into a file
void RegistrationSystem::initializeDataIntoIndividualFile(std::string name, std::string password)
{
	//Hashing the password
	password = sha256(password);

	individualDataOut.open("Individual Data.txt", std::ios::out | std::ios::app);
	if (individualDataOut.is_open())
	{
		if (checkIfUsernameOrPasswordAreEmpty(name, password))
		{
			individualDataOut << name << " " << password << std::endl;
		}
		else {
			printErrorMessage();
		}
		
	}

	individualDataOut.close();
}