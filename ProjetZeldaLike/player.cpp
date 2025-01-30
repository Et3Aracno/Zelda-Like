#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include "player.h"

using namespace sf;
using namespace std;

Player::Player(int health, int dmg, float s, Vector2f p) : Entity(health, dmg, s, p) {}

void Player::update(float deltaTime, vector<Player> p, RenderWindow& window)
{
    move(deltaTime);
    attack(p, window);
}

void Player::move(float deltaTime)
{
    if (Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        setPos(Vector2f(getPos().x, getPos().y - getSpeed()*deltaTime));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        setPos(Vector2f(getPos().x, getPos().y + getSpeed() * deltaTime));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        setPos(Vector2f(getPos().x - getSpeed() * deltaTime, getPos().y));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        setPos(Vector2f(getPos().x + getSpeed() * deltaTime, getPos().y));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        setOrientation(getOrientation() + 1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        setOrientation(getOrientation() - 1);
    }
}


bool isInside(Vector2f edges[4], Vector2f posPoint)
{
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        if ((posPoint.y < edges[i].y != posPoint.y < edges[i % 4].y)/* && (posPoint.x < edges[i].x + ((posPoint.y - edges[i].y) / (edges[i % 4].y - edges[i].y)) * (edges[i % 4].x - edges[i].x))*/)
        {
            count += 1;
        }
    }
    return count % 2 == 1;
}


void Player::attack(vector<Player> ennemy, RenderWindow& window)
{
    float attackSize = 30;
    float radO = getOrientation() * (M_PI / 180);
    Vector2f pPos = getPos();
    Vector2f attackHitBox[4] =
    {
        Vector2f(pPos.x + (sin(radO) * attackSize), pPos.y - (cos(radO) * attackSize)),
        Vector2f(pPos.x - (sin(radO) * attackSize), pPos.y + (cos(radO) * attackSize)),
        Vector2f((pPos.x + (cos(radO)*100)) + (sin(radO) * attackSize), (pPos.y + (sin(radO)*100)) - (cos(radO) * attackSize)),
        Vector2f((pPos.x + (cos(radO) * 100)) - (sin(radO) * attackSize), (pPos.y + (sin(radO) * 100)) + (cos(radO) * attackSize))
    };

    for (auto a : attackHitBox)
    {
        CircleShape c(4);
        c.setPosition(a);
        window.draw(c);
    }

    Vector2f tempPos = Vector2f(250, 700);

    CircleShape c2(4);
    c2.setPosition(tempPos);
    if (isInside(attackHitBox, tempPos))
    {
        c2.setFillColor(Color::Green);
    }
    else
    {
        c2.setFillColor(Color::Red);
    }
    window.draw(c2);

    /*for (auto e : ennemy)
    {
        if ()
    }*/
}

void Player::draw(RenderWindow& window)
{
    return;
}