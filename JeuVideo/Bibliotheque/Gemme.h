#pragma once
#include "Activable.h"

class Gemme : public Activable
{
public:
	Gemme(std::string name, std::string texteActivation, int x, int y);

	//Fonction dessinant et attribuant l'objet
	void Draw(int NbGraphic, sf::RenderWindow & window) override;

	//Action declenchee a l'activation de l'objet
	void Action(int NbGraphic, sf::RenderWindow &window) override;

private:

};

