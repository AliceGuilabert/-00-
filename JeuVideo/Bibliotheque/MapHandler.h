#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <tmxlite/Map.hpp>
#include <vector>
#include "MapLayer.h"
#include "Player.h"

class MapHandler
{
public:
	MapHandler();

	//Chargement de la carte
	tmx::Map Load(int NbGraphic);

	//Control de la camera 
	void CenterScrolling(Player player, sf::RenderWindow & window);
	//std::vector<MapLayer> layers;

private:
	tmx::Map map;
	
};

