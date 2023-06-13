#pragma once
#include "settings.h"
#include "gameObj.h"

class EnemyGreen : public GameObj {
private:
	float speedx;
	int speedRange1 = GREEN_START_SPEED_1;
	int speedRange2 = GREEN_START_SPEED_2;
	sf::Clock timer;
	int side;


public:


	EnemyGreen() {
		texture.loadFromFile("images\\green_ship_right.png");
		sprite.setTexture(texture);
		spawn();
	}


	/*void spawn() {
		speedx = rand() % speedRange1 + speedRange2;
		float y = (rand() % (int)(WINDOW_HEIGHT));
		sprite.setPosition(0, y - ENEMY_WIDTH);
		sprite.setRotation(360);
	}*/

	void spawn() {
		side = rand() % 2;
		if (side == 0) {
			speedx = rand() % speedRange1 + speedRange2;
			float y = (rand() % (int)(WINDOW_HEIGHT - (WINDOW_HEIGHT / 2)));
			sprite.setPosition(0 , y);
			sprite.setRotation(360);
		}
		if (side == 1) {
			speedx = rand() % speedRange1 + speedRange2;
			float y = (rand() % (int)(WINDOW_HEIGHT - (WINDOW_HEIGHT/2)));
			sprite.setPosition(WINDOW_WIDTH - ENEMY_WIDTH,y);
			sprite.setRotation(180);
			speedx = -speedx;
		}
	}



	void update() {
		sprite.move(speedx, 0);
		int now = timer.getElapsedTime().asSeconds();
		if (now >= SPEED_INCREACE_CD) {
			speedRange1++;
			speedRange2++;
			timer.restart();
		}
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

	void changeSide() { 
		speedx = -speedx;
		sprite.rotate(180);
	}

	int getSide() { return side; }

	void setStartSpeed() {
		speedRange1 = GREEN_START_SPEED_1;
		speedRange2 = GREEN_START_SPEED_2;
	}
};