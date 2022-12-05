#include <SFML/Graphics.hpp>
#include "drawmap.h"



using namespace std;

drawmap::drawmap() {

	
}
void drawmap::createmap(sf::Vector2i pos) {
	tile* tileheap = new tile(pos);
	tilevector.push_back(tileheap);
	wallBounds.push_back(tileheap->sprite.getGlobalBounds());

	
	
}
void drawmap::deletemap() {
	//  texture = sf::Texture(); if you want to free textues during run time
	/*for (int i = 0; i < tilevector.size(); i++) {
		delete tilevector[i];
		}*/    // use this if you manage to create your own texture sf::object
	
	tilevector.clear();
	wallBounds.clear();
	// this does not clear memory, but removes the tiles from the container
}
void drawmap::checkmouse(sf::RenderWindow& window) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		bool draw = true;
		sf::Vector2f pos2f = sf::Vector2f(sf::Mouse::getPosition(window));
		sf::Vector2i pos = (sf::Mouse::getPosition(window));
		for(int i = 0; i < tilevector.size();i++){
			if(wallBounds[i].contains(pos2f)) {
				//does not work as intented, you need to look through everyhthing
				//if one tile does not contain it for he ith element, then i will return false
				 draw = false;
			}
			
			
		}
		if (tilevector.size() == 0 || draw == true) {
			
			createmap(pos);
			justbuilt = true;

		}
		
		
		

	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

		deletemap();
		

	}
	    

}

