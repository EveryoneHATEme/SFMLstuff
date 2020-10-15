#include "Utils.h"


Vector2f Utils::fromCasterianToIsometric(Vector3f vector) {
	float x = vector.x * pow(0.5f, 0.5f) - vector.z * pow(0.5f, 0.5f);
	float y = vector.x * pow(1.f / 6.f, 0.5f) + vector.y * pow(2.f / 3.f, 0.5f) + vector.z * pow(1.f / 6.f, 0.5f);
	return Vector2f(x, y);
}