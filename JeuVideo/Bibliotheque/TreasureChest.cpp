#include "stdafx.h"
#include "TreasureChest.h"
#include <vector>
#include <windows.h>

TreasureChest::TreasureChest(std::string name, std::string texteActivation,
	std::string ValtexteGraph2, int x, int y)
	: Activable(name, texteActivation, x, y)
{
	texteGraph2 = ValtexteGraph2;
	boundingBox = sf::FloatRect(sf::Vector2f(x - 5, y - 10), sf::Vector2f(40, 40));
	activated = true;

	//Chargement des Sprites des Coffres.
	if (!texture1.loadFromFile("../../map/CoffreGraph1.png"))
	{
		std::cout << "Can't find the texture file" << std::endl;
		exit;
	}

	if (!texture2.loadFromFile("../../map/CoffreGraph2.png"))
	{
		std::cout << "Can't find the texture file" << std::endl;
		exit;
	}

	if (!texture3.loadFromFile("../../map/CoffreGraph3.png"))
	{
		std::cout << "Can't find the texture file" << std::endl;
		exit;
	}
}

void TreasureChest::Draw(int NbGraphic, sf::RenderWindow &window)
{
	switch (NbGraphic)	//On trace le bon sprite suivant le graphique
	{
	case(1):
		sprite.setTexture(texture1);
		window.draw(sprite);
		break;
	case(2):
		sprite.setTexture(texture2);
		window.draw(sprite);
		break;
	case(3):
		sprite.setTexture(texture3);
		window.draw(sprite);
		break;
	}
}

void TreasureChest::Action(int NbGraphic, sf::RenderWindow & window)
{
	//Chargement de la police
	sf::Font font;
	if (!font.loadFromFile("../../theboldfont.ttf")) {
		std::cout << "Can't find the font file" << std::endl;
	}

	//Creation du texte.
	sf::Text texte;
	texte.setFont(font);
	texte.setColor(sf::Color::White);
	texte.setCharacterSize(300);
	texte.setScale(0.03f, 0.03f);
	texte.setPosition(x - 25, y - 25);

	if (NbGraphic == 1) {
		texte.setString(texteActivation);  //On a pu ouvrir le coffre
		setActivated(false);
	}
	else if (NbGraphic == 2) {
		texte.setString(texteGraph2);  
		
	}
	window.draw(texte);
	window.display();
	Sleep(2500); //Attente pour avoir le temps de lire 
				 //TODO --> Remplacer l'attente par une boucle d'attente d'evenement.
}