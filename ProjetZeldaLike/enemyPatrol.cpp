#include "enemyPatrol.h"

bool touch = false;

void Patroler::draw(RenderWindow& game, View& view)
{
	if (health > 0)
	{
		sprite.setPosition(pos);
		game.draw(sprite);
	}
}

void Patroler::update(float deltaTime, Player& p)
{
}

void Patroler::moveHor3s()
{
	auto currentTime = chrono::steady_clock::now();
	chrono::duration<double> elapsed = currentTime - lastMove;

	if (elapsed.count() >= 3.0)
	{
		moveleft = !moveleft;
		lastMove = currentTime;
	}

	if (moveleft)
	{
		moveG();
	}
	else
	{
		moveD();
	}
}

void Patroler::moveG()
{
	pos.x -= 1.0f;
}

void Patroler::moveD()
{
	pos.x += 1.0f;
}

void Patroler::moveVer3s()
{
	auto currentTime = chrono::steady_clock::now();
	chrono::duration<double> elapsed = currentTime - lastMove;

	if (elapsed.count() >= 3.0)
	{
		moveup = !moveup;
		lastMove = currentTime;
	}

	if (moveup)
	{
		moveUP();
	}
	else
	{
		moveDown();
	}
}

void Patroler::moveUP()
{
	pos.y -= 1.0f;
}

void Patroler::moveDown()
{
	pos.y += 1.0f;
}




void Patroler::attack(Player& player_)
{

}

void Patroler::hitColor()
{
	health += -damage;
	sprite.setFillColor(Color::Red);
	clockHit.restart();
	getHit = true;
}

void Patroler::takeHit(Player& player_)
{
	FloatRect patrolerBounds = sprite.getGlobalBounds(); 
	FloatRect playerBounds = player_.getSprite().getGlobalBounds();

	if (patrolerBounds.intersects(playerBounds) && player_.attackstate )
	{
		if (!getHit)
		{
			touch = true;
			hitColor();
			health -= player_.getDamage();
		}
	}
	if (getHit && clockHit.getElapsedTime().asSeconds() >= 3.f)
	{
		getHit = false;
		sprite.setFillColor(Color::Blue);
		touch = false;
	}
}



