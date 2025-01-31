#pragma once

#include "item.h"

class Potion : public Item
{
public:
	RectangleShape potions;
	Potion(Vector2f pos) : Item(pos) {
		potions.setPosition(pos);
		potions.setSize({ 10,10 });
		potions.setFillColor(Color::Blue);
	}

	void draw(RenderWindow& game) override;
	void itmget() override;
	void itemEffect(Player& player_) override;
};
