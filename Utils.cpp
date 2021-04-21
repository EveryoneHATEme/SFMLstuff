#include "Utils.hpp"


Vector2f Utils::fromCasterianToIsometric(Vector3f vector) {
	float x = vector.x * std::pow(0.5f, 0.5f) - vector.z * std::pow(0.5f, 0.5f);
	float y = vector.x * std::pow(1.f / 6.f, 0.5f)
	        + vector.y * std::pow(2.f / 3.f, 0.5f)
	        + vector.z * std::pow(1.f / 6.f, 0.5f);
	return {x, y};
}