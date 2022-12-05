#pragma once
#include "audio.h"

audio::audio() {

	jumpbuffer.loadFromFile("audio/jump.wav");
	movebuffer;
	hitbuffer;
	destroyedbuffer.loadFromFile("audio/destroyed.wav");
	destroyed.setBuffer(destroyedbuffer);
	buildbuffer.loadFromFile("audio/built.wav");
	build.setBuffer(buildbuffer);
	//build.setPlayingOffset(sf::seconds(1.0));
	firebuffer.loadFromFile("audio/fire.wav");
	destroyedbuffer;
}
void audio::calcaudio(RenderWindow& window, Character& playerone, Character& playertwo, projectilemap& projmap, drawmap& map)
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
	if (projmap.justdestoryed == true)
	{
		projmap.justdestoryed = false;
		destroyed.play();
	}
	if (map.justbuilt == true)
	{
		
		build.play();
		map.justbuilt = false;
	}
	
	


}
