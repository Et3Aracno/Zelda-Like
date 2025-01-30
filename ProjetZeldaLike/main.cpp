#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#include "enemyPatrol.h"


using namespace std;
using namespace sf;


int main()
{
    Patroler test(5, 5, { 400,300 });
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fenêtre SFML");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); 
        }
        window.clear();
        test.draw(window);
        test.movement(1,1);

        window.display();
    }

    return 0;

}


