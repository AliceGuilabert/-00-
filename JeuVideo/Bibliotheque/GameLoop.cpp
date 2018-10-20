#include "stdafx.h"
#include "GameLoop.h"
#include <time.h>



GameLoop::GameLoop()
{
	//Initialisation de toutes les autres classes.
	Player player;
	XMLHandler xml;
	CommandHandler commande;
	MapHandler maphandler;
	sf::Event event;
	tmx::Map map;
	Collision collision;
	bool change = false;
	bool keyPressed = false;
	ActivableHandler activableHandler();
}

void GameLoop::Start(sf::RenderWindow & window) {
	//Parcours logique du jeu
	Loop(window, 3);
	Loop(window, 2);
	Loop(window, 1);
	//TODO --> Faire un ecran de fin ?
	return;
}

void GameLoop::Loop(sf::RenderWindow &window, int NbGraph)
{
	switch (NbGraph) //Chargement des bons sprites et map suivant le graphique
	{
	case(1): {
		map = maphandler.Load(NbGraph); //Importation de la carte
		xml.updatePlayer(NbGraph, player); //Initialisation des variables du perso
		break;
	}
	case(2): {
		map = maphandler.Load(NbGraph);
		xml.updatePlayer(NbGraph, player);
		break;
	}
	case(3): {
		map = maphandler.Load(NbGraph);
		xml.updatePlayer(NbGraph, player);
		break;
	}
	}
	
	
	//Creation des deux couches de la map
	MapLayer layerZero(map, 0);
	MapLayer layerOne(map, 1);

	//Creation de l'horloge pour les FPS
	sf::Clock clock;
	float fRate = 0.016f;

	while (window.isOpen()) {

		//Control des frames par secondes
		sf::Time time = clock.getElapsedTime();
		if (time.asSeconds() > fRate) {

			while (window.pollEvent(event)) {

				if (event.type == sf::Event::Closed) {
					window.close();
				}

				if (event.type == sf::Event::KeyPressed) {
					keyPressed = true;
				}

				if (event.type == sf::Event::KeyReleased) {
					keyPressed = false;
				}
			}

			//Chargement des colisions actives.
			activableHandler.Load(collision);

			//Update des touches appuyes
			std::string etat = commande.Handle(window, player, keyPressed, collision, NbGraph, activableHandler);
			//Si on a active une gemme, on sort de la loop.
			if (etat == "Change") {
				std::cout << "On chaange" << std::endl;
				return;
			}

			window.clear(sf::Color::Black);

			
			
			window.draw(layerZero); // Dessin de la carte.
			window.draw(layerOne);
			//window.draw(&maphandler.layers[0]);

			activableHandler.Draw(NbGraph,window); //Dessin des activables
			player.drawPlayer(window, etat); //Dessin du personnage
			maphandler.CenterScrolling(player, window); //Controle de la camera 

			window.display();


			clock.restart();

		}
	}
}



