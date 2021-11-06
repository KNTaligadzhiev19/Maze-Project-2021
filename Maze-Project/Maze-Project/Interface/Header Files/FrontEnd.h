#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

void printMenu(sf::RenderWindow& window);

void onClickUserMenu(sf::RenderWindow& window, sf::Event& event1);

void printLoginAndRegisterMenu(sf::RenderWindow& window);

void printPlayerMenu(sf::RenderWindow& window);

void onClickLoginAndRegister(sf::RenderWindow& window, sf::Event& event1);

void inputLoginData(sf::RenderWindow& window, sf::Event& event1);

void inputRegisterData(sf::RenderWindow& window, sf::Event& event1);

void onClickPlayerMenu(sf::RenderWindow& window, sf::Event& event1);

void printRulesTable(sf::RenderWindow& window);

void onClickRulesTable(sf::RenderWindow& window, sf::Event& event1);

void printCongratsMenu(sf::RenderWindow& window);

void onClickCongratsMenu(sf::RenderWindow& window, sf::Event& event1);

void reload();

void playMusic(sf::Music& music);

void setDataValue();