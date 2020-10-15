#include "Map.h"


Map::Map(int width, int height, int length) {
	this->width = width;
	this->height = height;
	this->length = length;

	field = vector<vector<vector<int>>>(width, vector<vector<int>>(height, vector<int>(length, 0)));

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < length; j++) {
			field[i][0][j] = 1;
		}
	}
}


int Map::getBlock(int x, int y, int z) {
	return field.at(x).at(y).at(z);
}


int Map::getWidth() {
	return width;
}


int Map::getHeight() {
	return height;
}


int Map::getLength() {
	return length;
}
