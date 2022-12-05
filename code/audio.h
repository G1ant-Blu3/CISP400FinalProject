#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Character.h"
#include "drawmap.h"


class audio {

public:
	audio();
	void calcaudio(RenderWindow& window, Character& playerone, Character& playertwo);
	void audiodestoryed();
	void audiobuilt();
	
	sf::SoundBuffer jumpbuffer;
	sf::SoundBuffer movebuffer;
	sf::SoundBuffer hitbuffer;
	sf::SoundBuffer firebuffer;
	sf::SoundBuffer buildbuffer;
	sf::SoundBuffer destroyedbuffer;
	// sf::SoundBuffer jumpbuffer; make sure each buffer has their own sound


	sf::Sound sound1;
	sf::Sound sound2;
	sf::Sound hit1;
	sf::Sound hit2;
	sf::Sound build;
	sf::Sound destroyed;

};