#pragma once
#include "Vector2d.h"
class AABBCollider

{

public:


	// uber left
	Vector2d ul;

	//lower right
	Vector2d lr ;

	Vector2d position = Vector2d(0,0);


	void UpdatePosition(Vector2d position);
	bool CheckCollision(AABBCollider other);
};

