#pragma once
#include "PlayerOne.h"
#include "PlayerTwo.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "tile.h"


class drawmap {
public:
	drawmap();
	void createmap(sf::Vector2i pos);
	void deletemap();
	void checkmouse(RenderWindow& window);
	std::vector<tile*> tilevector;
	std::vector<sf::FloatRect> wallBounds;

private: 
	
	
};