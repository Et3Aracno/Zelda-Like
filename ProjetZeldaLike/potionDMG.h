#pragma once

#include "item.h"

class PotionDMG : public Item
{
public:
	Sprite potDMG;
	Texture potDMGtext;
	PotionDMG(Vector2f pos) : Item(pos) {
		if (!potDMGtext.loadFromFile("asset/potDMG.png")) {
			cout << "Erreur de chargement de la texture!" << endl;
		}
		potDMG.setPosition(pos);
		potDMG.setTexture(potDMGtext);
		potDMG.setPosition(pos);
	}

	void draw(RenderWindow& game) override;
	void itmget() override;
	void itemEffect(Player& player_) override;
};
