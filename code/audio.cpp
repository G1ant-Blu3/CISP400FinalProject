#pragma once
#include "audio.h"

audio::audio() {

	jumpbuffer.loadFromFile("audio/____.wav");
	movebuffer;
	hitbuffer;
	firebuffer;
}
void audio::calcaudio(RenderWindow& window, Character& playerone, Character& playertwo)
{

}