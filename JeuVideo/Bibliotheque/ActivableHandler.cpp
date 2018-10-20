#include "stdafx.h"
#include "ActivableHandler.h"
#include "XMLHandler.h"



ActivableHandler::ActivableHandler()
{
	XMLHandler xmlHandler; // TODO --> le passer en argument du constructeur (pas si simple enfait ;) )
	auto node = xmlHandler.updateActivable();

	for (auto i : node.children()) { //On parcourt tout les enfants
		//On cree une Gemme
		if (strcmp(i.name(), "Gemme") == 0) { 
			objects.push_back(std::make_unique<Gemme>(Gemme(i.attribute("name").as_string(), 
				i.attribute("texteActivation").as_string(), i.attribute("x").as_int(), i.attribute("y").as_int())));
		}
		//On cree une Porte
		else if (strcmp(i.name(), "Door") == 0) {
			objects.push_back(std::make_unique<Door>(Door(i.attribute("name").as_string(),
				i.attribute("texteActivation").as_string(),
				i.attribute("texte2").as_string(), i.attribute("texte3").as_string(),
				i.attribute("x").as_int(), i.attribute("y").as_int())));
		} 
		//On cree un coffre
		else if (strcmp(i.name(), "TreasureChest") == 0) {
			objects.push_back(std::make_unique<TreasureChest>(TreasureChest(i.attribute("name").as_string(),
				i.attribute("texteActivation").as_string(),
				i.attribute("texte2").as_string(), i.attribute("x").as_int(), i.attribute("y").as_int())));
		}
	}
}

void ActivableHandler::Draw(int NbGraph, sf::RenderWindow & window){
	for (auto const& i : objects) {
		if (i->getActivated() == true) {	//On ne trace que les objets non actifs.
			i->Draw(NbGraph, window);
		}	
	}
}

void ActivableHandler::Load(Collision & collision)
{
	collision.activables.clear();	//On clean le vecteur puis update les collisions
	for (auto const& i : objects) {
		if (i->getName() == "Door1") {
			if (i->getActivated() == true) {	//Si on a une porte non activee --> on rajoute la collision
				collision.activables.push_back(i->getBox());
			}
		}
	}
}

std::string ActivableHandler::Interraction(int NbGraphic, int x, int y, int width, int height, sf::RenderWindow & window)
{
	//HitBox du personnage
	sf::FloatRect boundingBoxPerso(sf::Vector2f(x, y), sf::Vector2f(width, height));

	for (auto const& i : objects) {
		if (boundingBoxPerso.intersects(i->getBox())) { //Si le perso touche un objet
			if (i->getActivated() == true) { //et qu'il est active --> action
				i->Action(NbGraphic, window);

				if (i->getName() == "TreasureChest" && i->getActivated() == false) {
					objects[2]->setActivated(true);
				}

				if (i->getName() == "Gemme1" || i->getName() == "Gemme2" || i->getName() == "Gemme3") {
					return "Change"; //retour pour annoncer la modif à faire de graphique
				}
				else {
					return "Idle";
				}
			}
		}
	}
}

