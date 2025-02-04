#pragma once
#include "player.h"

#include "bossBullet.h"

class Boss : Entity
{
public:
	vector<BossBullet> bossBulletList;

	int bulletByAttack = 3;
	int bulletAlreadyShotInTheAttack = 0;

	float timeSinceLastBulletShot = 0;
	float timeBetweenBulletShots = 1000.f;
	float timeSinceLastAttack = 0;
	float timeBetweenAttacks = 5000.f;

	int bulletDamage = 10;
	float bulletSpeed = 0.4f;

	bool canMove = true;
	Vector2f targetPosition;

	Vector2i bossRoomSize = Vector2i(500, 500);

	Boss(int h, int d, float s, Vector2f p);

	void update(float deltaTime, Player& p);
	void attack1(float deltaTime, Player& p);
	void move(float deltaTime);

	void bulletUpdate(float deltaTime, Player& p);

	void draw(RenderWindow& window, View& view) override;
};