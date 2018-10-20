#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

class Cinematic
{
public:
	Cinematic();
	
	//Deroulement de la Cinematique
	void Show(sf::RenderWindow& window);

private : 
	sf::Text texte1;
	sf::Text texte2;
	sf::Text texte3;
	sf::Text texte4;
	std::vector<sf::Text> script;
};

