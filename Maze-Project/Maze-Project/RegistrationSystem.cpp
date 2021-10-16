#include "RegistrationSystem.h"

RegistrationSystem::RegistrationSystem(string name, string password)
{
	this->name = name;
	this->password = password;

	pushDataIntoIndividualFile(this->name, this->password);
}

void RegistrationSystem::pushDataIntoIndividualFile(string name, string password)
{
	individualDataOut.open("Individual Data.txt", ios::out | ios::app);
	if (individualDataOut.is_open())
	{
		individualDataOut << name << " " << password << endl;
	}

	individualDataOut.close();
}