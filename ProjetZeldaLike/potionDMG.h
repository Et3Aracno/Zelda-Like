#pragma once

#include "item.h"

class PotionDMG : public Item
{
public:
	RectangleShape potDMG;
	PotionDMG(Vector2f pos) : Item(pos) {
		potDMG.setPosition(pos);
		potDMG.setSize({ 10,10 });
		potDMG.setFillColor(Color::Red);
	}

	void draw(RenderWindow& game) override;
	void itmget() override;
	void itemEffect(Player& player_) override;
};
