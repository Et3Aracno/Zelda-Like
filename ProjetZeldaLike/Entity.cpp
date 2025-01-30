#include "Entity.h"

using namespace sf;

Entity::Entity(int pv, int dmg, Vector2f p)
{
	health = pv;
	damage = dmg;
	Vector2f pos = p;
}
