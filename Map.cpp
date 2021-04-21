#include "Map.hpp"


Map::Map(int width, int height, int length) {
	this->width = width;
	this->height = height;
	this->length = length;

	field = vector<vector<vector<int>>>(width, vector<vector<int>>(height, vector<int>(length, 0)));

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			for (int k = 0; k < length; k++)
				getBlock(i, j, k) = 1;
		}
	}
}


int& Map::getBlock(int x, int y, int z) {
	return field.at(x).at(y).at(z);
}


void Map::draw(sf::RenderWindow* window, sf::Vector3f sizes) {
	Block block(sizes);
	Vector2f blockPos;

	for (int j = height - 1; j >= 0; j--) {
		for (int i = 0; i < width; i++) {
			for (int k = 0; k < length; k++) {
				if (getBlock(i, j, k)) {
					blockPos = Utils::fromCasterianToIsometric(Vector3f(float(i) * sizes.x, float(j) * sizes.y, float(k) * sizes.z));

					if ((j > 0) && (j < height)) {
						if (getBlock(i, j - 1, k) == 0) {
							block.drawTop(window, blockPos);
						}
					}
					else if (j == 0) {
						block.drawTop(window, blockPos);
					}

					if ((i >= 0) && (i < width - 1)) {
						if (getBlock(i + 1, j, k) == 0) {
							block.drawFront(window, blockPos);
						}
					} 
					else if (i == width - 1)
						block.drawFront(window, blockPos);

					if ((k >= 0) && k < (length - 1)) {
						if (getBlock(i, j, k + 1) == 0) {
							block.drawRight(window, blockPos);
						}
					}
					else if (k == length - 1)
						block.drawRight(window, blockPos);
				}
			}
		}
	}
}


int Map::getWidth() const {
	return width;
}


int Map::getHeight() const {
	return height;
}


int Map::getLength() const {
	return length;
}
