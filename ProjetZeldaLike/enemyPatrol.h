#pragma once
#include "enemy.h"

class Patroler : public enemy
{
public:
	RectangleShape sprite;
	Patroler(int health, int damage, Vector2f pos ) : enemy( health, damage, pos)
	{
		sprite.setPosition(pos);
		sprite.setSize({ 40,40 });
	}

	void movement(int x, int y);

	void draw(RenderWindow& game) override;
	void update(float deltaTime) override;
	void attack(Player& player_) override;
	void takeHit() override;
};