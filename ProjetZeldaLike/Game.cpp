#include "Game.h"
#include <SFML/System/Clock.hpp>

#include "enemyPatrol.h"

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
	Patroler patr(2, 2, { 50.0f,50.0f });


	Map mapp(window);
	mapp.initM("Assets/hub.txt");
	mapp.DrawM();

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		deltaTime = clock.restart().asMilliseconds();

		window.clear();

		mapp.updatemap();
		player.update(deltaTime, p);
		player.draw(mapp.window, view);
		patr.moveHor3s();
		patr.takeHit(player);
		patr.draw(mapp.window, view);


		window.setView(view);
		window.display();
	}
}
