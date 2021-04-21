#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Block.hpp"
#include "Utils.hpp"

using namespace std;


class Map
{
private:
	int width, height, length;
	vector<vector<vector<int>>> field;

public:
	Map(int width, int height, int length);

	int& getBlock(int x, int y, int z);
	void draw(sf::RenderWindow* window, sf::Vector3f sizes);

	int getWidth() const;
    int getHeight() const;
    int getLength() const;
};

