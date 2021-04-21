#pragma once

#include <SFML/Graphics.hpp>

#include "Utils.hpp"


class Block
{
private:
	sf::ConvexShape drawShapeTop;
	sf::ConvexShape drawShapeFront;
	sf::ConvexShape drawShapeRight;
	float width, height, length;

public:
	Block(float width, float height, float length);
	explicit Block(sf::Vector3f sizes);
	void draw(sf::RenderWindow* window, sf::Vector2f position);

	void drawTop(sf::RenderWindow* window, sf::Vector2f position);
	void drawFront(sf::RenderWindow* window, sf::Vector2f position);
	void drawRight(sf::RenderWindow* window, sf::Vector2f position);
};

