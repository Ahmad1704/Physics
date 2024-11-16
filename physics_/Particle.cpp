#include "Particle.h"


Particle::Particle(Vector2d postion, float mass, float drag)
{
	this->postion = postion;
	this->mass = mass;
	this->drag = drag;
	forces = Vector2d(0, 0);
	velocity = Vector2d(0, 0);
	collider.center = postion;
	collider.r = 20;

	collider_aabb.ul = Vector2d(0, 0);
	collider_aabb.lr = Vector2d(40, 40);

	collider_aabb.UpdatePosition(postion);



	std::vector<Vector2d>points;

	points.push_back(Vector2d(0, 0));
	points.push_back(Vector2d(0, 40));
	points.push_back(Vector2d(40, 40));
	points.push_back(Vector2d(40, 0));

	collider_sat.points = points;
	collider_sat.updatePosition(postion);
}

void Particle::Update(float dt)
{
	acceleration = Vector2d(forces.x / mass, forces.y / mass);
	velocity += acceleration * dt;
	postion += velocity * dt;
	forces = Vector2d(0, 0);

	collider.center = postion;
	collider_aabb.UpdatePosition(postion);
	collider_sat.updatePosition(postion);

}

void Particle::addForce(Vector2d force)
{
	forces += force;
}

