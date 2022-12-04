#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"

class animationtwo
{

public:
	animationtwo();
	void calcanimationtwo(float chnagedtime, Character& player);
	float totaltime;
	float imagestate = 0;
	float switchtime;
	float fastimagestate = 0;
	float fasttotaltime = 0;
	float fastswitchtime;

};