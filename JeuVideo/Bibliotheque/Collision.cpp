#include "stdafx.h"
#include "Collision.h"


Collision::Collision()
{
	//Declaration a la main de toutes les boundingBox car je n'ai pas trouve une methode plus rentable
	//en terme de temps et d'efficacite : l'utilisation de tmxlite est tres mal documentee.
	sf::FloatRect boundingBox0(sf::Vector2f(0, 64), sf::Vector2f(16, 112));
	sf::FloatRect boundingBox1(sf::Vector2f(0, 176), sf::Vector2f(192, 16));
	sf::FloatRect boundingBox2(sf::Vector2f(176, 144), sf::Vector2f(96, 64));
	sf::FloatRect boundingBox3(sf::Vector2f(304, 144), sf::Vector2f(64, 32));
	sf::FloatRect boundingBox4(sf::Vector2f(400, 80), sf::Vector2f(96, 32));
	sf::FloatRect boundingBox5(sf::Vector2f(384, 176), sf::Vector2f(160, 48));
	sf::FloatRect boundingBox6(sf::Vector2f(512, 80), sf::Vector2f(32, 32));
	sf::FloatRect boundingBox7(sf::Vector2f(576, 176), sf::Vector2f(32, 32));
	sf::FloatRect boundingBox8(sf::Vector2f(640, 176), sf::Vector2f(480, 48));
	sf::FloatRect boundingBox9(sf::Vector2f(848, 144), sf::Vector2f(192, 32));
	sf::FloatRect boundingBox9bis(sf::Vector2f(896, 112), sf::Vector2f(128, 32));
	sf::FloatRect boundingBox10(sf::Vector2f(912, 80), sf::Vector2f(64, 32));
	sf::FloatRect boundingBox11(sf::Vector2f(976, 0), sf::Vector2f(192, 32));
	sf::FloatRect boundingBox12(sf::Vector2f(1024, 32), sf::Vector2f(128, 32));
	sf::FloatRect boundingBox13(sf::Vector2f(1136, 144), sf::Vector2f(48, 48));
	sf::FloatRect boundingBox14(sf::Vector2f(1200, 176), sf::Vector2f(48, 48));
	sf::FloatRect boundingBox15(sf::Vector2f(1200, 48), sf::Vector2f(48, 48));
	sf::FloatRect boundingBox16(sf::Vector2f(1280, 176), sf::Vector2f(48, 48));
	sf::FloatRect boundingBox17(sf::Vector2f(1296, 48), sf::Vector2f(32, 16));
	sf::FloatRect boundingBox18(sf::Vector2f(1280, 32), sf::Vector2f(64, 46));
	sf::FloatRect boundingBox19(sf::Vector2f(1264, 0), sf::Vector2f(96, 32));
	sf::FloatRect boundingBox20(sf::Vector2f(1360, 192), sf::Vector2f(64, 32));
	sf::FloatRect boundingBox21(sf::Vector2f(1408, 160), sf::Vector2f(48, 64));
	sf::FloatRect boundingBox22(sf::Vector2f(1456, 144), sf::Vector2f(48, 80));
	sf::FloatRect boundingBox23(sf::Vector2f(1504, 176), sf::Vector2f(32, 48));
	sf::FloatRect boundingBox24(sf::Vector2f(1536, 208), sf::Vector2f(64, 16));
	sf::FloatRect boundingBox25(sf::Vector2f(1584, 64), sf::Vector2f(16, 160));

	boxs.push_back(boundingBox0);
	boxs.push_back(boundingBox1); 
	boxs.push_back(boundingBox2);
	boxs.push_back(boundingBox3);
	boxs.push_back(boundingBox4);
	boxs.push_back(boundingBox5);
	boxs.push_back(boundingBox6);
	boxs.push_back(boundingBox7);
	boxs.push_back(boundingBox8);
	boxs.push_back(boundingBox9);
	boxs.push_back(boundingBox9bis);
	boxs.push_back(boundingBox10);
	boxs.push_back(boundingBox11);
	boxs.push_back(boundingBox12);
	boxs.push_back(boundingBox13);
	boxs.push_back(boundingBox14);
	boxs.push_back(boundingBox15);
	boxs.push_back(boundingBox16);
	boxs.push_back(boundingBox17);
	boxs.push_back(boundingBox18);
	boxs.push_back(boundingBox19);
	boxs.push_back(boundingBox20);
	boxs.push_back(boundingBox21);
	boxs.push_back(boundingBox22);
	boxs.push_back(boundingBox23);
	boxs.push_back(boundingBox24);
	boxs.push_back(boundingBox25);

	sf::FloatRect dead1(sf::Vector2f(272, 208), sf::Vector2f(112, 16));
	sf::FloatRect dead2(sf::Vector2f(544, 208), sf::Vector2f(96, 16));
	sf::FloatRect dead3(sf::Vector2f(1120, 208), sf::Vector2f(240, 16));

	dead.push_back(dead1);
	dead.push_back(dead2);
	dead.push_back(dead3);
}

bool Collision::CollisionTestX(float speed, int x, int y, int wRun, int hRun) {
	
	//Declaration de la future HitBox du perso
	sf::FloatRect boundingBoxPerso(sf::Vector2f(x + speed, y), sf::Vector2f(wRun, hRun));
	for (auto i : boxs) {
		if (boundingBoxPerso.intersects(i)) {   //si le perso est en contact avec une des boxs: collision.
			return true;
		}
	}

	//Box plus petite pour avoir l'interaction
	sf::FloatRect boundingBoxPerso2(sf::Vector2f(x + speed*0.5, y), sf::Vector2f(wRun, hRun));
	for (auto i : activables) {
		if (boundingBoxPerso2.intersects(i)) { //si le perso est en contact avec une des boxs: collision.
			return true;
		}
	}
	return false;
}

bool Collision::CollisionTestY(float speed, int x, int y, int wRun, int hRun) {

	//Declaration de la future HitBox du perso
	sf::FloatRect boundingBoxPerso(sf::Vector2f(x, y + speed), sf::Vector2f(wRun, hRun));

	for (auto i : boxs) {
		if (boundingBoxPerso.intersects(i)) {  //si le perso est en contact avec une des boxs: collision.
			return true;
		}
	}
	return false;
}

bool Collision::JumpTest(float speed, int x, int y, int wRun, int hRun) {

	//Declaration de la future HitBox du perso
	sf::FloatRect boundingBoxPerso(sf::Vector2f(x, y - speed), sf::Vector2f(wRun, hRun));

	for (auto i : boxs) {
		if (boundingBoxPerso.intersects(i)) {   //si le perso est en contact avec une des boxs: collision.
			return true;
		}
	}
	return false;
}

bool Collision::FallTest(int x, int y, int wIdle, int hIdle)
{
	//Le perso tombe si le pixel en dessous de lui n'est pas en contact avec un sol.
	sf::FloatRect boundingBoxPerso(sf::Vector2f(x, y + 1), sf::Vector2f(wIdle, hIdle));
	for (auto i : boxs) {
		if (boundingBoxPerso.intersects(i)) {
			return false;
		}
	}
	return true;
}

bool Collision::Dead(int x, int y, int wIdle, int hIdle) {

	//Si le personnage touche une des box "trou", il est considéré comme mort.
	sf::FloatRect boundingBoxPerso(sf::Vector2f(x, y), sf::Vector2f(wIdle, hIdle));
	for (auto i : dead) {
		if (boundingBoxPerso.intersects(i)) {
			return true;
		}
	}
	return false;
}