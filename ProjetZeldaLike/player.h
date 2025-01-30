#pragma once
#include <iostream>
#include "Entity.h"

class Player : public Entity
{
	void update();
	void move();
	void attack();
	void usePowerUp();

	void draw();
};