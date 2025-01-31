#include "potion.h"

bool activePot = true;

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
}



