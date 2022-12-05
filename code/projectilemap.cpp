#include "projectilemap.h"


projectilemap::projectilemap() 
{

}
void projectilemap::createprojectile(Character& player) 
{
	player.justfired = true;
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
void  projectilemap::projecticalc(float elaspedtime,RenderWindow& window, Character& player, Character& otherplayer, drawmap& map, float bullettime) 
{

	if (Keyboard::isKeyPressed(Keyboard::F))
	{
		if (player.firedtime < bullettime)
		{
			player.isfiring = true;
			createprojectile(player);
			player.firedtime = bullettime + 100 ;
			
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		if (otherplayer.firedtime < bullettime)
		{
			otherplayer.isfiring = true;
			createprojectile(otherplayer);
			otherplayer.firedtime = bullettime + 100;
		}
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
		if (projectilevector[i]->sprite.getGlobalBounds().intersects(player.getSprite().getGlobalBounds()))
		{
			projectilevector.erase(projectilevector.begin() + i);
			player.ishit = true;
			player.beenhit = true;
			player.justhit = true;
		}
		if (projectilevector[i]->sprite.getGlobalBounds().intersects(otherplayer.getSprite().getGlobalBounds()))
		{
			projectilevector.erase(projectilevector.begin() + i);
			otherplayer.ishit = true;
			otherplayer.beenhit = true;
			otherplayer.justhit = true;
		}
		for (int i = 0; i < map.tilevector.size(); i++)
		{
			for (int j = 0; j < projectilevector.size(); j++) // pay close attention to if the i or the j is part of the vector
			{
				if (projectilevector[j]->sprite.getGlobalBounds().intersects(map.wallBounds[i]))
				{
				 projectilevector.erase(projectilevector.begin() + j);// why does it have to have to beggging idk????/
				 map.tilevector.erase(map.tilevector.begin() + i);
				 map.wallBounds.erase(map.wallBounds.begin() + i); // disable this if you want brocks to stay
				 justdestoryed = true;
				

				}

				if (projectilevector[j]->sprite.getGlobalBounds().left < 0)
				{
					projectilevector.erase(projectilevector.begin() + j);
					
				}
				if (projectilevector[j]->sprite.getGlobalBounds().left > window.getSize().x)
				{
					projectilevector.erase(projectilevector.begin() + j);

				}
			}
		}
	}

}
void projectilemap::removeprojectile() {

	//use vector.erase();
}





