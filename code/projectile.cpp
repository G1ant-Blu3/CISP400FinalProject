#pragma once
#include "projectile.h"



projectile::projectile(sf::Vector2f pos) {

	position = pos;

	projectiletexture.loadFromFile("graphics/rock.png");
	sf::IntRect rectangle(30, 30, 30, 30);
	sprite.setTextureRect(rectangle);

	sprite.setTexture(projectiletexture); // remeber to add this, wasted time firgureing it out

	sprite.setPosition(position.x - 15, position.y - 15); // to get center, make it half of rectange size
}