#include "enemyChaser.h"

void Chaser::update(float deltaTime)
{
}

void Chaser::attack(Player& player_)
{
    // si dans le cercle
    player_.setHealth(player_.getHealth() - damage);
    player_.getSprite().setColor(Color::Red);

    //enlever la couleur rouge apres 0.3 seconde
}

void Chaser::takeHit(int damage)
{
	health += -damage;
	sprite.setFillColor(Color::Red);
}

void Chaser::movement(Player& p)
{
    Vector2f pPos = p.getPos();
    float angle1 = atan2(pos.y, pos.x);
    float angle2 = atan2(pPos.y, pPos.x);

    float angleDiff = fabs(angle1 - angle2);

    float cosValue = cos(angleDiff);
    float sinValue = sin(angleDiff);

    setPos(Vector2f(pos.x + (sinValue * speed), pos.y + (cosValue * speed)));
}
