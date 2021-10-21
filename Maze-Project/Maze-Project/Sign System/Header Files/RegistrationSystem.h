#pragma once
#include <string>
#include <fstream>
using namespace std;

class RegistrationSystem
{
private:
	string name;
	string password;

	ofstream individualDataOut;
	ifstream individualDataIn;

public:
	RegistrationSystem(string name, string password);

	void pushDataIntoIndividualFile(string name, string password);
};

