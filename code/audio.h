#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Character.h"

class audio {

public:
	audio();
	void calcaudio(RenderWindow& window, Character& playerone, Character& playertwo);
	

};