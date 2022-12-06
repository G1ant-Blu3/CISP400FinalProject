#include "audio.h"

audio::audio() {

	bufferbackgound.loadFromFile("audio/background.wav");
	background.setVolume(5.0);
	background.setLoop(true);
	background.setBuffer(bufferbackgound);
	background.play();
	jumpbuffer.loadFromFile("audio/jump.wav");
	movebuffer;
	hitbuffer.loadFromFile("audio/hit.wav");
	hit1.setBuffer(hitbuffer);
	hit2.setBuffer(hitbuffer);
	destroyedbuffer.loadFromFile("audio/destroyed.wav");
	destroyed.setBuffer(destroyedbuffer);
	buildbuffer.loadFromFile("audio/built.wav");
	build.setBuffer(buildbuffer);
	//build.setPlayingOffset(sf::seconds(1.0));
	firebuffer.loadFromFile("audio/fire.wav");
	
	destroyedbuffer;
	deadbuffer.loadFromFile("audio/death.wav");
	dead.setBuffer(deadbuffer);
}
void audio::calcaudioplayerone(RenderWindow& window, Character& playerone)
{
	if (playerone.justjumped == true)
	{
		sound1.setBuffer(jumpbuffer);
		
		sound1.play();
		playerone.justjumped = false;

	}
	if (playerone.justfired == true)
	{
		sound1.setBuffer(firebuffer);
		sound1.play();
		playerone.justfired = false;
	}
	if (playerone.justhitaud == true)
	{
		playerone.justhitaud = false;
		hit1.play();
	}
	if (playerone.justdiedaud == true)
	{
		dead.play();
		playerone.justdiedaud = false;
	}

}

void audio::calcaudioplayertwo(RenderWindow& window, Character& playertwo)
{
	if (playertwo.justdiedaud == true)
	{
		dead.play();
		playertwo.justdiedaud = false;
	}
	if (playertwo.justhitaud == true)
	{
		playertwo.justhitaud = false;
		hit2.play();
	}
	if (playertwo.justjumped == true)
	{
		sound2.setBuffer(jumpbuffer);
		sound2.play();
		playertwo.justjumped = false;
	}
	if (playertwo.justfired == true)
	{
		sound2.setBuffer(firebuffer);
		sound2.play();
		playertwo.justfired = false;
	}

}
void audio::calcaudiomap(drawmap & map,  projectilemap & projmap)
{
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

