#pragma once
#include "settings.h"
#include "player.h"
#include "enemyRed.h"
#include "enemyGreen.h"
#include <vector>
#include "textObj.h"
#include "bomb.h"

class Game {
private:
	sf::RenderWindow window;
	Player player;
	std::vector<EnemyRed*> enemySpritesR;
	std::vector<EnemyGreen*> enemySpritesG;
	std::list<Bomb*> bombSprites;
	int score = 0;
	int HP = 100;
	TextObj scoreText;
	TextObj HPText;


	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();
	}
	

	void checkcollisions() {
			sf::FloatRect playerHitBox = player.getHitBox();
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					for (auto& enemyR : enemySpritesR) {
						sf::FloatRect enemyHitBox = enemyR->getHitBox();
						if (playerHitBox.intersects(enemyHitBox)) {
							enemyR->spawn();
							score += 10;
						}
					}
					for (auto& enemyG : enemySpritesG) {
						sf::FloatRect enemyHitBox = enemyG->getHitBox();
						if (playerHitBox.intersects(enemyHitBox)) {
							enemyG->spawn();
							score += 10;
							/*int bombRange = rand() % (int)WINDOW_WIDTH / 2 + WINDOW_WIDTH / 2;*/
						}
					}
					for (auto& b : bombSprites) {
						b->setDel();
					}
			}
				for (auto& b : bombSprites) {
					if (b->getPosition().y >= WINDOW_HEIGHT) {			
						HP -= 10;
					}

				}
				bombSprites.remove_if([](Bomb* bonus) {return bonus->offScreen(); });
				bombSprites.remove_if([](Bomb* bonus) {return bonus->isToDel(); });
	}
	void spawnBomb() {
		for (auto& e : enemySpritesG) {
			if (e->getPosition().x == WINDOW_WIDTH / 2) {
				Bomb* bomb = new Bomb(e->getPosition());
				bombSprites.push_back(bomb);
				e->changeSide();

			}
		}
	}


	void update() {
		spawnBomb();
		scoreText.update(std::to_string(score));
		HPText.update(std::to_string(HP));
		player.update();
		for (auto& e : enemySpritesR) {
			e->update();
			if (e->getPosition().y > DOWN_DEAD_ZONE) {
				HP -= 10;
				e->spawn();
			}
		}
		for (auto& e : enemySpritesG) {
			e->update(); 
			if (e->getPosition().x > RIGHT_DEAD_ZONE) {
				HP -= 10;
				e->spawn();
			}
		}
		for (auto& b : bombSprites) {
			b->update();
		}
		
	}


	void draw() {
		window.clear();
		for (auto e : enemySpritesR) {
			e->draw(window);
		}
		for (auto e : enemySpritesG) {
			e->draw(window);
		}
		for (auto b : bombSprites) {
			b->draw(window);
		}
		player.draw(window);
		window.draw(scoreText.getText());
		window.draw(HPText.getText());
		window.display();
	}

public:
	Game() :
		window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE),
		scoreText(std::to_string(score), (sf::Vector2f{ WINDOW_WIDTH / 2,0.f })),
		HPText(std::to_string(HP), (sf::Vector2f{0.f,0.f }))
	{
		window.setFramerateLimit(FPS);
		enemySpritesR.reserve(ENEMY_QTY_RED);
		enemySpritesR.reserve(ENEMY_QTY_GREEN);
		for (int i = 0; i < ENEMY_QTY_RED; i++) {
			enemySpritesR.push_back(new EnemyRed);
		}
		for (int i = 0; i < ENEMY_QTY_GREEN; i++) {
			enemySpritesG.push_back(new EnemyGreen);
		}
	}

	void play() {
		while (window.isOpen())
		{
			checkEvents();
			update();
			checkcollisions();
			draw();
		}
	}
};