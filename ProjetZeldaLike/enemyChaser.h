#pragma once

#include "enemy.h"
#include "player.h"

class Chaser : public enemy
{
public:
	float speed;
	RectangleShape chaser;
	Chaser(int health, int damage, Vector2f pos) : enemy( health, damage, pos) 
	{
		chaser.setPosition(pos);
		chaser.setSize({ 40,40 });
		speed = 0.1f;
	}
	void update(float deltaTime) override;
	void attack(Player& player_) override;
	void takeHit(Player& player_) override;
	void draw(RenderWindow& window, View& view) override;

	void movement(Player& player_, float deltaTime);
};
