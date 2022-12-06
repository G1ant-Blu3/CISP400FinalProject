#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Character.h"
#include "projectilemap.h"
#include "drawmap.h"


class audio {

public:
	audio();
	void calcaudioplayerone(RenderWindow& window, Character& playerone);
	void calcaudioplayertwo(RenderWindow& window, Character& playertwo);
	void calcaudiomap(drawmap& map, projectilemap& projmap);
	
	
	sf::SoundBuffer bufferbackgound;
	sf::SoundBuffer jumpbuffer;
	sf::SoundBuffer movebuffer;
	sf::SoundBuffer hitbuffer;
	sf::SoundBuffer firebuffer;
	sf::SoundBuffer buildbuffer;
	sf::SoundBuffer destroyedbuffer;
	sf::SoundBuffer deadbuffer;
	// sf::SoundBuffer jumpbuffer; make sure each buffer has their own sound
	sf::Sound background;
	sf::Sound dead;
	sf::Sound sound1;
	sf::Sound sound2;
	sf::Sound hit1;
	sf::Sound hit2;
	sf::Sound build;
	sf::Sound destroyed;

};