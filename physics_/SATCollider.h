#pragma once

#include "Vector2d.h"
#include <vector>
class SATCollider
{
	Vector2d position;
public:
	std::vector<Vector2d> points;
	void updatePosition(Vector2d position);
	bool CheckCollision(SATCollider other);
	std::vector<Vector2d> getNormals();
	Vector2d ProjectShape(Vector2d axis);
};

