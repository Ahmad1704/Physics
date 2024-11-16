#include "collider.h"

bool Collider::CheckCollision(Collider other)
{
    return ((other.center - center).getMagnitude() < (other.r + r));
}

