#pragma once

#include "item.h"

class Potion : public Item
{
public:
	Sprite potions;
	Texture potTex;
	Potion(Vector2f pos) : Item(pos) {
		if (!potTex.loadFromFile("asset/vie.png")) {
			cout << "Erreur de chargement de la texture!" << endl;
		}
		potions.setPosition(pos);
		potions.setTexture(potTex);
		potions.setPosition(pos);
	}

	void draw(RenderWindow& game) override;
	void itmget() override;
	void itemEffect(Player& player_) override;
};
