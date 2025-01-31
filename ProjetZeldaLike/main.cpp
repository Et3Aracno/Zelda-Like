#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#include "enemyPatrol.h"
#include "potion.h"
#include "potionDMG.h"


using namespace std;
using namespace sf;


int main()
{
    Patroler test(5, 5, { 400,300 });
    Potion pot({ 10,10 });
    PotionDMG potDMg({ 50,50 });
 
    sf::RenderWindow window(sf::VideoMode(1700, 1000), "Fenêtre SFML");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); 
        }
        window.clear();
        test.draw(window);
        test.movementVER(1,1);
        pot.draw(window);
        potDMg.draw(window);

        window.display();
    }

    return 0;

}


