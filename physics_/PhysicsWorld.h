#pragma once
#include "Particle.h"
#include "Collider.h"
#include "Vector2d.h"
#include<iostream>
#include <list>

using namespace std;

class PhysicsWorld
{
private:
public:
	list<Particle*> particles;
	void addParticle(Particle* particle);
	void Update(float deltaTime);


	void CheckSATCollsion();

	void ChecktwoCircleCollision();

	void CheckAABBCollsion();

	void DirctionChange(Particle *p1 , Particle *p2);

	static const Vector2d gravity;
};

