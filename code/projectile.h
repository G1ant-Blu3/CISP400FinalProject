#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Character.h"


class projectile {
public:
	projectile(sf::Vector2f);
	
	//void projectile(sf::RenderWindow& window);
	

	sf::Vector2f position;
	sf::Texture projectiletexture;
	sf::Sprite sprite;
	bool leftward = false;
	bool rightward = false;


private:
	

};