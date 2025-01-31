#include "potionDMG.h"


bool activePotDMG = true;

void PotionDMG::draw(RenderWindow& game)
{
	if (activePotDMG)
	{
		game.draw(potDMG);
	}
}

void PotionDMG::itmget()
{
	activePotDMG = false;
}

void PotionDMG::itemEffect(Player& player_)
{
}
