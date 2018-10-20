#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <Vector>
#include <iostream>
 


class Player
{
public:
	Player();

	//Fonction dessinant le personnage
	void drawPlayer(sf::RenderWindow &window, std::string etat);

	sf::RectangleShape sprite;

	//getters et setters
	float getX();
	float getY();
	int getWRun();
	int getHRun();
	void setX(float x);
	void setY(float y);
	void setWIdle(int x);
	void setHIdle(int y);
	void setWRun(int x);
	void setHRun(int y);
	void setWJump(int x);
	void setHJump(int y);
	void setFrameMaxIdle(int x);
	void setFrameMaxRun(int x);
	void setFrameMaxJump(int x);
	void setDirection(int x);

	sf::Texture heroTextureIdle;
	sf::Texture heroTextureRun;
	sf::Texture heroTextureJump;
	sf::Sprite hero;

	bool fall;

private:

	//position
	float x, y;
	int wIdle, wRun, wJump;
	int hIdle, hRun, hJump; 
	int direction;
	std::string etat;
	

	//Frames
	int frameNumber, frameTimer, frameMaxRun, frameMaxIdle, frameMaxJump;
	const int TIME_BETWEEN_2_FRAMES_PLAYER = 4;
	
};
