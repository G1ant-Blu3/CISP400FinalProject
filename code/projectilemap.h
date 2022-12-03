#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "projectile.h"

#include <vector>

using namespace sf;


class projectilemap {
public:
	projectilemap();
	void createprojectile(RenderWindow& window, Character& player);
	void removeprojectile();
	std::vector<projectile*> projectilevector;
	void projecticalc(RenderWindow& window, Character& player, Character& otherplayer);
	
	

private:


};