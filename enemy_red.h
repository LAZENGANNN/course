#pragma once
#include "settings.h"
#include "gameObj.h"

class EnemyRed : public GameObj {
private:
	float speedx, speedy;

public:

	EnemyRed() {
		texture.loadFromFile("images\\orange_ship_down1.png");
		sprite.setTexture(texture);
		spawn();
	}

	void spawn() {
		float y = -(rand() % (int)(WINDOW_HEIGHT - bounds.height) + bounds.height);
		float x = (rand() % (int)(WINDOW_WIDTH));
		speedy = rand() % 6 + 3;
		sprite.setPosition(x, 0);
	} 


	void update() {
		sprite.move(0, speedy);
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