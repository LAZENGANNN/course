#pragma once
#include "gameObj.h"
class Player :public GameObj {
private:
	float speedx;
	float speedy;
	int HP = 5;
public:
	Player() {
		texture.loadFromFile("");
		sprite.setTexture(texture);
		speedx = SPEED;
		speedy = SPEED;
		sprite.setPosition(PLAYER_START_POS);
	}
	void playerControl() {}
	void update() {}
	void draw(sf::RenderWindow& window) { window.draw(sprite); }
};