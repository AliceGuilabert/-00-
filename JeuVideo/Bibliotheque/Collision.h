#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <vector>


class Collision
{
public:
	Collision();

	//Test de collision des déplacements en X
	bool CollisionTestX(float speed, int x, int y, int wRun, int hRun);

	//Test de collision des déplacements en Y
	bool CollisionTestY(float speed, int x, int y, int wRun, int hRun);

	//Test de collision pour le saut du personnage
	bool JumpTest(float speed, int x, int y, int wRun, int hRun);

	//Test pour savoir si le personnage est sur le sol ou en train de tomber
	bool FallTest(int x, int y, int wIdle, int hIdle);

	//Test pour savoir si le personnage est tombe dans un trou
	bool Dead(int x, int y, int wIdle, int hIdle);

	std::vector<sf::FloatRect> activables;

private : 
	sf::FloatRect boundingBox0;
	sf::FloatRect boundingBox1;
	sf::FloatRect boundingBox2;
	sf::FloatRect boundingBox3;
	sf::FloatRect boundingBox4;
	sf::FloatRect boundingBox5;
	sf::FloatRect boundingBox6;
	sf::FloatRect boundingBox7;
	sf::FloatRect boundingBox8;
	sf::FloatRect boundingBox9;
	sf::FloatRect boundingBox10;
	sf::FloatRect boundingBox11;
	sf::FloatRect boundingBox12;
	sf::FloatRect boundingBox13;
	sf::FloatRect boundingBox14;
	sf::FloatRect boundingBox15;
	sf::FloatRect boundingBox16;
	sf::FloatRect boundingBox17;
	sf::FloatRect boundingBox18;
	sf::FloatRect boundingBox19;
	sf::FloatRect boundingBox20;
	sf::FloatRect boundingBox21;
	sf::FloatRect boundingBox22;
	sf::FloatRect boundingBox23;
	sf::FloatRect boundingBox24;
	sf::FloatRect boundingBox25;
	
	sf::FloatRect dead1;
	sf::FloatRect dead2;
	sf::FloatRect dead3;

	std::vector<sf::FloatRect> boxs;
	std::vector<sf::FloatRect> dead;
};