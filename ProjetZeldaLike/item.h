#pragma once

#include "Entity.h"
#include "player.h"

class Item : public Entity
{
public:
	Item(Vector2f pos) : Entity(health,damage,pos) {}

	virtual void draw(RenderWindow& game) = 0;
	virtual void itmget() = 0;
	virtual void itemEffect(Player& player_) = 0;
};
