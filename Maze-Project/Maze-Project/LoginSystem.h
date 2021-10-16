#pragma once
#include <string>
#include <fstream>
using namespace std;

class LoginSystem
{
private:
	string name;
	string password;

	ofstream individualDataOut;
	ifstream individualDataIn;
public:

	LoginSystem(string name, string password);

	bool checkLoginData();
};

