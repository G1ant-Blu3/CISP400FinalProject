#include <SFML/Graphics.hpp>
#include "Character.h"

class hud {

public:
	hud();

	sf::Font font;
	sf::Text build;
	sf::Text gameover;
	sf::Text player1deathstext;
	sf::Text player2deathstext;
	sf::RectangleShape player1health;
	sf::RectangleShape player2helath;

	float player1deaths;
	float player2deaths;
	float player1heatlh;
	float player2health;

	void updatehud(RenderWindow& window, Character& playerone, Character& playertwo) 
	{
		player1deathstext.setString("Deaths: ");
		player2deathstext.setString("Deaths: ");
		window.draw(player1deathstext);
		window.draw(player2deathstext);
	}
};


