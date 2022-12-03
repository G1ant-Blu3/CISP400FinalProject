#pragma once
#include "projectilemap.h"


projectilemap::projectilemap() 
{

}
void projectilemap::createprojectile(Character& player) 
{
	if (player.left == true)
	{
		sf::Vector2f pos(player.getSprite().getGlobalBounds().left - 31, player.getSprite().getGlobalBounds().top + 32);
		projectile* proj = new projectile(pos);
		proj->leftward = true;
		projectilevector.push_back(proj);

	}
	if (player.right == true) 
	{
		sf::Vector2f pos(player.getSprite().getGlobalBounds().width + player.getSprite().getGlobalBounds().left + 31, player.getSprite().getGlobalBounds().top + 32);
		projectile* proj = new projectile(pos);
		proj->rightward = true;
		projectilevector.push_back(proj);

	}
		

}
void  projectilemap::projecticalc(float elaspedtime,RenderWindow& window, Character& player, Character& otherplayer, drawmap& map) 
{
	if (Keyboard::isKeyPressed(Keyboard::F))
	{
		createprojectile(player);
	}
	if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		createprojectile(otherplayer);
	}
	float offset = speed * elaspedtime;
	for (int i = 0; i < projectilevector.size(); i++)
	{
		if (projectilevector[i]->leftward == true)
		{
			projectilevector[i]->position.x -= offset;
			projectilevector[i]->sprite.setPosition(projectilevector[i]->position);
		}
		if (projectilevector[i]->rightward == true)
		{
			projectilevector[i]->position.x += offset;
			projectilevector[i]->sprite.setPosition(projectilevector[i]->position);
		}
		for (int i = 0; i < map.tilevector.size(); i++)
		{
			for (int j = 0; j < projectilevector.size(); j++) // pay close attention to if the i or the j is part of the vector
			{
				if (projectilevector[j]->sprite.getGlobalBounds().intersects(map.tilevector[i]->sprite.getGlobalBounds()))
				{
				 projectilevector.erase(projectilevector.begin() + j);// why does it have to have to beggging idk????/
				
				

				}
			}
		}
	}

}
void projectilemap::removeprojectile() {

	//use vector.erase();
}





