#pragma once
#include "settings.h"
#include "gameObj.h"
#include "shot.h"
#include <list>

class Player : public GameObj {
private:
	sf::FloatRect bounds;
	/*std::list<Shot*> shot;
	sf::Clock timer;*/

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

	/*void fire() {
		int now = timer.getElapsedTime().asMilliseconds();
		if (now > 350) {
			sf::Vector2f Pos{ sprite.getPosition().x + bounds.width / 2,  sprite.getPosition().y };
			shot* s = new Shot(Pos);
			shot.push_back(s);
			timer.restart();

		}
	}*/

	void update() {
		playerControl();
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
		/*for (auto shot : shot) {
			window.draw(shot->getSprite());
		}*/
	}
};