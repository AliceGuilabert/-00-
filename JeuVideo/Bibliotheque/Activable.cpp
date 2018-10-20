#include "stdafx.h"
#include "Activable.h"


Activable::Activable(std::string Valname, std::string ValtexteActivation, int Valx, int Valy)
{
	name = Valname;
	texteActivation = ValtexteActivation;
	x = Valx;
	y = Valy;
	sprite.setPosition(x, y);
}


// GETTERS et SETTERS
sf::FloatRect Activable::getBox() { return boundingBox; }
std::string Activable::getName() { return name; }
bool Activable::getActivated() { return activated; }
void Activable::setActivated(bool val) { activated = val; }
void Activable::setName(std::string val) { name = val; }
void Activable::setBox(sf::FloatRect val) { boundingBox = val; }
void Activable::setTexteActivation(std::string val) { texteActivation = val; }
void Activable::setX(int val) { x = val; }
void Activable::setY(int val) { y = val; }
