#pragma once
#include <iostream>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <vector>

class Activable
{
public:
	Activable(std::string Valname, std::string texteActivation, int x, int y);

	//GETTERS et SETTERS
	sf::FloatRect getBox();
	bool getActivated();
	std::string getName();
	void setActivated(bool val);
	void setName(std::string val);
	void setBox(sf::FloatRect val);
	void setTexteActivation(std::string val);
	void setX(int val);
	void setY(int val);

	//fonctions virtuels
	virtual void Action(int NbGraphic, sf::RenderWindow & window) = 0;
	virtual void Draw(int NbGraphic, sf::RenderWindow & window) = 0;

	sf::Sprite sprite;

protected: 
	std::string name;
	sf::FloatRect boundingBox;
	std::string texteActivation;
	bool activated;
	sf::Texture texture1;
	sf::Texture texture2;
	sf::Texture texture3;
	int x;
	int y;
	
};

