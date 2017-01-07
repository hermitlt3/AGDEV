#include "Physics.h"
#include <iostream>
Physics::Physics() :
isAffectedbyG(false),
isAffectedbyA(false),
physicsToggle(false),
force(0, 0, 0),
acceleration(0, 0, 0),
velocity(0, 0, 0),
mass(1)
{

}

Physics::~Physics()
{

}

void Physics::update(Vector3& position, double _dt) {
	// s = ut + 0.5at^2
	// v^2 = u^2 + 2as
	// v = u + at
	// s = (u + v) * t / 2

	if (isAffectedbyG) 
		acceleration.y += IN_GAME_GRAVITY;
	
	if (velocity.Length() < Math::EPSILON && velocity.Length() > -Math::EPSILON)
		velocity.SetZero();

	// FORCE = MASS * ACCELERATION
	acceleration += force * (1.f / mass);
	// FINAL VELOCITY = INITIAL VELOCITY + ACCELERATION * TIME
	velocity += acceleration * _dt;

	// POSITION = VELOCITY * TIME
	if ((position + velocity *_dt).y < -10.f) {
		velocity.y *= -0.5f;
		velocity.z *= 0.2f;
	}
	else {
		position += velocity * _dt;
	}

	force.SetZero();
	acceleration.SetZero();
}