#pragma once
#include "settings.h"
#include "gameObj.h"

class Enemy : public GameObj {
private:
	float speedx, speedy;
	int side;
	bool del = false;

public:
	enum EnemyType { RIGHT_GREEN, RED_DOWN, ENEMIES_TYPE_QTY };
	EnemyType type;

	/*Enemy() {
		side = rand() % 2;
		texture.loadFromFile("images\\green_ship_right.png");
		sprite.setTexture(texture);
		spawn(type);
	}*/
	Enemy(EnemyType type) {
		side = rand() % 2;
		this->type = type;
		switch (type) {
		case RIGHT_GREEN:
			texture.loadFromFile("images\\green_ship_right.png");
			break;

		case RED_DOWN:
			texture.loadFromFile("images\\orange_ship_down1.png");
			break;
		}
		sprite.setTexture(texture);
		spawn(type);
	}

	/*void spawn() {
		speedx = rand() % 20 + 5;
		float y = (rand() % (int)(WINDOW_HEIGHT));
		sprite.setPosition(0, y + ENEMY_WIDTH);
	} */
	void spawn(EnemyType type) {
		this->type = type;
		float y = (rand() % (int)(WINDOW_HEIGHT));
		float x = (rand() % (int)(WINDOW_WIDTH));
		switch (type) {
		case RIGHT_GREEN:
			speedx = rand() % 8 + 4;
			sprite.setPosition(0, y + ENEMY_WIDTH);
			break;
		case RED_DOWN:
			speedy = rand() % 6 + 2;
			sprite.setPosition(x, 0);
			break;
		}
	}

	void update(EnemyType type) {
		this->type = type;
		switch (type) {
		case RIGHT_GREEN:
			sprite.move(speedx, 0);
		case RED_DOWN:
			sprite.move(0, speedy);
		}

		sf::FloatRect bounds = sprite.getGlobalBounds();
		if (bounds.left < -bounds.width || bounds.left > WINDOW_WIDTH ||
			bounds.top > WINDOW_HEIGHT)
		{
			spawn(type);		
		}
	}
	void setDel() {
		del = true;
	}
	bool isToDel() {
		return del;
	}

	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}


};