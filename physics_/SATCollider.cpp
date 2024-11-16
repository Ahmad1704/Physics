#include "SATCollider.h"

void SATCollider::updatePosition(Vector2d position)
{

	Vector2d delta = this->position - position;
	for (size_t i = 0; i < points.size(); i++)
	{
		points[i] += delta;
	}
	this->position = position;
}

bool SATCollider::CheckCollision(SATCollider other)
{
	std::vector<Vector2d>normals = getNormals();
	for (size_t i = 0; i < normals.size(); i++)
	{
		Vector2d otherShape = other.ProjectShape(normals[i]);
		Vector2d shape = ProjectShape(normals[i]);

		if (shape.y < otherShape.x)return false;
		if (shape.x > otherShape.y)return false;
	}
	normals = other.getNormals();
	for (size_t i = 0; i < normals.size(); i++)
	{
		Vector2d otherShape = other.ProjectShape(normals[i]);
		Vector2d shape = ProjectShape(normals[i]);

		if (shape.y < otherShape.x)return false;
		if (shape.x > otherShape.y)return false;
	}
	return true;
}

std::vector<Vector2d> SATCollider::getNormals()
{
	std::vector<Vector2d> normals;
	for (size_t i = 0; i < points.size()-1; i++)
	{
		Vector2d side = points[i + 1] - points[i];
		normals.push_back(side.getNormal().getNormalized());
	}
	Vector2d side = points[0] - points[points.size() - 1];
	normals.push_back(side.getNormal().getNormalized());
	return normals;
}

Vector2d SATCollider::ProjectShape(Vector2d axis)
{
	float dot = points[0].Dot(axis);
	float min = dot;
	float max = dot;
	for (size_t i = 0; i < points.size(); i++)
	{
		dot = points[i].Dot(axis);
		if (dot < min)
			min = dot;
		if (dot > max) 
			max = dot;
	}

	return Vector2d(min,max);
}
