#include "Game.h"


Game::Game(unsigned int windowWidth, unsigned int windowHeight, const char* windowTitle, unsigned int fpsLimit) {
	window = new RenderWindow(VideoMode(windowWidth, windowHeight), windowTitle);
	window->setFramerateLimit(fpsLimit);

	clock = new Clock();
	currentEvent = Event();

	map = new Map(10, 10, 10);
}


void Game::draw() {
	window->clear(Color::White);

	int blockWidth = 20.f;
	int blockHeight = 20.f;
	int blockLength = 20.f;

	ConvexShape shape;
	shape.setPointCount(4);

	shape.setPoint(0, Utils::fromCasterianToIsometric(Vector3f(0.f, 0.f, 0.f))); // (0, 0, 0)
	shape.setPoint(1, Utils::fromCasterianToIsometric(Vector3f(blockWidth, 0.f, 0.f))); // (1, 0, 0)
	shape.setPoint(2, Utils::fromCasterianToIsometric(Vector3f(blockWidth, 0.f, blockHeight))); // (1, 0, 1)
	shape.setPoint(3, Utils::fromCasterianToIsometric(Vector3f(0.f, 0.f, blockHeight))); // (0, 0, 1)

	shape.setOutlineThickness(1.f);
	shape.setOutlineColor(Color::Black);

	View view(Vector2f(0.f, 0.f), Vector2f(300.f, 300.f));
	window->setView(view);

	Vector3f blockPos;

	for (int i = 0; i < map->getWidth(); i++) {
		for (int j = 0; j < map->getHeight(); j++) {
			for (int k = 0; k < map->getLength(); k++) {
				if (map->getBlock(i, j, k)) {
					blockPos = Vector3f(i * blockWidth, j * blockHeight, k * blockLength);
					shape.setPosition(Utils::fromCasterianToIsometric(blockPos));

					shape.setFillColor(Color::Green);

					window->draw(shape);
				}
			}
		}
	}

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