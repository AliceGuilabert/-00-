#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Collision.h"
#include "ActivableHandler.h"



class CommandHandler
{
public:
	CommandHandler();
	
	//Fonction prenant en charge les appuits de touches et les actions associées.
	std::string Handle(sf::RenderWindow & window, Player & player,
		bool KeyPressed, Collision collision, int NbGraph, ActivableHandler &activableHandler);

private:
	float speed;
	int timeBeforeJumpAgain;
	int timeJump;
	int jumpSpeed;
	float gravite;
	float fallSpeed;
	
};

