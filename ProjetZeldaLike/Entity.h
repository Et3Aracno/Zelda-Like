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
	Vector2f pos;

public:
	Entity(int health, int dmg, Vector2f p);

	virtual void draw(RenderWindow& game) = 0;
};