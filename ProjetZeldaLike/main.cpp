
#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#include "enemyChaser.h"
#include "enemyPatrol.h"
#include "potion.h"
#include "potionDMG.h"


#define _USE_MATH_DEFINES
#include "Game.h"


using namespace std;

int main()
{
	Game game;

	game.run();
}