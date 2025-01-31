#pragma once

#include "enemy.h"

class Chaser : public enemy
{
public:
	RectangleShape chaser;
	Chaser(int health, int damage, Vector2f pos) : enemy( health, damage, pos) 
	{
		chaser.setPosition(pos);
		chaser.setSize({ 40,40 });
	}
	void update(float deltaTime) override;
	void attack(Player& player_) override;
	void takeHit(Player& player_) override;
	void draw(RenderWindow& window, View& view) override;

	void movement();
};
