#include "../Header Files/RegistrationSystem.h"

RegistrationSystem::RegistrationSystem(std::string name, std::string password)
{
	this->name = name;
	this->password = password;

	initializeDataIntoIndividualFile(this->name, this->password);
}

void RegistrationSystem::initializeDataIntoIndividualFile(std::string name, std::string password)
{
	individualDataOut.open("Individual Data.txt", std::ios::out | std::ios::app);
	if (individualDataOut.is_open())
	{
		individualDataOut << name << " " << password << std::endl;
	}

	individualDataOut.close();
}