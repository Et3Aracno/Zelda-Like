#pragma once

#include "Entity.h";

class Player;

class Enemy : public Entity
{
public:
	Texture textureWalk;
	Texture textureAttack;
	Sprite sprite;

	int frameHeight = 16;
	int frameWidth = 16;
	int frameCount = 4;
	int currentFrame = 0;
	float frameDuration = 100.0f;
	float timer = 0;

	string animState = "Walk";
	string animStateBackup = "";

	float attackDuration = 1000.0f;
	float timeSinceLastAttack = 0;
	bool canMove = true;

	Enemy(int health, int damage, float speed, Vector2f pos) : Entity(health, damage, speed, pos) {}

	virtual void draw(RenderWindow& game, View& view) = 0;
	virtual void update(float deltaTime, Player& p) = 0;
	virtual void attack(float deltaTime, Player& player_) = 0;
	virtual void takeHit(int damage) = 0;
};