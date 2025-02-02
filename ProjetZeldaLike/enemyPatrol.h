#pragma once
#include "enemy.h"
#include "player.h"

#include <chrono>
#include <iostream>

class Patroler : public enemy
{
private:
	bool moveleft;
	bool moveup;
	chrono::steady_clock::time_point lastMove;
public:

	Clock clockHit;	
	bool getHit;
	bool colorChangeE;

	RectangleShape sprite;
	Patroler(int health, int damage, Vector2f pos ) : enemy( health, damage, pos), moveleft(true), moveup(true), getHit(false)
	{
		sprite.setPosition(pos);
		sprite.setSize({ 40,40 });
		lastMove = chrono::steady_clock::now();
	}

	void moveHor3s();
	void moveG();
	void moveD();

	void moveVer3s();
	void moveUP();
	void moveDown();


	void draw(RenderWindow& game, View& view) override;
	void update(float deltaTime) override;
	void attack(Player& player_) override;

	void hitColor();
	void takeHit(Player& player_) override;

};