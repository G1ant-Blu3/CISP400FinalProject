#pragma once
#include <SFML/Graphics.hpp>

class tile {

public: 
	tile(sf::Vector2i pos);

	sf::Texture tiletexture;
	sf::Sprite sprite;
	sf::Sprite returnsprite();
	



private: 

};