#pragma once
#include <iostream>
#include <vector>
#include <math.h>

#include "Entity.h"


class Player : public Entity
{
private:
	void move(float deltaTime);
	void attack(vector<Player> ennemy); //changer player to enemy

	void animationUpdate(float deltaTime);

	Texture textureWalk;
	Texture textureIdle;
	Texture textureAttack;
	Sprite sprite;

	int frameHeight = 16;
	int frameWidth = 16;
	int frameCount = 4;
	int currentFrame = 0;
	float frameDuration = 100.0f;
	float timer = 0;



	string animState = "Idle";
	string animStateBackup = "Idle";
	bool isMoving = false;

public:
	bool attackstate = false;

	Player(int health, int dmg, float s, Vector2f p);
	void update(float deltaTime, vector<Player> p);
	void draw(RenderWindow& window, View& view);

	bool buff = true;
	void usePowerUp();

	Sprite getSprite();

};