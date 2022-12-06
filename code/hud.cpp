#include "hud.h"
#include <iostream>

hud::hud(Window& window)
{
	font.loadFromFile("graphics/arial.ttf");
	healthImage.loadFromFile("graphics/healthState.png");

	build.setFont(font);
	build.setFillColor(Color::Black);
	build.setCharacterSize(24);
	build.setString("Build Mode is ON! Esc to toggle ON/OFF");
	build.setOrigin(build.getLocalBounds().width / 2.0, build.getLocalBounds().height / 2.0);
	build.setPosition(window.getSize().x / 2.0, 15.0);

	player1deathstext.setFont(font);
	player1deathstext.setFillColor(Color::Black);
	player1deathstext.setCharacterSize(24);
	player1deathstext.setPosition(7.0, 20.0);

	player2deathstext.setFont(font);
	player2deathstext.setFillColor(Color::Black);
	player2deathstext.setCharacterSize(24);
	
	player1healthbar.setTexture(&healthImage);
	player1healthbar.setTextureRect(IntRect(0, 0, healthImage.getSize().x / 2, healthImage.getSize().y));
	player1healthbar.setSize(Vector2f(500.0, 15.0));
	player1healthbar.setOutlineColor(Color::Black);
	player1healthbar.setOutlineThickness(2.0);
	player1healthbar.setPosition(10.0, 5.0);

	player2healthbar.setTexture(&healthImage);
	player2healthbar.setScale(-1.0, 1.0);
	player2healthbar.setTextureRect(IntRect(0, 0, healthImage.getSize().x / 2, healthImage.getSize().y));
	player2healthbar.setSize(Vector2f(500.0, 15.0));
	player2healthbar.setOutlineColor(Color::Black);
	player2healthbar.setOutlineThickness(2.0);
	player2healthbar.setPosition(window.getSize().x - 10.0, 5.0);
}
void hud::updatehud(RenderWindow& window, Character& playerone, Character& playertwo, bool buildState)
{
	player1healthbar.setTextureRect(IntRect((-playerone.health + 100) * 2.5, 0, healthImage.getSize().x / 2, healthImage.getSize().y));
	player2healthbar.setTextureRect(IntRect((-playertwo.health + 100) * 2.5, 0, healthImage.getSize().x / 2, healthImage.getSize().y));
	player1deathstext.setString("Player 1 Deaths: " + std::to_string(playerone.timesdead));
	player2deathstext.setString("Player 2 Deaths: " + std::to_string(playertwo.timesdead));
	player2deathstext.setPosition(window.getSize().x - player2deathstext.getGlobalBounds().width - 10.0, 20.0); 
	//applying setPosition here to for playertwo to avoid death counter outside the screen's view
	if(buildState)
	{
		window.draw(build);
	}
	window.draw(player1deathstext);
	window.draw(player2deathstext);
	window.draw(player1healthbar);
	window.draw(player2healthbar);
}