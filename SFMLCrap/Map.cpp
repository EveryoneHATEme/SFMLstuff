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