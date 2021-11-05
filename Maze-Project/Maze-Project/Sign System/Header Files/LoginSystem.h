#pragma once
#include <string>
#include <fstream>
#include "SFML/Graphics.hpp"

class LoginSystem
{
private:
	sf::String name;
	sf::String password;

	std::ifstream userDataIn;
public:

	LoginSystem(sf::String name, sf::String password);

	bool checkLoginData();
};