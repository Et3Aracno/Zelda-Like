#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include "player.h"


using namespace sf;
using namespace std;

Player::Player(int health, int dmg, float s, Vector2f p) : Entity(health, dmg, s, p) 
{

    if (!textureWalk.loadFromFile("../ProjetZeldaLike/Assets/GladiatorBlue/SeparateAnim/Walk.png")) {
        throw std::runtime_error("Erreur de chargement de la texture");
    }
    if (!textureIdle.loadFromFile("../ProjetZeldaLike/Assets/GladiatorBlue/SeparateAnim/Idle.png")) {
        throw std::runtime_error("Erreur de chargement de la texture");
    }

    sprite.setTexture(textureIdle);
    sprite.setScale(Vector2f(4, 4));
}

void Player::update(float deltaTime, vector<Player> p)
{
    move(deltaTime);
    attack(p);
    animationUpdate(deltaTime);
}

void Player::animationUpdate(float deltaTime) 
{
    timer += deltaTime;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Q) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
    {
        isMoving = true;
    }
    else
    {
        isMoving = false;
    }

    if (isMoving)
    {
        animState = "Walk";
    }
    else
    {
        animState = "Idle";
    }

    if (animState == "Idle")
    {
        frameCount = 1;
        sprite.setTexture(textureIdle);

    }
    else if (animState == "Walk")
    {
        frameCount = 4;
        sprite.setTexture(textureWalk);
    }

    if (animState != animStateBackup)
    {
        animStateBackup = animState;
        sprite.setTextureRect(IntRect(((getOrientation() + 90) / 90 % 4) * frameHeight, 0, frameWidth, frameHeight));
    }

    if (timer > frameDuration)
    {
        timer = 0;
        currentFrame = (currentFrame + 1) % frameCount;
        sprite.setTextureRect(IntRect(((getOrientation() + 90) / 90 % 4) * frameHeight, currentFrame * frameWidth, frameWidth, frameHeight));
    }
}

void Player::move(float deltaTime)
{
    if (Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        setPos(Vector2f(getPos().x, getPos().y - getSpeed()* deltaTime));
        setOrientation(270);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        setPos(Vector2f(getPos().x, getPos().y + getSpeed() * deltaTime));
        setOrientation(90);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        setPos(Vector2f(getPos().x - getSpeed() * deltaTime, getPos().y));
        setOrientation(180);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        setPos(Vector2f(getPos().x + getSpeed() * deltaTime, getPos().y));
        setOrientation(0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        setOrientation(getOrientation() + 1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        setOrientation(getOrientation() - 1);
    }
}


bool isInside(Vector2f edges[4], Vector2f posPoint) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        Vector2f a = edges[i];
        Vector2f b = edges[(i + 1) % 4];

        if ((a.y > posPoint.y) != (b.y > posPoint.y)) {
            float intersectX = a.x + (b.x - a.x) * (posPoint.y - a.y) / (b.y - a.y);

            if (posPoint.x < intersectX) {
                count++;
            }
        }
    }

    return count % 2 == 1;
}




void Player::attack(vector<Player> ennemy)
{
    float attackSize = 30;
    float radO = getOrientation() * (M_PI / 180);
    Vector2f pPos = getPos();
    Vector2f attackHitBox[4] =
    {
        Vector2f(pPos.x + (sin(radO) * attackSize), pPos.y - (cos(radO) * attackSize)),
        Vector2f(pPos.x - (sin(radO) * attackSize), pPos.y + (cos(radO) * attackSize)),
        Vector2f((pPos.x + (cos(radO) * 100)) - (sin(radO) * attackSize), (pPos.y + (sin(radO) * 100)) + (cos(radO) * attackSize)),
        Vector2f((pPos.x + (cos(radO) * 100)) + (sin(radO) * attackSize), (pPos.y + (sin(radO) * 100)) - (cos(radO) * attackSize))
    };

    for (auto e : ennemy)
    {
        if (isInside(attackHitBox, e.getPos()))
        {
            //e.takeDamage(getDamage());
        }
    }
}

void Player::draw(RenderWindow& window)
{
    sprite.setPosition(getPos());
    window.draw(sprite);
}