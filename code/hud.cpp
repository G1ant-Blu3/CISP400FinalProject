#include "hud.h"

hud::hud(Window& window)
{

	font.loadFromFile("graphics/arial.ttf");
	healthImage.loadFromFile("graphics/healthState.png");

	player1deathstext.setFont(font);
	player1deathstext.setFillColor(Color::Black);
	player1deathstext.setCharacterSize(24);
	player1deathstext.setPosition(7.0, 20.0);

	/*player2deathstext.setFont(font);
	player2deathstext.setCharacterSize(24);
	player2deathstext.setPosition(20, 20);*/
	
	player1healthbar.setTexture(&healthImage);
	player1healthbar.setTextureRect(IntRect(0, 0, healthImage.getSize().x / 2, healthImage.getSize().y));
	player1healthbar.setSize(Vector2f(500.0, 15.0));
	player1healthbar.setOutlineColor(Color::Black);
	player1healthbar.setOutlineThickness(2.0);
	player1healthbar.setPosition(10.0, 5.0);
}
void hud::updatehud(RenderWindow& window, Character& playerone, Character& playertwo)
{
	player1deathstext.setString("Player 1 Deaths: " + std::to_string(playerone.timesdead));
	//player2deathstext.setString("Deaths: ");
	window.draw(player1deathstext);
	//window.draw(player2deathstext);
	window.draw(player1healthbar);
}