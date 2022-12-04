#pragma once
#include "hud.h"

hud::hud()
{

	font.loadFromFile("graphics/arial.ttf");
	sf::Text build;

	sf::Text gameover;

	sf::Text player1deaths;
	player1deathstext.setFont(font);
	player1deathstext.setCharacterSize(24);
	player1deathstext.setPosition(20, 20);

	sf::Text player2deaths;
	player1deathstext.setFont(font);
	player2deathstext.setCharacterSize(24);
	player1deathstext.setPosition(20, 20);




	sf::RectangleShape player1health;

	sf::RectangleShape player2helath;
}