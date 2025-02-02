#pragma once
#include <iostream>
#include <vector>
#include "Entity.h"
#include "Entity.h"
#include <math.h>

class Enemy;

class Player : public Entity
{
private:
	void move(float deltaTime);
	void attack(float deltaTime, vector<Enemy*> ennemy);
	void usePowerUp();
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

	float attackDuration = 100.0f;
	float timeSinceLastAttack = 0;
	bool canMove = true;

	//TODO : Attack Cooldown

public:
	Player(int health, int dmg, float s, Vector2f p);
	void update(float deltaTime, vector<Enemy*> p);

	void draw(RenderWindow& window, View& view);

	Sprite& getSprite();
};