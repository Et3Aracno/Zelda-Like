#pragma once
#include "player.h"

class Boss : Entity
{
	void update(float deltaTime, Player& p);
	void attack1(float deltaTime, Player& p);
};