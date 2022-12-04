#include <SFML/Graphics.hpp>

class hud {

public:
	hud();

	sf::Font font;
	sf::Text build;
	sf::Text gameover;
	sf::Text player1deaths;
	sf::Text player2deaths;
	sf::Text gameover;
	sf::RectangleShape player1health;
	sf::RectangleShape player2helath;

	float player1deaths;
	float player2deaths;
	float player1heatlh;
	float player2health;

};


