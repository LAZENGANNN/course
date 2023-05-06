#pragma once
#include "settings.h"
#include "player.h"

class Game {
private:
	sf::RenderWindow window;
	Player player;

	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();
	}

	void update(){
		player.update();
	}

	void draw() {
		window.clear();
		player.draw(window);
		window.display();
	}

public:
	Game() :
		window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE)		
	{
		window.setFramerateLimit(FPS);
	}

	void play() {
		while (window.isOpen()/* && player.isAlive()*/)
		{
			checkEvents();
			update();
			/*checkCollisions();*/
			draw();
		}
	}
};