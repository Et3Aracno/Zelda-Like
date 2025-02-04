#include "Game.h"
#include <SFML/System/Clock.hpp>

#include "enemyPatrol.h"
#include "enemyChaser.h"
#include "Boss.h"
#include "potionDMG.h"


Game::Game()
{
	view.setSize(Vector2f(1920, 1080));
	view.zoom(0.5f);
	window.setView(view);
}

void Game::run()
{
	RenderWindow window = RenderWindow(VideoMode(1920, 1080), "zelda");
	window.setFramerateLimit(60);

	//PotionDMG pot({ 90,90 });
	Player player(100, 50, 0.35f, Vector2f(1548, 883));
	EnemyManager enemyManager;
	Boss boss(1000, 10, 0.1f, Vector2f(300, 300));

	Map mapp(window);
	mapp.initall();
	mapp.initM(currentMap);
	mapp.DrawM(player, view, currentMap);


	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		deltaTime = clock.restart().asMilliseconds();

		window.clear();

		player.update(deltaTime, enemyManager.getEnemyList());
		enemyManager.update(deltaTime, player);
		boss.update(deltaTime, player);

		mapp.eDonj(player,view,currentMap);
		mapp.DrawM(player, view,currentMap);

		player.draw(window, view);
		enemyManager.draw(window, view);
		boss.draw(window, view);
		
		window.setView(view);
		window.display();
	}
}
