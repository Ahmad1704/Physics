#include "AABBCollider.h"

void AABBCollider::UpdatePosition(Vector2d position)
{
	Vector2d delta = position - this->position;

	ul += delta;
	lr += delta;
	this->position = position;
}

bool AABBCollider::CheckCollision(AABBCollider other)
{

	if (ul.x >= other.ul.x &&
		ul.x <= other.lr.x &&
		ul.y >= other.ul.y &&
		ul.y <= other.lr.y) return true;
	if (lr.x >= other.ul.x &&
		lr.x <= other.lr.x &&
		lr.y >= other.ul.y &&
		lr.y <= other.lr.y) return true;

	return false;
}
