
#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#include "enemyPatrol.h"
#include "potion.h"
#include "potionDMG.h"


#define _USE_MATH_DEFINES
#include "Map.h"


using namespace std;
using namespace sf;


bool running = true;
float deltaTime = 0;


int main()
{
    RenderWindow window(VideoMode(1920, 1080), "zelda");
    View view;
    view.setSize(Vector2f(1920, 1080));
    view.zoom(0.5f);
    window.setView(view);
    //TEMP
    Map mapp(window);
    Clock clock;
    mapp.initM("Assets/hub.txt");
    mapp.DrawM();

    while (window.isOpen()) {
        window.setFramerateLimit(60);
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asMilliseconds();

        window.clear();
        mapp.updatemap();
        vector<Player> p;
        window.setView(view);
        window.display();
        //cout << player.getPos().x << ", " << player.getPos().y << endl;
        // FPS : cout << 1000/deltaTime << endl;
    }

    //FIN TEMP
}
