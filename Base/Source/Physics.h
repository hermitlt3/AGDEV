#pragma once
#include "Vector3.h"

class Physics
{
	friend class GenericEntity;
	friend class GroundEntity;
	friend class CProjectile;

	const float IN_GAME_GRAVITY = -15.f;

public:
	~Physics();

	void update(Vector3& position, double _dt);
	bool& boolGravity() { return isAffectedbyG;  }
	bool& boolAcceleration() { return isAffectedbyA;  }
	bool& boolPhysics() { return physicsToggle; }
	Vector3& getVelocity() { return velocity; }
	Vector3& getAcceleration() { return acceleration; }
	Vector3& getForce() { return force; }

protected:
	bool isAffectedbyG;
	bool isAffectedbyA;
	bool physicsToggle;

	Vector3 force;
	Vector3 acceleration;
	Vector3 velocity;

	float mass;
	
private:
	Physics();
};