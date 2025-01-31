#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"

using namespace std;
using namespace sf;

class Game
{
private:
	int windowWidth = 1920;
	int windowHeight = 1080;
public:
	RenderWindow window;
	View view;

	Clock clock;
	float deltaTime;
	Game();


	void run();
};