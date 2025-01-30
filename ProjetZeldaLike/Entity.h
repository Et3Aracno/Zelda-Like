#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Entity
{
private:
	int health;
	int damage;
	float posX;
	float posY;

public:
	Entity(int health, int dmg, float x, float y);

	virtual void draw(RenderWindow& game) = 0;
};