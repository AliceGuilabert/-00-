#pragma once
#include "Activable.h"

class Door : public Activable
{
public:
	Door(std::string name, std::string texteActivation, std::string texteGraph2, 
		std::string texteGraph3, int x, int y);

	//Action declenchee a l'activation de l'objet
	void Action(int NbGraphic, sf::RenderWindow & window) override;

	//Fonction dessinant et attribuant l'objet
	void Draw(int NbGraphic, sf::RenderWindow & window) override;

private:
	std::string texteGraph2;
	std::string texteGraph3;
};


