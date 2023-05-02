#pragma once
#include "settings.h"
#include "player.h"

class Game {
private:
	Player player;
	sf::RenderWindow window;

	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();
	}

	void update() {
		player.update();
	}
	void checkCollisions() {}

	void draw() {
		player.draw(window);
	}
public:
	Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE) {
		window.setFramerateLimit(FPS);		
	}
	void play() {
		while (window.isOpen())
		{
			checkEvents();
			update();
			checkCollisions();
			draw();
		}
	}
};