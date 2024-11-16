#include <SFML/Graphics.hpp>
#include <iostream>
#include "Particle.h"
#include "PhysicsWorld.h"
#include "Renderer.h"
#include "Vector2d.h"



int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Template!");

    PhysicsWorld physicsWorld;
    Renderer renderer;

    Vector2d position(100, 100);
    Vector2d position2(600, 100);
    Particle particle(position, 1);
    Particle particle2(position2, 1);
    Vector2d gravity(0, 9.8 * particle.mass);
    //particle.addForce(gravity);
    particle.addForce(Vector2d(10000,0 ));
    particle2.addForce(Vector2d(-10000, 0));


    Clock clock;
    float time = 0;
    float dt = 0;

    physicsWorld.addParticle(&particle);
    physicsWorld.addParticle(&particle2);

    sf::CircleShape circle(100, 100);
    circle.setRadius(20);
    sf::CircleShape circle2(600, 100);
    circle2.setRadius(20);
    circle2.setFillColor(sf::Color(255, 0, 255));
    

    renderer.AddDrawable(&circle2);
    renderer.AddDrawable(&circle);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        dt = clock.getElapsedTime().asSeconds() - time;
        time += dt;

        physicsWorld.Update(dt);

        circle.setPosition(particle.postion.x, particle.postion.y);
        circle2.setPosition(particle2.postion.x, particle2.postion.y);
        physicsWorld.ChecktwoCircleCollision();
        physicsWorld.CheckAABBCollsion();
        physicsWorld.CheckSATCollsion();
        physicsWorld.Update(dt);
        renderer.Render(&window);
    }

    return 0;
}