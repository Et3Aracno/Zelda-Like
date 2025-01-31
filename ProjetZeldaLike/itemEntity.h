#pragma once

#include "Entity.h"
#include "player.h"

class ItemEntity
{
public:
	ItemEntity(Vector2f pos) {}

	virtual void draw(RenderWindow& game) = 0;
	virtual void itmget() = 0;
	virtual void itemEffect(Player& player_) = 0;
};
