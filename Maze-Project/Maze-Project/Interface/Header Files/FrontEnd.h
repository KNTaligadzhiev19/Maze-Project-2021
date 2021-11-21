#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

//Prints the menu for logging and registrating
void printMenu(sf::RenderWindow& window);

//Getting the choice of the user
void onClickUserMenu(sf::RenderWindow& window, sf::Event& event1);

//Return the saved email
sf::String returnSafeEmail();

//Printing the Login or Register Menu for inputting the data
void printLoginAndRegisterMenu(sf::RenderWindow& window);

//Printing the player menu after logging in
void printPlayerMenu(sf::RenderWindow& window);

//Getting the choice of the user in the logging or registrating menu
void onClickLoginAndRegister(sf::RenderWindow& window, sf::Event& event1);

void inputLoginData(sf::RenderWindow& window, sf::Event& event1);

void inputRegisterData(sf::RenderWindow& window, sf::Event& event1);

//Getting the choice of the user in the player menu after logging in
void onClickPlayerMenu(sf::RenderWindow& window, sf::Event& event1);

void printRulesTable(sf::RenderWindow& window);

void onClickRulesTable(sf::RenderWindow& window, sf::Event& event1);

//Printing the congratulations message after winning the game
void printCongratsMenu(sf::RenderWindow& window);

//Getting the choice of the user in the congratulations menu
void onClickCongratsMenu(sf::RenderWindow& window, sf::Event& event1);

void printShopMenu(sf::RenderWindow &window);

void onClickShopMenu(sf::RenderWindow& window, sf::Event& event1);

void printSymbolMenu(sf::RenderWindow& window);

void saveCoinData(std::string email);

void saveCoinData2(int coins);

void onClickSymbolMenu(sf::RenderWindow& window, sf::Event& event1);

void printBackgroundMenu(sf::RenderWindow& window);

void onClickBackgroundMenu(sf::RenderWindow& window, sf::Event& event1);

//Reloading the player menu
void reload();

//Setting the background music
void playMusic(sf::Music& music);

//Starting the program
void setDataValue();