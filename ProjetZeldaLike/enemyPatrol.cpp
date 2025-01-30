#include "enemyPatrol.h"

float X = 0.1f;
float Y = 0.0f;
bool hor = true;
bool ver = false;

void Patroler::draw(RenderWindow& game)
{
	game.draw(sprite);
}

void Patroler::update(float deltaTime)
{
}

void Patroler::movement(int x, int y)
{
	sprite.move(X, Y);
	if (sprite.getPosition().x > 600 && hor == true)
	{
		X = -0.1f;
	}

	if (sprite.getPosition().x < 300 && hor == true)
	{
		X = 0.1f;
		ver = true;
	}

	if (sprite.getPosition().x == 400 && ver == true)
	{
		X = 0.0f;
		Y = 0.1f;
	}

	if (sprite.getPosition().y > 500 && ver == true)
	{
		Y = -0.1f;
		ver = false;
		hor = false;
	}

	if (sprite.getPosition().y < 300)
	{
		Y = 0.1f;
		hor = true;
	}






}

void Patroler::attack(Player& player_)
{

}

void Patroler::takeHit()
{
}
