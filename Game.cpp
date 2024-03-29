#include "Game.hpp"


Game::Game(unsigned int windowWidth, unsigned int windowHeight, const char* windowTitle, unsigned int fpsLimit) {
	window = new RenderWindow(VideoMode(windowWidth, windowHeight), windowTitle);
	window->setFramerateLimit(fpsLimit);

	clock = new Clock();
	currentEvent = Event();

	map = new Map(10, 10, 10);
    View view(Vector2f(150.f, 150.f), Vector2f(300.f, 300.f));
    window->setView(view);
}


void Game::draw() {
	window->clear(Color::White);

	float blockWidth = 15.f;
	float blockHeight = 15.f;
	float blockLength = 15.f;

	map->draw(window, Vector3f(blockWidth, blockHeight, blockLength));

	window->display();
}


void Game::update() {
    if (leftMouseKeyPressed) {
        View currentView = window->getView();
        Vector2f delta = Vector2f(lastMousePosition - currentMousePosition);
        currentView.move(delta);
        window->setView(currentView);
        lastMousePosition = currentMousePosition;
    }
	clock->restart();
	draw();
}


void Game::loop() {
	while (window->isOpen()) {
	    checkEvents();
		update();
	}
}


void Game::checkEvents() {
    while (window->pollEvent(currentEvent)) {
        if (currentEvent.type == Event::Closed)
            window->close();

        if (currentEvent.type == Event::MouseMoved) {
            lastMousePosition = currentMousePosition;
            currentMousePosition = sf::Mouse::getPosition(*window);
        }

        if (currentEvent.type == Event::MouseButtonPressed) {
            if (currentEvent.mouseButton.button == sf::Mouse::Left) {
                leftMouseKeyPressed = true;
            }
        }

        if (currentEvent.type == Event::MouseButtonReleased) {
            leftMouseKeyPressed = false;
        }

        if (currentEvent.type == Event::MouseWheelScrolled) {
            if (currentEvent.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                View current_view = window->getView();
                float delta = currentEvent.mouseWheelScroll.delta;
                if (currentEvent.mouseWheelScroll.delta > 0)
                    current_view.zoom(1.f / (delta + 1));
                else if (delta < 0)
                    current_view.zoom(1 - delta);

                window->setView(current_view);
            }
        }
    }
}


Game::~Game() {
	delete window;
	delete clock;
	delete map;
}