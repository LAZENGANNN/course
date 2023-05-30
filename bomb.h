#pragma once
#include "settings.h"
#include "gameObj.h"

class Bomb : public GameObj {
private:
	float speedy = 8;
	bool del = false;
public:
	Bomb(sf::Vector2f pos) {
		texture.loadFromFile("images\\laserRed08.png");
		sprite.setTexture(texture);
		sprite.setPosition(pos);
	}

	void update() {
		sprite.move(0, speedy);
	}

	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}

	bool offScreen() {
		if (sprite.getPosition().y > WINDOW_HEIGHT) return true;
		return false;
	}

	bool isToDel() { return del; }

	void setDel() { del = true; }
};