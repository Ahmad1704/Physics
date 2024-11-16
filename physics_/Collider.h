#pragma once
#include "Vector2d.h"
#include <iostream>


class Collider
{

public:
	float r;
	Vector2d center;


	bool CheckCollision(Collider other);

};


