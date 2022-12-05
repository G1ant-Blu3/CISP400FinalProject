#pragma once
#include <SFML/Graphics.hpp>
#include "projectile.h"


using namespace sf;


class projectilemap {
public:
	projectilemap();
	void createprojectile(Character& player);
	void removeprojectile();
	std::vector<projectile*> projectilevector;
	void projecticalc(float speed, RenderWindow& window, Character& player, Character& otherplayer, drawmap& map, float bullettime);
	bool justdestoryed = false;
	float speed = 1000.0;

private:


};