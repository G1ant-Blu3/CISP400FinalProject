#include "tile.h"
using namespace std;
tile::tile(sf::Vector2i pos) {
	sf::Vector2f recpos = sf::Vector2f(pos);
	tiletexture.loadFromFile("graphics/tile.png");
	sf::IntRect rectangle(50, 50 , 50, 50);
	sprite.setTextureRect(rectangle);
	
	sprite.setTexture(tiletexture); // remeber to add this, wasted time firgureing it out
	
	sprite.setPosition(recpos.x -25, recpos.y -25); // to get center, make it half of rectange size

   
    
	
}
sf::Sprite tile::returnsprite() {

	
	
	return sprite;
}