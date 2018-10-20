#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <memory>
#include <vector>
#include <iostream>
#include "Collision.h"
#include "Gemme.h"
#include "Door.h"
#include "TreasureChest.h"


class ActivableHandler
{
public:
	ActivableHandler();

	//Gere l'activation des interactions.
	std::string Interraction(int NbGraphic, int x, int y, int width, int height, sf::RenderWindow & window);
	
	//Affiche les Activables sur la map
	void Draw(int NbGraph, sf::RenderWindow & window);

	//Charge les activables disponibles.
	void Load(Collision &collision);

	std::vector<std::unique_ptr<Activable>> objects;
	
};

