#pragma once
#include "hud.h"

hud::hud()
{

	font.loadFromFile("graphics/arial.ttf");
	sf::Text build;

	sf::Text gameover;

	sf::Text player1deaths;
	player1deaths.setFont(font);
	player1deaths.setCharacterSize(24);

	sf::Text player2deaths;
	player1deaths.setFont(font);
	player2deaths.setCharacterSize(24);


	sf::Text gameover;

	sf::RectangleShape player1health;

	sf::RectangleShape player2helath;
}