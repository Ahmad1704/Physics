#include"PhysicsWorld.h"


void PhysicsWorld::addParticle(Particle* particle)
{
	particles.push_back(particle);
}



void PhysicsWorld::Update(float deltaTime)
{
	for (auto it = particles.begin(); it != particles.end(); ++it)
	{
		(**it).Update(deltaTime);
	}


}


void PhysicsWorld::CheckSATCollsion()
{
	
	for (auto it = particles.begin(); it != particles.end(); ++it)
	{
		Particle* p1 = *it;
		SATCollider c1 = p1->collider_sat;

		for (auto itt = std::next(it); itt != particles.end(); ++itt)
		{
			Particle *p2 = *itt;
			SATCollider c2 = p2->collider_sat;
			
			if (c1.CheckCollision(c2))
			{
				
				std::cout << "SAT Collision \n";
				DirctionChange( p1, p2);	
			}
			
		}
		

	}
}

void PhysicsWorld::CheckAABBCollsion()
{
	for (auto it = particles.begin(); it != particles.end(); ++it)
	{
		Particle *p1 = *it;
		AABBCollider c1 = p1->collider_aabb;


		for (auto itt = std::next(it); itt != particles.end(); ++itt)
		{
			Particle *p2 = *itt;
			AABBCollider c2 = p2->collider_aabb;
		
			if (c1.CheckCollision(c2))
			{

				std::cout << "AABB Collision \n";		
			
			}
		}
		
	}
}




void PhysicsWorld::ChecktwoCircleCollision()
{
	for (auto it = particles.begin(); it != particles.end(); ++it)
	{

		Particle *p1 = *it;
		Collider c1 = p1->collider;


		for (auto itt = std::next(it); itt != particles.end(); ++itt)
		{
			Particle *p2 = *itt;
			Collider c2 = p2->collider;
			
			if (c1.CheckCollision(c2))
			{
				std::cout << "Circle collision \n";
				
			}

		}
	}
}

void PhysicsWorld::DirctionChange(Particle* p1, Particle* p2)
{


	Vector2d velocity1 = p1->velocity;
	float mass1 = p1->mass;
	Vector2d position1 = p1->postion;

	Vector2d velocity2 = p2->velocity;
	float mass2 = p2->mass;
	Vector2d position2 = p2->postion;

	// Calculate the normal vector
	Vector2d normal1 = position1 - position2;
	float normalMag1 = normal1.getMagnitude();

	Vector2d normal2 = position2 - position1;
	float normalMag2 = normal2.getMagnitude();

	if (normalMag1 == 0 || normalMag2 == 0)
	{
		std::cerr << "Particles are overlapping or too close; no valid collision response.\n";
		return;
	}

	// Normalize the normal vectors
	Vector2d collisionNormal1 = normal1 / normalMag1;
	Vector2d collisionNormal2 = normal2 / normalMag2;

	// Calculate dot products
	float dot1 = (velocity1 - velocity2).Dot(collisionNormal1);
	float dot2 = (velocity2 - velocity1).Dot(collisionNormal2);

	if (dot1 >= 0 && dot2 >= 0)
	{
		// Particles are moving apart; no collision response needed
		std::cerr << "Particles are moving apart; no collision response.\n";
		return;
	}
	std::cout << "before Collision - Particle1 Velocity: (" << p1->velocity.x << ", " << p1->velocity.y << ")\n";
	std::cout << "before Collision - Particle2 Velocity: (" << p2->velocity.x << ", " << p2->velocity.y << ")\n";
	// Update velocities 
	velocity1 = velocity1 - (collisionNormal1 * (dot1 * (2 * mass2) / (mass1 + mass2)));
	velocity2 = velocity2 - (collisionNormal2 * (dot2 * (2 * mass1) / (mass1 + mass2)));

	// Assign updated velocities back to the particles
	p1->velocity = velocity1;
	p2->velocity = velocity2;

	// Debugging output
	std::cout << "after Collision - Particle1 Velocity: (" << p1->velocity.x << ", " << p1->velocity.y << ")\n";
	std::cout << "after Collision - Particle2 Velocity: (" << p2->velocity.x << ", " << p2->velocity.y << ")\n";
}