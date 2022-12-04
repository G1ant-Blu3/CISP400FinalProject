#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"

class audio {

public:
	audio();
	void calcaudio(RenderWindow& window, Character& playerone, Character& playertwo);
	

};