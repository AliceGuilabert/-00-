#include "stdafx.h"
#include "Menu.h"


Menu::Menu()
{	
	
	//Chargement de la police
	if (!font.loadFromFile("../../theboldfont.ttf")) {
		std::cout << "Can't find the font file" << std::endl;
	}

	//Declaration des titres
	startText.setFont(font);
	startText.setString("New Game");
	startText.setColor(sf::Color::White);
	startText.setCharacterSize(150);
	startText.setPosition(200.0f, 500.0f);

	exit.setFont(font);
	exit.setString("Exit");
	exit.setColor(sf::Color::White);
	exit.setCharacterSize(150);
	exit.setPosition(1300.0f, 500.0f);
	
}

void Menu::Action(sf::RenderWindow& window) {


	sf::Event currentEvent;

	while (window.isOpen())
	{
		while (window.pollEvent(currentEvent)) {

		
		switch (currentEvent.type) {

		case sf::Event::Closed:
		{
			window.close();
			break;
		}

		case sf::Event::MouseMoved:
		{
			//mise en bleu des textes quand on passe la souris dessus.
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
			if (startText.getGlobalBounds().contains(mousePosF))
			{
				startText.setColor(sf::Color::Blue);
			}
			else {
				startText.setColor(sf::Color::White);
			}

			if (exit.getGlobalBounds().contains(mousePosF))
			{
				exit.setColor(sf::Color::Blue);
			}
			else {
				exit.setColor(sf::Color::White);
			}
		}
		break;
	
		case sf::Event::MouseButtonPressed:
		{
			//gestion du Clic et du déplacement vers un autre écran.
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
			if (startText.getGlobalBounds().contains(mousePosF))
			{
				//exit de la fonction, retour dans la loop.
				return;
			}
			else if (exit.getGlobalBounds().contains(mousePosF))
			{
				window.close();
			}
		}
		break;
		
		}
		}
		//Display de la fenetre.
		window.clear();
		window.draw(startText);
		window.draw(exit);
		window.display();
	}
}
