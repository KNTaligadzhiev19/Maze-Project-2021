#pragma once
#include <string>
#include <fstream>

class LoginSystem
{
private:
	std::string name;
	std::string password;

	std::ofstream individualDataOut;
	std::ifstream individualDataIn;
public:

	LoginSystem(std::string name, std::string password);

	bool checkLoginData();
};

