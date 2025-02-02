#pragma once
#include "player.h"
#include "enemy.h"

class Chaser : public Enemy
{
public:

	Chaser(int health, int damage, float speed, Vector2f pos);
	void update(float deltaTime, Player& p) override;
	void attack(float deltaTime, Player& player_) override;
	void takeHit(int damage) override;

	void movement(float deltaTime, Player& p);
	void animationUpdate(float deltaTime);
	void draw(RenderWindow& game, View& view);

};
