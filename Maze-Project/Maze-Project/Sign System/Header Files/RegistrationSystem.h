#pragma once
#include <fstream>
#include "SFML/Graphics.hpp"

class RegistrationSystem
{
private:
	sf::String name;
	sf::String password;

	std::ofstream userDataOut;

public:

	RegistrationSystem(sf::String name, sf::String password, bool& userMenuEventClick, bool& loginAndRegisterEventClick, int& status);

	
	bool checkIfUsernameOrPasswordAreEmpty(sf::String name, sf::String password);

	
	void initializeDataIntoIndividualFile(sf::String name, sf::String password, bool& userMenuEventClick, bool& loginAndRegisterEventClick, int& status);
};
