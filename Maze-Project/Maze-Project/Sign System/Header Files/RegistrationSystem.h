#pragma once
#include <string>
#include <fstream>

class RegistrationSystem
{
private:
	std::string name;
	std::string password;

	std::ofstream individualDataOut;
	std::ifstream individualDataIn;

public:

	RegistrationSystem(std::string name, std::string password);

	void initializeDataIntoIndividualFile(std::string name, std::string password);
};

