#include "projectile.h"



projectile::projectile(sf::Vector2f pos) {

	position = pos;

	projectiletexture.loadFromFile("graphics/magicOrb.png");
	sprite.setTexture(projectiletexture); // remeber to add this, wasted time firgureing it out
	sprite.setScale(0.1,0.1);
	//sprite.setPosition(position.x - 15, position.y - 15); // to get center, make it half of rectange size
}