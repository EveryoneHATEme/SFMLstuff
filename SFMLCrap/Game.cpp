#include "Game.h"


Game::Game(unsigned int windowWidth, unsigned int windowHeight, const char* windowTitle, unsigned int fpsLimit) {
	window = new RenderWindow(VideoMode(windowWidth, windowHeight), windowTitle);
	window->setFramerateLimit(fpsLimit);

	clock = new Clock();
	currentEvent = Event();
}


void Game::draw() {
	window->clear();

	window->display();
}


void Game::update() {
	clock->restart();
	draw();
}


void Game::loop() {
	while (window->isOpen()) {
		while (window->pollEvent(currentEvent)) {
			if (currentEvent.type == Event::Closed)
				window->close();
		}

		update();
	}
}


Game::~Game() {
	delete window;
	delete clock;
}