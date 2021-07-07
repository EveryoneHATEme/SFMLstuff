#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Map.hpp"
#include "Utils.hpp"
#include "Block.hpp"

using namespace sf;


class Game
{
private: 
	RenderWindow* window;
	Clock* clock;
	Event currentEvent{};
	Map* map;
	bool leftMouseKeyPressed{false};
	Vector2i lastMousePosition;
	Vector2i currentMousePosition;

public:
	Game(unsigned int windowWidth, unsigned int windowHeight, const char* title, unsigned int fpsLimit);
	~Game();

	void draw();
	void update();
	void loop();
	void checkEvents();
};

