#include "Game.hpp"


Game::Game(unsigned int windowWidth, unsigned int windowHeight, const char* windowTitle, unsigned int fpsLimit) {
	window = new RenderWindow(VideoMode(windowWidth, windowHeight), windowTitle);
	window->setFramerateLimit(fpsLimit);

	clock = new Clock();
	currentEvent = Event();

	map = new Map(10, 10, 10);
}


void Game::draw() {
	window->clear(Color::White);

	float blockWidth = 15.f;
	float blockHeight = 15.f;
	float blockLength = 15.f;

	View view(Vector2f(0.f, 100.f), Vector2f(300.f, 300.f));
	window->setView(view);

	map->draw(window, Vector3f(blockWidth, blockHeight, blockLength));

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
	delete map;
}