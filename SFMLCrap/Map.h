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
};

