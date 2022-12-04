#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Character.h"

class audio {

public:
	audio();
	void calcaudio(RenderWindow& window, Character& playerone, Character& playertwo);
	
	sf::SoundBuffer jumpbuffer;
	sf::SoundBuffer movebuffer;
	sf::SoundBuffer hitbuffer;
	sf::SoundBuffer firebuffer;
	// sf::SoundBuffer jumpbuffer; make sure each buffer has their own sound


	sf::Sound sound1;
	sf::Sound sound2;
};