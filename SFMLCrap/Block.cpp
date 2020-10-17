#include "Block.hpp"


Block::Block(float width, float height, float length) {
	this->width = width;
	this->height = height;
	this->length = length;

	drawShapeFront.setPointCount(4);

	drawShapeFront.setPoint(0, Utils::fromCasterianToIsometric(Vector3f(width, height, 0.f))); // (1, 1, 0)
	drawShapeFront.setPoint(1, Utils::fromCasterianToIsometric(Vector3f(width, 0.f, 0.f))); // (1, 0, 0)
	drawShapeFront.setPoint(2, Utils::fromCasterianToIsometric(Vector3f(width, 0.f, length))); // (1, 0, 1)
	drawShapeFront.setPoint(3, Utils::fromCasterianToIsometric(Vector3f(width, height, length))); // (1, 1, 1)

	drawShapeFront.setFillColor(Color::Red);
	drawShapeFront.setOutlineThickness(.5f);
	drawShapeFront.setOutlineColor(Color::Black);

	drawShapeTop.setPointCount(4);

	drawShapeTop.setPoint(0, Utils::fromCasterianToIsometric(Vector3f(0.f, 0.f, 0.f))); // (0, 0, 0)
	drawShapeTop.setPoint(1, Utils::fromCasterianToIsometric(Vector3f(width, 0.f, 0.f))); // (1, 0, 0)
	drawShapeTop.setPoint(2, Utils::fromCasterianToIsometric(Vector3f(width, 0.f, length))); // (1, 0, 1)
	drawShapeTop.setPoint(3, Utils::fromCasterianToIsometric(Vector3f(0.f, 0.f, length))); // (0, 0, 1)

	drawShapeTop.setFillColor(Color::Green);
	drawShapeTop.setOutlineThickness(.5f);
	drawShapeTop.setOutlineColor(Color::Black);

	drawShapeRight.setPointCount(4);

	drawShapeRight.setPoint(0, Utils::fromCasterianToIsometric(Vector3f(width, height, length))); // (1, 1, 1)
	drawShapeRight.setPoint(1, Utils::fromCasterianToIsometric(Vector3f(width, 0.f, length))); // (1, 0, 1)
	drawShapeRight.setPoint(2, Utils::fromCasterianToIsometric(Vector3f(0.f, 0.f, height))); // (0, 0, 1)
	drawShapeRight.setPoint(3, Utils::fromCasterianToIsometric(Vector3f(0.f, height, height))); // (0, 1, 1)

	drawShapeRight.setFillColor(Color::Blue);
	drawShapeRight.setOutlineThickness(.5f);
	drawShapeRight.setOutlineColor(Color::Black);
}


Block::Block(sf::Vector3f sizes) : Block(sizes.x, sizes.y, sizes.z) {

}


void Block::drawTop(sf::RenderWindow* window, sf::Vector2f position) {
	drawShapeTop.setPosition(position);
	window->draw(drawShapeTop);
}


void Block::drawFront(sf::RenderWindow* window, sf::Vector2f position) {
	drawShapeFront.setPosition(position);
	window->draw(drawShapeFront);
}


void Block::drawRight(sf::RenderWindow* window, sf::Vector2f position) {
	drawShapeRight.setPosition(position);
	window->draw(drawShapeRight);
}


void Block::draw(sf::RenderWindow* window, sf::Vector2f position) {
	drawShapeFront.setPosition(position);
	drawShapeTop.setPosition(position);
	drawShapeRight.setPosition(position);

	window->draw(drawShapeFront);
	window->draw(drawShapeTop);
	window->draw(drawShapeRight);
}