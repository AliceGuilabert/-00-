#include "stdafx.h"
#include "Cinematic.h"


Cinematic::Cinematic()
{
}

void Cinematic::Show(sf::RenderWindow & window)
{
	//Chargement de la police
	sf::Font font;
	if (!font.loadFromFile("../../theboldfont.ttf")) {
		std::cout << "Can't find the font file" << std::endl;
	}
	//Créations des textes
	sf::Text texte1;
	texte1.setFont(font);
	texte1.setString("Bonjour bienvenue dans le tuto de ce jeu !");
	texte1.setColor(sf::Color::White);
	texte1.setCharacterSize(70);
	texte1.setPosition(150.0f, 500.0f);
	script.push_back(texte1);

	sf::Text texte2;
	texte2.setFont(font);
	texte2.setString("Pour vous deplacer, utilisez les fleches directionnelles.");
	texte2.setColor(sf::Color::White);
	texte2.setCharacterSize(60);
	texte2.setPosition(150.0f, 500.0f);
	script.push_back(texte2);

	sf::Text texte3;
	texte3.setFont(font);
	texte3.setString("Pour interagir avec les objets, appuyez sur Espace");
	texte3.setColor(sf::Color::White);
	texte3.setCharacterSize(60);
	texte3.setPosition(150.0f, 500.0f);
	script.push_back(texte3);

	sf::Text texte4;
	texte4.setFont(font);
	texte4.setString("Bon  jeu !");
	texte4.setColor(sf::Color::White);
	texte4.setCharacterSize(100);
	texte4.setPosition(400.0f, 500.0f);
	script.push_back(texte4);


	int index = 0;
	sf::Event currentEvent;
	while (window.waitEvent(currentEvent))
	{
		window.clear();
		window.draw(script[index]);
		window.display();

		switch (currentEvent.type) {

		case sf::Event::Closed:
		{
			window.close();
			break;
		}
		break;

		case sf::Event::MouseButtonPressed:
		{
			//Changement de texte à afficher à chaque clique, sans changer de classe.
			index++;
			if (index == 4) {
				return;
			}
		}
		break;
		}
	}
}

