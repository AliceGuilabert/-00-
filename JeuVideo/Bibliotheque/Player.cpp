#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	x = 690.0f;
	y = 143.0f;
	direction = 1;
	frameNumber = 0;
	fall = false;
	frameTimer = TIME_BETWEEN_2_FRAMES_PLAYER;
}

//GETTERS et SETTERS
void Player::setX(float valeur) { x = valeur; }
void Player::setY(float valeur) { y = valeur; }
void Player::setWIdle(int valeur) { wIdle = valeur; }
void Player::setHIdle(int valeur) { hIdle = valeur; }
void Player::setWRun(int valeur) { wRun= valeur; }
void Player::setHRun(int valeur) { hRun = valeur; }
void Player::setWJump(int valeur) { wJump = valeur; }
void Player::setHJump(int valeur) { hJump = valeur; }
void Player::setFrameMaxIdle(int valeur) { frameMaxIdle = valeur; }
void Player::setFrameMaxRun(int valeur) { frameMaxRun = valeur; }
void Player::setFrameMaxJump(int valeur) { frameMaxJump = valeur; }
void Player::setDirection(int valeur) { direction = valeur; }
float Player::getX() { return x; }
float Player::getY() { return y; }
int Player::getWRun() { return wRun; }
int Player::getHRun() { return hRun; }



void Player::drawPlayer(sf::RenderWindow &window, std::string etat) {

	//Cas de la course
	if (etat == "RunLeft" || etat == "RunRight")
	{
		//On attends un temps entre chaque frame 
		//et on revient à la premiere frame quand on atteint la derniere
		if (frameTimer <= 0)
		{
			frameTimer = TIME_BETWEEN_2_FRAMES_PLAYER;
			frameNumber++;
			if (frameNumber >= frameMaxRun)
				frameNumber = 0;
		}
		else
		{
			frameTimer--;
		}

		//On applique la texture course, puis on oriente suivant la course droite ou gauche.
		hero.setTexture(heroTextureRun);
		hero.setTextureRect(sf::IntRect(
			(etat == "RunLeft") ? (frameNumber+1) * wRun : frameNumber * wRun, 
			1, (etat == "RunLeft") ? -wRun : wRun, hRun));
	}
	
	//Cas de l'attente
	else if (etat == "Idle") {

		//On attends un temps entre chaque frame 
		//et on revient à la premiere frame quand on atteint la derniere
		if (frameTimer <= 0)
		{
			frameTimer = TIME_BETWEEN_2_FRAMES_PLAYER;
			frameNumber++;
			if (frameNumber >= frameMaxIdle)
				frameNumber = 0;
		}
		else
		{
			frameTimer--;
		}

		//On applique la texture d'attente,que l'on oriente par rapport au dernier deplacement.
		hero.setTexture(heroTextureIdle);
		hero.setTextureRect(sf::IntRect((direction == 1 ) ? frameNumber * wIdle : (frameNumber + 1) * wIdle, 
			1, (direction == 1) ? wIdle : -wIdle, hIdle));
	}
	
	//On positionne le personnage
	hero.setPosition(sf::Vector2f(x, y));
	//et on le trace.
	window.draw(hero);

	return;
}

