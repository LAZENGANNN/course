#pragma once
#include "settings.h"
#include "gameObj.h"

class Player : public GameObj {
private:
	sf::FloatRect bounds;
public:
	Player() {
		texture.loadFromFile(PLAYER_FILE_NAME);
		sprite.setTexture(texture);
		bounds = sprite.getGlobalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
	}
	void playerControl() {
		sf::Vector2f mouse;
		mouse = sf::Vector2f{ sf::Mouse::getPosition() };
		sprite.setPosition(mouse);
	}
	void update() {
		playerControl();
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
};