#include "boss.h"
#include "cstdlib"
#define _USE_MATH_DEFINES
#include <math.h>

Boss::Boss(int h, int d, float s, Vector2f p) : Entity(h, d, s, p)
{
	srand(time(NULL));
}

void Boss::update(float deltaTime, Player& p)
{
	timeSinceLastAttack += deltaTime;
	if (timeSinceLastAttack > timeBetweenAttacks) 
	{
		if (currentAttackID == 0) {
			attack1(deltaTime, p);
		}
		if (currentAttackID == 1) {
			attack2(deltaTime, p);
		}
	}

	//Attaque tête chercheuses
	//Attaque rapide demi cercle
	//Un autre truc
	move(deltaTime);

	bulletUpdate(deltaTime, p);
}

void Boss::attack1(float deltaTime, Player& p)
{
	if (bulletAlreadyShotInTheAttack < bulletByAttack)
	{
		timeSinceLastBulletShot += deltaTime;
		if (timeSinceLastBulletShot > timeBetweenBulletShots)
		{
			timeSinceLastBulletShot = 0;
			bulletAlreadyShotInTheAttack += 1;

			bossBulletList.push_back(BossBullet(1, bulletDamage, bulletSpeed, pos, (rand()%int(M_PI*200))/100));
		}
	}
	else
	{
		bulletAlreadyShotInTheAttack = 0;
		timeSinceLastAttack = 0;
		currentAttackID = 1;
	}
}

void Boss::attack2(float deltaTime, Player& p)
{
	
}

void Boss::move(float deltaTime)
{
	if (canMove)
	{
		if (abs(pos.x - targetPosition.x) < 5 && abs(pos.y - targetPosition.y) < 5)
		{
			targetPosition = Vector2f(rand() % bossRoomSize.x, rand() % bossRoomSize.y);
		}

		float angle = atan2(targetPosition.y - pos.y, targetPosition.x - pos.x);

		//orientation = angle * (M_PI / 180);

		pos = Vector2f(pos.x + (cos(angle) * deltaTime * speed), pos.y + (sin(angle) * deltaTime * speed));
	}
}

void Boss::bulletUpdate(float deltaTime, Player& p)
{
	vector<BossBullet> tempBossBulletList;
	for (auto& b : bossBulletList)
	{
		b.update(deltaTime, p);
		if (!(b.time > 7000))
		{
			tempBossBulletList.push_back(b);
		}
	}
	bossBulletList = tempBossBulletList;
}

void Boss::draw(RenderWindow& window, View& view)
{
	RectangleShape rect(Vector2f(30, 30));
	rect.setPosition(pos);
	window.draw(rect);

	for (auto& b : bossBulletList)
	{
		b.draw(window, view);
	}

	RectangleShape rect2(Vector2f(200, 100));
	rect2.setRotation(orientation);
	rect2.setPosition(pos);
	window.draw(rect2);
}