#pragma once
#include "Activable.h"

class TreasureChest: public Activable
{
public:
	TreasureChest(std::string name, std::string texteActivation, std::string texteGraph2, int x, int y);
	
	//Action declenchee a l'activation de l'objet
	void Action(int NbGraphic, sf::RenderWindow & window) override;

	//Fonction dessinant et attribuant l'objet
	void Draw(int NbGraphic, sf::RenderWindow & window) override;

private:
	std::string texteGraph2;
};

