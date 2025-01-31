#pragma once
#include "enemy.h"
#include "player.h"

class Patroler : public enemy
{
public:
	RectangleShape sprite;
	Patroler(int health, int damage, Vector2f pos ) : enemy( health, damage, pos)
	{
		sprite.setPosition(pos);
		sprite.setSize({ 40,40 });
	}

	void movementHOR(int x, int y);
	void movementVER(int x, int y);

	void draw(RenderWindow& game) override;
	void update(float deltaTime) override;
	void attack(Player& player_) override;
	void takeHit(Player& player_) override;

};