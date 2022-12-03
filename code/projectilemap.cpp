#pragma once
#include "projectile.h"
#include <SFML/Graphics.hpp>


projectilemap::projectilemap() 
{

}
void projectilemap::createprojectile(RenderWindow& window, Character& player) 
{
	if (player.left = true)
	{
		sf::Vector2f pos(player.getSprite().getGlobalBounds().left - 31, player.getSprite().getGlobalBounds().top - 32);
		projectile* proj = new projectile(pos);
		proj->leftward = true;
		projectilevector.push_back(proj);

	}
	if (player.right == true) 
	{
		sf::Vector2f pos(player.getSprite().getGlobalBounds().width + 31, player.getSprite().getGlobalBounds().top - 32);
		projectile* proj = new projectile(pos);
		proj->rightward = true;
		projectilevector.push_back(proj);

	}
		

}
void  projectilemap::projecticalc(RenderWindow& window, Character& player, Character& otherplayer) 
{

}
void projectilemap::removeprojectile() {

	//use vector.erase();
}





