#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Game
{
private: 
	RenderWindow* window;
	Clock* clock;
	Event currentEvent;

public:
	Game(unsigned int windowWidth, unsigned int windowHeight, const char* title, unsigned int fpsLimit);
	~Game();

	void draw();
	void update();
	void loop();
};

