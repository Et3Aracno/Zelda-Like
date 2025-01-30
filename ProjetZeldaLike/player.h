#pragma once
#include <iostream>
#include <vector>
#include "Entity.h"

class Player : public Entity
{
private:
	void move(float deltaTime);
	void attack(vector<Player> ennemy, RenderWindow& window); //changer player to enemy
	void usePowerUp();

public:
	Player(int health, int dmg, float s, Vector2f p);
	void update(float deltaTime, vector<Player> p, RenderWindow& window);

	void draw(RenderWindow& window);
};