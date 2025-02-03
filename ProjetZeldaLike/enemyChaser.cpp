#include "enemyChaser.h"

Chaser::Chaser(int health, int damage, float speed, Vector2f pos) : Enemy(health, damage, speed, pos) 
{
    if (!textureWalk.loadFromFile("Assets/Flam/SeparateAnim/Walk.png")) {
        throw std::runtime_error("Erreur de chargement de la texture");
    }
    if (!textureAttack.loadFromFile("Assets/Flam/SeparateAnim/Attack.png")) {
        throw std::runtime_error("Erreur de chargement de la texture");
    }

    sprite.setTexture(textureWalk);
    sprite.setScale(Vector2f(4, 4));
}

void Chaser::update(float deltaTime, Player& p)
{
    movement(deltaTime, p);
    attack(deltaTime, p);
    animationUpdate(deltaTime);
    stuntManager(deltaTime);
}

void Chaser::attack(float deltaTime, Player& p)
{
    timeSinceLastAttack += deltaTime;

    Vector2f pPos = p.getPos();
    if (timeSinceLastAttack > attackDuration){
        if (stuntTime <= 0) 
        { 
            canMove = true; 
        }

        animState = "Walk";
        p.getSprite().setColor(Color::White);
        if (abs(pPos.x - pos.x) + abs(pPos.y - pos.y) < 50)
        {
            cout << "ATTACK" << endl;
            p.setHealth(p.getHealth() - damage);
            p.getSprite().setColor(Color::Red);
            animState = "Attack";
            timeSinceLastAttack = 0;
            canMove = false;
        }
    }
}

void Chaser::movement(float deltaTime, Player& p)
{
    Vector2f pPos = p.getPos();

    float angle = atan2(pPos.y - pos.y, pPos.x - pos.x);

    float dx = cos(angle) * speed * deltaTime;
    float dy = sin(angle) * speed * deltaTime;

    if (abs(dx) < abs(dy)) {
        if (dy > 0) { orientation = 180; }
        else { orientation = 0; }
    }
    else {
        if (dx > 0) { orientation = 270; }
        else { orientation = 90; }

    }
    if (canMove)
    {
        setPos(Vector2f(pos.x + dx, pos.y + dy));
    }

    if (stuntTime > 0)
    {
        setPos(Vector2f(pos.x - dx*3, pos.y - dy*3));
    }
}

void Chaser::animationUpdate(float deltaTime)
{
    if (animState == "Walk")
    {
        frameCount = 4;
        sprite.setTexture(textureWalk);
    }
    else if (animState == "Attack")
    {
        frameCount = 1;
        sprite.setTexture(textureAttack);
    }


    if (animState != animStateBackup)
    {
        animStateBackup = animState;
        sprite.setTextureRect(IntRect(((getOrientation() + 90) / 90 % 4) * frameHeight, 0, frameWidth, frameHeight));
    }

    timer += deltaTime;
    if (timer > frameDuration && stuntTime <= 0)
    {
        timer = 0;
        currentFrame = (currentFrame + 1) % frameCount;
        sprite.setTextureRect(IntRect(((getOrientation() + 90) / 90 % 4) * frameHeight, currentFrame * frameWidth, frameWidth, frameHeight));
    }
}

void Chaser::draw(RenderWindow& window, View& view)
{
    sprite.setPosition(pos);
    window.draw(sprite);
}

void Chaser::giveStunt(float time)
{
    canMove = false;
    stuntTime += time;
    sprite.setColor(Color::Red);
}

void Chaser::stuntManager(float deltaTime)
{
    if (stuntTime > 0)
    {
        stuntTime += -deltaTime;
    }
    else 
    {
        stuntTime = 0;
        canMove = true;
        sprite.setColor(Color::White);
    }
}

void Chaser::takeHit(int damage)
{
    health += -damage;
}