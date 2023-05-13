#pragma once
#pragma once
#include "settings.h"
#include "gameObj.h"

class Shot : public GameObj{
private:
	bool hit;

public:
	Shot(sf::Vector2f pos) {
		texture.loadFromFile("images\\exp4.jpg");
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition(pos);
		hit = false;
	}

	void update() {
	}

	sf::Sprite& getSprite() { return sprite; }

	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }

	void setHit() { hit = true; }

	bool isHited() { return hit; }

	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
};