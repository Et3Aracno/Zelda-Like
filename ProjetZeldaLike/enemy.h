#pragma once

#include "Entity.h"
#include "player.h"

class enemy : public Entity
{
public:
	enemy(int health, int damage, Vector2f pos) : Entity(health, damage, pos) {}

	virtual void draw(RenderWindow& game) = 0;
	virtual void update(float deltaTime) = 0;
	virtual void attack(Player& player_) = 0;
	virtual void takeHit(const Color& color) = 0;
};