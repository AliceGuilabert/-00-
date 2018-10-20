#include "stdafx.h"
#include "CommandHandler.h"


CommandHandler::CommandHandler()
{
	speed = 3.0;
	jumpSpeed = 5.3;
	timeBeforeJumpAgain = 0;
	timeJump = 0;
	gravite = 9.81f;
	fallSpeed = 0;
}

std::string CommandHandler::Handle(sf::RenderWindow & window, 
	Player & player, bool KeyPressed, Collision collision, int NbGraph, ActivableHandler & activableHandler)
{
	//D�claration d'un temps entre 2 sauts qui lorsqu'il est initialis� est d�cr�ment� � chaque frame.
	if (timeBeforeJumpAgain != 0) {
		timeBeforeJumpAgain--;
	}

	//Si on rentre, le personnage est en train de sauter.
	if (timeJump > 0) {
		timeJump--;
		//Test pour pr�voir la collision en hauteur avant de sauter.
		bool touche = collision.JumpTest(jumpSpeed, player.getX(),
			player.getY(), player.getWRun(), player.getHRun());
		if (!touche) {
			player.setY(player.getY() - jumpSpeed);
		}
		else {
			//On a touch� en hauteur : on s'arr�te.
			timeJump = 0;
		}
	}


	//Test si le personnage touche le sol ou est en train de tomber.
	player.fall = collision.FallTest(player.getX(),
		player.getY(), player.getWRun(), player.getHRun());

	if (player.fall) {
		//On tombe, on incr�mente la vitesse de chute pour coller � la gravit� r�elle.
		fallSpeed += gravite;
		bool touche = collision.CollisionTestY(fallSpeed*0.016f, player.getX(),
			player.getY(), player.getWRun(), player.getHRun());
		if (!touche && timeJump == 0) { //On ne saute plus et on ne touche pas le sol � la prochaine frame.
			player.setY(player.getY() + fallSpeed*0.016f);
		}
		else {
			//On ralenti pour ne pas rentrer dans la mati�re du sol
			fallSpeed = std::max(fallSpeed * 0.5f, 1.0f);
		}

		//Test pour savoir si le perso est tombe dans un trou
		bool isDead = collision.Dead(player.getX(),
			player.getY(), player.getWRun(), player.getHRun());
		if (isDead) {
			//Reinitialisation des coordonn�es � celle de d�part
			player.setX(690.0f);
			player.setY(143.0f);
		}
	}
	else { //Lorsqu'on atterit on r�initialise la vitesse de chute.
		fallSpeed = 0.0f;
	}


	if (KeyPressed) {

		//Action de saut.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player.fall == false && timeBeforeJumpAgain == 0) {
			timeBeforeJumpAgain = 30; //On commence le compteur
			timeJump = 10; //On commence le compteur;
			//return "Jump";
		}

		//Action d�placement gauche
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			//Test de collision avant d�placement
			bool touche = collision.CollisionTestX(-speed, player.getX(),
				player.getY(), player.getWRun(), player.getHRun());
			if (!touche) {
				player.setX(player.getX() - speed);
				player.setDirection(-1);
				return "RunLeft";
			}
			return "RunLeft";
		}

		//Action d�placement droite
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			//Test de collision avant d�placement
			bool touche = collision.CollisionTestX(speed, player.getX(),
				player.getY(), player.getWRun(), player.getHRun());
			if (!touche) {
				player.setX(player.getX() + speed);
				player.setDirection(1);
				return "RunRight";
			}
			
			return "RunRight";
		}

		/*
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			--> A d�finir : blocage lors des combats ?
		}
		*/
		
		//Action interraction avec les objets.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space )) {
			//on retourne directement la valeur pour gerer le changement de niveau
			return activableHandler.Interraction(NbGraph, player.getX(),
				player.getY(), player.getWRun(), player.getHRun(), window);
		}
	}
	else {
		//Si on appuit sur rien on renvient Idle
		return "Idle";
	}	
}
