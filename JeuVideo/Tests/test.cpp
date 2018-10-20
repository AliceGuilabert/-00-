#include "pch.h"
#include "../Bibliotheque/monMain.h"
#include <iostream>
#include <string>
#include <sstream>
#include "../../tmxlite-master/tmxlite/src/detail/pugixml.hpp"

TEST(TestReadXML, TestGraphic1_Idle) {

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("../../XML_text.xml");
	EXPECT_NE(0, result);

	auto node = doc.child("Graphic1").child("Animation").child("Idle");
	int width = node.attribute("width").as_int();
	int height = node.attribute("height").as_int();
	int nbFrames = node.attribute("nbFrames").as_int();
	std::string path = node.attribute("path").as_string();

	EXPECT_EQ(width, 19);
	EXPECT_EQ(height, 34);
	EXPECT_EQ(nbFrames, 12);
	EXPECT_EQ(path, "../../idleGraph1.png");

	EXPECT_TRUE(true);
}

TEST(TestReadXML, TestGraphic1_Run) {

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("../../XML_text.xml");
	EXPECT_NE(0, result);

	auto node = doc.child("Graphic1").child("Animation").child("Run");
	int width = node.attribute("width").as_int();
	int height = node.attribute("height").as_int();
	int nbFrames = node.attribute("nbFrames").as_int();
	std::string path = node.attribute("path").as_string();

	EXPECT_EQ(width, 21);
	EXPECT_EQ(height, 33);
	EXPECT_EQ(nbFrames, 7);
	EXPECT_EQ(path, "../../runGraph1.png");

	EXPECT_TRUE(true);
}

TEST(TestReadXML, TestActivable) {

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("../../XML_text.xml");
	EXPECT_NE(0, result);

	auto node = doc.child("Objects");
	for (auto i : node.children()) {
		if (strcmp(i.name(), "Gemme") == 0) {
			std::string name = i.attribute("name").as_string();
			std::string texte1 = i.attribute("texte1").as_string();
			std::string texte2 = i.attribute("texte2").as_string();
			std::string texte3 = i.attribute("texte3").as_string();
			int x = i.attribute("x").as_int();
			int y = i.attribute("y").as_int();


			EXPECT_EQ(x, 300);
			EXPECT_EQ(y, 180);
			EXPECT_EQ(name, "Gemme1");
			EXPECT_EQ(texte1, "Coucou");
			EXPECT_EQ(texte2, "coucou2");
			EXPECT_EQ(texte3, "coucou3");

		}
	}

	EXPECT_TRUE(true);
}