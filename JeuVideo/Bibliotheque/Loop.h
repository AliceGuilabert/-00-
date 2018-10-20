#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Menu.h"
#include "Cinematic.h"
#include "GameLoop.h"
#include <iostream>

class Loop
{
public:
	static void Start();

private:

	//Lance la sortie du jeu
	static bool Exit();

	//Boucle squelette
	static void MainLoop();

	//Lance le Menu
	static void ShowMenu();

	//Lance la cinematique
	static void ShowCinematic();

	//Lance le jeu
	static void ShowGame();

	enum GameState {
		Uninitialized, MainMenu, Cinematic_, Paused, Playing, Exiting
	};

	static GameState gameState;
	static sf::RenderWindow mainWindow;
};

