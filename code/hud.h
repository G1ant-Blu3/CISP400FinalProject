#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"

class hud {

public:
	hud(Window& window);

	Font font;
	Texture healthImage;
	Text build;
	Text gameover;
	Text player1deathstext;
	Text player2deathstext;
	RectangleShape player1healthbar;
	RectangleShape player2healthbar;

	float player1deaths;
	float player2deaths;
	float player1heatlh;
	float player2health;

	void updatehud(RenderWindow& window, Character& playerone, Character& playertwo);
	
};


