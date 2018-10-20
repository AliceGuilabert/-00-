#include "stdafx.h"
#include "XMLHandler.h"

XMLHandler::XMLHandler()
{
	//On parse le XML
	pugi::xml_parse_result result = doc.load_file("C:/Users/Alice/Desktop/Cours_2A/C++/csc_4526/XML_text.xml");

	if (!result) {
		std::cout << "XML n'a pas réussi à parser !" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void XMLHandler::updatePlayer(int NBgraphic, Player & player)
{
	pugi::xml_node node; 

	switch (NBgraphic)  //Suivant le Graphique on charge la bonne node.
	{
	case(1): {
		node = doc.child("Graphic1").child("Animation");
		break;
	}
	case(2): {
		node = doc.child("Graphic2").child("Animation");
		break;
	}
	case(3): {
		node = doc.child("Graphic3").child("Animation");
		break;
	}
	}

	//Chargement des textures
	player.heroTextureIdle.loadFromFile(node.child("Idle").attribute("path").as_string());
	player.heroTextureRun.loadFromFile(node.child("Run").attribute("path").as_string());

	//Attribution des variables
	player.setWIdle(node.child("Idle").attribute("width").as_int());
	player.setHIdle(node.child("Idle").attribute("height").as_int());
	player.setWRun(node.child("Run").attribute("width").as_int());
	player.setHRun(node.child("Run").attribute("height").as_int());
	player.setWJump(node.child("Jump").attribute("width").as_int());
	player.setHJump(node.child("Jump").attribute("height").as_int());
	player.setFrameMaxIdle(node.child("Idle").attribute("nbFrames").as_int());
	player.setFrameMaxRun(node.child("Run").attribute("nbFrames").as_int());
	player.setFrameMaxJump(node.child("Jump").attribute("nbFrames").as_int());
}

pugi::xml_node XMLHandler::updateActivable() {
	
	//Retourne juste la node pour ne pas avoir à parser encore.
	return doc.child("Objects");
}
