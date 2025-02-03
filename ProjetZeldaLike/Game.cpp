#include "Game.h"
#include <SFML/System/Clock.hpp>

#include "enemyPatrol.h"
#include "enemyChaser.h"
#include "potionDMG.h"

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

	Player player(100, 1, 0.35f, Vector2f(0, 0));
	vector<Player> p; // A SUPPRIMER (theo)
	Patroler patr(5, 5, { 50.0f,50.0f });
	PotionDMG pot({ 90,90 });

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
		float chaseTime = clock.restart().asSeconds();

		window.clear();

		mapp.updatemap();
		player.update(deltaTime, p);
		player.draw(mapp.window, view);
		patr.moveHor3s();
		patr.takeHit(player);
		patr.draw(mapp.window, view);

		pot.draw(mapp.window);
		pot.itemEffect(player);


		window.setView(view);
		window.display();
	}
}
