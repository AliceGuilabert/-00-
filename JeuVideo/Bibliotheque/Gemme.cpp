#include "stdafx.h"
#include "Gemme.h"
#include <windows.h>

Gemme::Gemme(std::string name, std::string texteActivation, int x, int y)
	: Activable(name, texteActivation, x, y)
{
	boundingBox = sf::FloatRect(sf::Vector2f(x, y), sf::Vector2f(32, 32));

	//Chargement des Sprites des Gemmes.
	if (!texture1.loadFromFile("../../map/GemmeGraph1.png"))
	{
		std::cout << "Can't find the texture file" << std::endl;
		exit;
	}

	if (!texture2.loadFromFile("../../map/GemmeGraph2.png"))
	{
		std::cout << "Can't find the texture file" << std::endl;
		exit;
	}

	if (!texture3.loadFromFile("../../map/GemmeGraph3.png"))
	{
		std::cout << "Can't find the texture file" << std::endl;
		exit;
	}

	if (name == "Gemme3") {
		activated = false;
	}
	else {
		activated = true;
	}
}

void Gemme::Draw(int NbGraphic, sf::RenderWindow &window) 
{
	switch (NbGraphic)		//On trace le bon sprite suivant le graphique
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

void Gemme::Action(int NbGraphic,sf::RenderWindow &window)
{
	//Chargement de la police
	sf::Font font;
	if (!font.loadFromFile("../../theboldfont.ttf")) {
		std::cout << "Can't find the font file" << std::endl;
		exit;
	}

	//Creation du texte
	sf::Text texte;
	texte.setFont(font);
	texte.setString(texteActivation);
	texte.setColor(sf::Color::White);
	texte.setCharacterSize(300);
	texte.setScale(0.03f, 0.03f);
	texte.setPosition(x - 5, y - 25);


	window.draw(texte);
	window.display();
	Sleep(2000); //Attente pour avoir le temps de lire 
	//TODO --> Remplacer l'attente par une boucle d'attente d'evenement.
	setActivated(false);
}



