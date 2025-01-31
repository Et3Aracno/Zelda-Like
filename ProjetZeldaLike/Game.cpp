#include "Game.h"
#include <SFML/System/Clock.hpp>

Game::Game()
{
	view.setSize(Vector2f(1920, 1080));
	view.zoom(0.5f);
	window.setView(view);
	cout << "oui";
}

void Game::run()
{
	RenderWindow window = RenderWindow(VideoMode(1920, 1080), "zelda");
	window.setFramerateLimit(60);

	Player player(100, 5, 0.35f, Vector2f(0, 0));
	vector<Player> p; // A SUPPRIMER (theo)

	Map mapp(window);
	mapp.initM("Assets/hub.txt");
	mapp.DrawM(player);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		deltaTime = clock.restart().asMilliseconds();

		window.clear();

		mapp.updatemap(view,player);
		player.update(deltaTime, p);
		player.draw(mapp.window, view);

		window.setView(view);
		window.display();
	}
}
