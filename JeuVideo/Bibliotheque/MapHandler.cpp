#include "stdafx.h"
#include "MapHandler.h"

MapHandler::MapHandler()
{
	
}

tmx::Map MapHandler::Load(int NBgraphic)
{
	//Chargement des bons Tiled suivant le graph
	if (NBgraphic == 1) {
		tmx::Map map;
		map.load("../../map/Level2.tmx");
		return map;
	}

	else if (NBgraphic == 2) {
		tmx::Map map;
		map.load("../../map/Level2D.tmx");
		return map;
	}

	else if (NBgraphic == 3) {
		tmx::Map map;
		map.load("../../map/LevelAscii.tmx");
		return map;
	}
	/*
	
	//Creation des deux couches de la map
	MapLayer layerZero(map, 0);
	MapLayer layerOne(map, 1);

	layers.push_back(layerZero);
	//layers.push_back(&layerOne);*/
}

void MapHandler::CenterScrolling(Player player, sf::RenderWindow & window)
{
	//On definit une vue que l'on centre sur le personnage.
	sf::View view(sf::Vector2f(300, 112), sf::Vector2f(400, 224));

	// On bloque les extremites de la carte avec un test de position.
	if (player.getX() < 200) {
		view.setCenter(200, 112);
	}
	else if (player.getX() > 1400) {
		view.setCenter(1400, 112);
	}
	else {
		view.setCenter(player.getX(), 112);
	}

	window.setView(view);
}