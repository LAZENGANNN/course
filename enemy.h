#pragma once
#include "settings.h"
#include "gameObj.h"

class Enemy : public GameObj{
private:
	float speedx, speedy;
	int side;
	enum EnemyType { RIGHT_GREEN };
	EnemyType type;
public:

	
	Enemy() {
		side = rand() % 2;
		texture.loadFromFile("images\\green_ship_right.png");
		sprite.setTexture(texture);
		spawn();
	}
	/*Enemy(EnemyType type, sf::Vector2f position) {
		side = rand() % 2;
		this->type = type;
		switch (type) {
		case RIGHT_GREEN:
			texture.loadFromFile("images\\green_ship_right.png");
			break;
		}
		sprite.setTexture(texture);
		sprite.setPosition(position);
	
		spawn(type);
	}*/

	void spawn() {
		speedx = rand() % 20 + 5;
		float y = (rand() % (int)(WINDOW_HEIGHT));
		sprite.setPosition(0, y + ENEMY_WIDTH);
	} 
	/*void spawn(EnemyType type) {
		this->type = type;
			switch (type) {
			case RIGHT_GREEN:
				speedx = rand() % 6 + 2;
				float y = (rand() % (int)(WINDOW_HEIGHT));
				sprite.setPosition(0, y + ENEMY_WIDTH);
				break;
			}
	}*/

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
