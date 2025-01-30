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
Player player(100, 5, 1, Vector2f(0, 0));

int main()
{
    //TEMP
    deltaTime = 1;
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

        window.clear();
        vector<Player> p;
        player.update(deltaTime, p, window);
        circle.setPosition(player.getPos());
        circle.setOrigin(Vector2f(5, 5));
        player.setPos(Vector2f(300, 300));
        window.draw(circle);
        window.display();
        cout << "Orientation (Degres) : " << player.getOrientation() << " - Sinus : " << sin(player.getOrientation() * (M_PI / 180))  << " - Cosinus : " <<  cos(player.getOrientation() * (M_PI / 180)) << endl << endl;
        //cout << player.getPos().x << ", " << player.getPos().y << endl;

    }

    //FIN TEMP
    cout << "Hello World !";
    while (running)
    {
        
    }
}


