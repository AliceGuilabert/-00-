#pragma once

#include "../../tmxlite-master/tmxlite/src/detail/pugixml.hpp"
#include <iostream>
#include "Player.h"
#include "ActivableHandler.h"

class XMLHandler
{
public:
	XMLHandler();

	//Update et chargement des attributs du personnage
	void updatePlayer(int NBgraphic, Player & player);

	//Update des activables
	pugi::xml_node updateActivable();

private:
	pugi::xml_document doc;
	
};

