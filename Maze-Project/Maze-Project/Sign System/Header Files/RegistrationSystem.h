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

	//Checks for correct data
	bool checkIfUsernameOrPasswordAreEmpty(std::string name, std::string password);

	//Prints error when data is not valid
	void printErrorMessage();

	//Pushing user data into a file
	void initializeDataIntoIndividualFile(std::string name, std::string password);
};

