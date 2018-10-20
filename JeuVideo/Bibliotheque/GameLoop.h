#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "XMLHandler.h"
#include "Player.h"
#include "CommandHandler.h"
#include "MapHandler.h"
#include "Collision.h"
#include "ActivableHandler.h"


class GameLoop
{
public:
	GameLoop();

	//Loop principale du jeu
	void Loop(sf::RenderWindow & window, int NbGraph);

	//Fonction gerant l'appel aux 3 loops de Graphic.
	void Start(sf::RenderWindow & window);

	int Graph;
	bool change;
	bool keyPressed;
private:
	Player player;
	XMLHandler xml;
	CommandHandler commande;
	MapHandler maphandler;
	sf::Event event;
	tmx::Map map; 
	Collision collision;
	ActivableHandler activableHandler;
};

