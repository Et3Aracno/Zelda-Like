#include "potion.h"

bool activePot = true;

void Potion::update(float deltaTime, Player& player_)
{
	itmget();
	itemEffect(player_);
}

void Potion::draw(RenderWindow& game)
{
	if (activePot)
	{
		game.draw(potions);
	}
}

void Potion::itmget()
{
	activePot = false;
}

void Potion::itemEffect(Player& player_)
{
	player_.setHealth(player_.getHealth() + 10);
}



