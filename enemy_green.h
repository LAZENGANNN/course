#pragma once
#include "settings.h"
#include "gameObj.h"

class EnemyGreen : public GameObj {
private:
	float speedx;

public:


	EnemyGreen() {
		texture.loadFromFile("images\\green_ship_right.png");
		sprite.setTexture(texture);
		spawn();
	}


	void spawn() {
		speedx = rand() % 6 + 3;
		float y = (rand() % (int)(WINDOW_HEIGHT));
		sprite.setPosition(0, y - ENEMY_WIDTH);
	} 


	void update() {
		sprite.move(speedx, 0);
		sf::FloatRect bounds = sprite.getGlobalBounds();
		if (bounds.left < -bounds.width || bounds.left > WINDOW_WIDTH ||
			bounds.top > WINDOW_HEIGHT)
		{
			spawn();
		}
	}

	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}


};