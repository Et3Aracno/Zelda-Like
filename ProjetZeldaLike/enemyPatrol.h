#pragma once
#include "enemy.h"
#include "player.h"

class Patroler : public Enemy
{
public:
	RectangleShape sprite;
	Patroler(int h, int d,float s, Vector2f p ) : Enemy(h, d, s, p)
	{
		sprite.setPosition(p);
		sprite.setSize({ 40,40 });
	}

	void movementHOR(int x, int y);
	void movementVER(int x, int y);

	void draw(RenderWindow& game, View& view);
	void update(float deltaTime, Player& p);
	void attack(float deltaTime, Player& player_);
	void takeHit(int damage);

};