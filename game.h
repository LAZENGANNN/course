#pragma once
#include "settings.h"
#include "player.h"
#include "enemy.h"
#include <vector>
#include "textObj.h"

class Game {
private:
	sf::RenderWindow window;
	Player player;
	std::vector<Enemy*> enemySprites;
	int score = 0;
	TextObj scoreText;


	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();
	}
	void checkcollisions() {
		sf::FloatRect playerHitBox = player.getHitBox();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			for (auto& enemy : enemySprites) {
				sf::FloatRect enemyHitBox = enemy->getHitBox();
				if (playerHitBox.intersects(enemyHitBox)) {
					enemy->spawn();
					score += 10;
				}
			}
		}
	}

	void update() {
		for (auto& e : enemySprites) {
			e->update();
		}
		player.update();
		scoreText.update(std::to_string(score));
	}

	void draw() {
		window.clear();
		for (auto e : enemySprites) {
			e->draw(window);
		}
		player.draw(window);
		window.draw(scoreText.getText());
		window.display();
	}

public:
	Game() :
		window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE), 
		scoreText(std::to_string(score),(sf::Vector2f{ WINDOW_WIDTH / 2,0.f }))
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
			checkcollisions();
			/*checkCollisions();*/
			draw();
		}
	}
};