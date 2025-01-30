#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#define _USE_MATH_DEFINES
#include <math.h>

#include "Player.h"


using namespace std;
using namespace sf;

bool running = true;
float deltaTime = 0;
Player player(100, 5, 0.35f, Vector2f(0, 0));

int main()
{
    //TEMP
    player.setPos(Vector2f(200, 200));
    Clock clock;
    sf::RenderWindow window(sf::VideoMode(800, 800), "Test");
    window.setFramerateLimit(60);

    CircleShape circle(10);
    circle.setFillColor(Color::Yellow);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asMilliseconds();

        window.clear();
        vector<Player> p;
        player.update(deltaTime, p, window);
        player.draw(window);
        
        window.display();
        //cout << player.getPos().x << ", " << player.getPos().y << endl;
        // FPS : cout << 1000/deltaTime << endl;
    }

    //FIN TEMP
    cout << "Hello World !";

}


