#pragma once
#include <vector>

using namespace std;


class Map
{
private:
	int width, height, length;
	vector<vector<vector<int>>> field;

public:
	Map(int width, int height, int length);

	int getBlock(int x, int y, int z);

	int getWidth();
	int getHeight();
	int getLength();
};

