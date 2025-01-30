#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Entity
{
protected:
	int health;
	int damage;
	Vector2f pos;
	RectangleShape sprite;

public:
	Entity(int health, int dmg, Vector2f p);

	virtual void draw(RenderWindow& game) = 0;
	//sf::Sprite getSprite() 
	//{ 
	//	return sprite; 
	//}
};