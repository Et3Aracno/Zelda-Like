#pragma once

#include "enemy.h"

class Chaser : public enemy
{
public:

	Chaser(int health, int damage, Vector2f pos) : enemy( health, damage, pos) {}
	void update(float deltaTime) override;
	void attack(Player& player_) override;
	void takeHit(int damage) override;

	void movement(Player& p);

};
