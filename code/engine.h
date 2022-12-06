#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "PlayerOne.h"
#include "PlayerTwo.h"
#include "drawmap.h"
#include "projectilemap.h"
#include "animationone.h"
#include "animationtwo.h"
#include "hud.h"
#include "audio.h"

using namespace std;

class engine {

public:
	engine();
	void run();
	RenderWindow window;
	audio audio;
	animationone animationone;
	animationtwo animationtwo;
	PlayerOne playerOne;
	PlayerTwo playerTwo;
	drawmap map;
	projectilemap projmap;
	Sprite s_background;
	Texture background;
	Vector2f resolution;
	Clock proj;
	Clock clock;
private:
	
};
