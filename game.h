#pragma once
#include "settings.h"
#include "player.h"
#include "enemies.h"
#include <vector>
class Game {
private:
	sf::RenderWindow window;
	Player player;
	std::vector<Enemy*> enemySprites;
	/*Enemy enemy_test;*/

	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();
	}

	void update() {
		for (auto& e : enemySprites) {
			e->update();
		}
		player.update();
	}

	void draw() {
		window.clear();
		for (auto e : enemySprites) {
			e->draw(window);
		}
		player.draw(window);
		window.display();
	}

public:
	Game() :
		window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE)
	{
		window.setFramerateLimit(FPS);
		enemySprites.reserve(ENEMY_QTY);
		for (int i = 0; i < ENEMY_QTY; i++) {
			enemySprites.push_back(new Enemy());
		}
    }

	void play() {
		while (window.isOpen()/* && player.isAlive()*/)
		{
			checkEvents();
			update();
			/*checkCollisions();*/
			draw();
		}
	}
};