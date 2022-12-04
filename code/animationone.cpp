#pragma once
#include "animationone.h"


animationone::animationone()
{
	totaltime = 0.0;
	switchtime = 1.0;
	fasttotaltime = 0.0;
	fastswitchtime = 0.1;

}
void animationone::calcanimationone(float changedtimesec, Character& player)
{
	fasttotaltime += changedtimesec;
	totaltime += changedtimesec;
	if (totaltime >= switchtime)
	{
		totaltime = 0;
		imagestate++;

	}
	if (fasttotaltime >= fastswitchtime)
	{
		fasttotaltime = 0;
		fastimagestate++;

	}
	if (imagestate == 4) 
	{
		imagestate = 0;
	}
	if (fastimagestate == 4) 
	{
		player.beenhit = false;
		player.isfiring = false;
		fastimagestate = 0;
	}
	if (player.beenhit == false && player.isdead == false && player.isJumping == false && player.isfiring == false && player.isFalling == false)
	{
		if (player.left == true)
		{
			if (imagestate == 0) {
				player.characterTexture.loadFromFile("graphics/Biker_idle/Biker_idle1left.png");
				
				player.characterSprite.setTexture(player.characterTexture,true);
			}
			if (imagestate == 1) {
				player.characterTexture.loadFromFile("graphics/Biker_idle/Biker_idle2left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (imagestate == 2) {
				player.characterTexture.loadFromFile("graphics/Biker_idle/Biker_idle3left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (imagestate == 3) {
				player.characterTexture.loadFromFile("graphics/Biker_idle/Biker_idle4left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			
		}
		if (player.right == true)
		{
			if (imagestate == 0) {
				player.characterTexture.loadFromFile("graphics/Biker_idle/Biker_idle1.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (imagestate == 1) {
				player.characterTexture.loadFromFile("graphics/Biker_idle/Biker_idle2.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (imagestate == 2) {
				player.characterTexture.loadFromFile("graphics/Biker_idle/Biker_idle3.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (imagestate == 3) {
				player.characterTexture.loadFromFile("graphics/Biker_idle/Biker_idle4.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}

		}


	}
	if (player.beenhit == false && player.ismoving == true && player.isJumping == false && player.isFalling == false && player.isfiring == false)
	{
		if (player.right == true)
		{
			if (fastimagestate == 0) 
			{
				player.characterTexture.loadFromFile("graphics/Biker_run/Biker_run1.png");
				player.characterSprite.setTexture(player.characterTexture,true);
			}   
			if (fastimagestate == 1) {
				player.characterTexture.loadFromFile("graphics/Biker_run/Biker_run2.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 2) {
				player.characterTexture.loadFromFile("graphics/Biker_run/Biker_run3.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 3) {
				player.characterTexture.loadFromFile("graphics/Biker_run/Biker_run4.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}

		}
		if (player.left == true)
		{
			if (fastimagestate == 0)
			{
				player.characterTexture.loadFromFile("graphics/Biker_run/Biker_run1Left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 1) {
				player.characterTexture.loadFromFile("graphics/Biker_run/Biker_run2Left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 2) {
				player.characterTexture.loadFromFile("graphics/Biker_run/Biker_run3Left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 3) {
				player.characterTexture.loadFromFile("graphics/Biker_run/Biker_run4Left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
		}
			
	
	}
	if (player.beenhit == false && player.isJumping == true && player.isfiring == false)// first two images are jumping last two are falling
	{

		if (player.right == true)
		{
			if (fastimagestate == 0)
			{
				player.characterTexture.loadFromFile("graphics/Biker_jump/Biker_jump1.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 1) {
				player.characterTexture.loadFromFile("graphics/Biker_jump/Biker_jump2.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 2) {
				player.characterTexture.loadFromFile("graphics/Biker_jump/Biker_jump1.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 3) {
				player.characterTexture.loadFromFile("graphics/Biker_jump/Biker_jump2.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}

		}
		if (player.left == true)
		{
			if (fastimagestate == 0)
			{
				player.characterTexture.loadFromFile("graphics/Biker_jump/Biker_jump1Left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 1) {
				player.characterTexture.loadFromFile("graphics/Biker_jump/Biker_jump2Left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 2) {
				player.characterTexture.loadFromFile("graphics/Biker_jump/Biker_jump1Left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 3) {
				player.characterTexture.loadFromFile("graphics/Biker_jump/Biker_jump2Left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
		}
	}
	if (player.beenhit == false && player.isFalling == true && player.isfiring == false)// first two images are jumping last two are falling
	{

		if (player.right == true)
		{
			if (fastimagestate == 0)
			{
				player.characterTexture.loadFromFile("graphics/Biker_jump/Biker_jump3.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 1) {
				player.characterTexture.loadFromFile("graphics/Biker_jump/Biker_jump4.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 2) {
				player.characterTexture.loadFromFile("graphics/Biker_jump/Biker_jump3.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 3) {
				player.characterTexture.loadFromFile("graphics/Biker_jump/Biker_jump4.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}

		}
		if (player.left == true)
		{
			if (fastimagestate == 0)
			{
				player.characterTexture.loadFromFile("graphics/Biker_jump/Biker_jump3Left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 1) {
				player.characterTexture.loadFromFile("graphics/Biker_jump/Biker_jump4Left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 2) {
				player.characterTexture.loadFromFile("graphics/Biker_jump/Biker_jump3Left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 3) {
				player.characterTexture.loadFromFile("graphics/Biker_jump/Biker_jump4Left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
		}
	}
	if (player.beenhit == false && player.isfiring == true)
	{
		
		if (player.right == true)
		{
			if (fastimagestate == 0)
			{
				player.characterTexture.loadFromFile("graphics/Biker_shoot/Biker_shoot1.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 1) {
				player.characterTexture.loadFromFile("graphics/Biker_shoot/Biker_shoot2.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 2) {
				player.characterTexture.loadFromFile("graphics/Biker_shoot/Biker_shoot2.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 3) {
				player.characterTexture.loadFromFile("graphics/Biker_shoot/Biker_shoot1.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}

		}
		if (player.left == true)
		{
			if (fastimagestate == 0)
			{
				player.characterTexture.loadFromFile("graphics/Biker_shoot/Biker_shoot2Left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 1) {
				player.characterTexture.loadFromFile("graphics/Biker_shoot/Biker_shoot1Left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 2) {
				player.characterTexture.loadFromFile("graphics/Biker_shoot/Biker_shoot2Left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 3) {
				player.characterTexture.loadFromFile("graphics/Biker_shoot/Biker_shoot1Left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
		}
	}
	if (player.beenhit == true)
	{
		if (player.right == true)
		{
			if (fastimagestate == 0)
			{
				player.characterTexture.loadFromFile("graphics/Biker_hurt/Biker_hurt1.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 1) {
				player.characterTexture.loadFromFile("graphics/Biker_hurt/Biker_hurt2.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 2) {
				player.characterTexture.loadFromFile("graphics/Biker_hurt/Biker_hurt1.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 3) {
				player.characterTexture.loadFromFile("graphics/Biker_hurt/Biker_hurt2.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}

		}
		if (player.left == true)
		{
			if (fastimagestate == 0)
			{
				player.characterTexture.loadFromFile("graphics/Biker_hurt/Biker_hurt1Left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 1) {
				player.characterTexture.loadFromFile("graphics/Biker_hurt/Biker_hurt2Left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 2) {
				player.characterTexture.loadFromFile("graphics/Biker_hurt/Biker_hurt1Left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
			if (fastimagestate == 3) {
				player.characterTexture.loadFromFile("graphics/Biker_hurt/Biker_hurt2Left.png");
				player.characterSprite.setTexture(player.characterTexture, true);
			}
		}
	}

		

		
	
}
