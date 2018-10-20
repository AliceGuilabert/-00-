#include "stdafx.h"
#include "Loop.h"


void Loop::Start(void)
{
	if (gameState != Uninitialized)
		return;

	mainWindow.create(sf::VideoMode(1920,1080), "Fenetre principale");
	gameState = Loop::MainMenu; //Ecran de demarrage.

	while (!Exit()) //Temps qu'on ne quitte pas, on execute la loop.
	{
		MainLoop();
	}

	mainWindow.close();
}

bool Loop::Exit()					//TODO --> rendre les Exits directement là
{
	if (gameState == Loop::Exiting)
		return true;
	else
		return false;
}

void Loop::MainLoop()
{
	sf::Event currentEvent;
	while (mainWindow.waitEvent(currentEvent))
	{
		switch (gameState) //suivant l'etat du jeu differentes actions.
		{
		case Loop::Playing:
		{
			ShowGame();			
			break;
		}

		case Loop::MainMenu:
		{
			ShowMenu();
			break;
		}

		case Loop::Cinematic_: {
			ShowCinematic();
			break;
		}
		}
	}
}

void Loop::ShowMenu()
{
	Menu menu;
	menu.Action(mainWindow); //On montre le menu et quand on return on change l'etat
	gameState = Cinematic_;
}

void Loop::ShowCinematic()
{
	Cinematic cinematic;
	cinematic.Show(mainWindow);  //On montre le menu et quand on return on change l'etat
	gameState = Playing;
}

void Loop::ShowGame()
{
	GameLoop game;
	game.Start(mainWindow);  //On rentre dans le jeu
	gameState = Exiting ;
}


Loop::GameState Loop::gameState = Uninitialized;
sf::RenderWindow Loop::mainWindow;