#include "enemyChaser.h"


void Chaser::draw(RenderWindow& window, View& view)
{
	window.draw(chaser);
}

void Chaser::update(float deltaTime)
{
}

void Chaser::attack(Player& player_)
{
}

void Chaser::takeHit(Player& player_)
{
}



void Chaser::movement(Player& player_,float deltaTime)
{
    Vector2f playerPosition = player_.getPos();
    Vector2f enemyPosition = chaser.getPosition();

    Vector2f diff = playerPosition - enemyPosition;
    if (diff.x != 0.f || diff.y != 0.f) {

        float length = sqrt(diff.x * diff.x + diff.y * diff.y);
        diff /= length;
        chaser.move(diff * speed * deltaTime);

    }
}
