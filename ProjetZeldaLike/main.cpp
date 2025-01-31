#define _USE_MATH_DEFINES
#include "Map.h"

using namespace std;
using namespace sf;

bool running = true;
float deltaTime = 0;
Player player(100, 5, 0.35f, Vector2f(0, 0));

int main()
{
    RenderWindow window(VideoMode(1920, 1080), "zelda");
    //TEMP
    Map mapp(window);
    player.setPos(Vector2f(200, 200));
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
        player.update(deltaTime, p);
        player.draw(mapp.window);
        
        window.display();
        //cout << player.getPos().x << ", " << player.getPos().y << endl;
        // FPS : cout << 1000/deltaTime << endl;
    }

    //FIN TEMP

}
