#pragma once
#include "audio.h"

audio::audio() {

	jumpbuffer.loadFromFile("audio/jump.wav");
	movebuffer;
	hitbuffer;
	firebuffer.loadFromFile("audio/fire.wav");
}
void audio::calcaudio(RenderWindow& window, Character& playerone, Character& playertwo)
{
	if (playerone.justjumped == true) 
	{
		sound1.setBuffer(jumpbuffer);
		sound1.play();
		playerone.justjumped = false;

	}
	if (playertwo.justjumped == true)
	{
		sound2.setBuffer(jumpbuffer);
		sound2.play();
		playertwo.justjumped = false;


	}
	if (playerone.justfired == true)
	{
		sound1.setBuffer(firebuffer);
		sound1.play();
		playerone.justfired = false;
	}
	if (playertwo.justfired == true)
	{
		sound2.setBuffer(firebuffer);
		sound2.play();
		playertwo.justfired = false;
	}


}