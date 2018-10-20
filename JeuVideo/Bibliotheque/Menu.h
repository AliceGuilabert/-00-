#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <list>

class Menu
{
public:
	Menu();

	//Fonction d'affichage et action du menu
	void Action(sf::RenderWindow& window);	
	
private:
	sf::Text startText;
	sf::Text exit;

	sf::Font font;
};
