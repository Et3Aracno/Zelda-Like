#include "enemyPatrol.h"

float X = 0.1f;
float Y = 0.1f;

void Patroler::draw(RenderWindow& game, View& view)
{
	game.draw(sprite);
}

void Patroler::update(float deltaTime)
{
}

void Patroler::movementHOR(int x, int y)
{
	sprite.move(X, 0);
	if (sprite.getPosition().x > 600)
	{
		X = -0.1f;
	}

	if (sprite.getPosition().x < 300)
	{
		X = 0.1f;
	}
}

void Patroler::movementVER(int x, int y)
{
	sprite.move(0, Y);

	if (sprite.getPosition().y < 300)
	{
		Y = 0.1f;
	}

	if (sprite.getPosition().y > 600)
	{
		Y = -0.1f;
	}
}

void Patroler::attack(Player& player_)
{

}

void Patroler::takeHit(Player& player_)
{
	sprite.setFillColor(Color::Red);
}
