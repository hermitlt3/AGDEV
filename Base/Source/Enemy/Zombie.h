#pragma once

#include "Vector3.h"

class Mesh;
class GroundEntity;
class GenericEntity;
class CZombie 
{
public:
	CZombie(void);
	virtual ~CZombie();

	void Init(Vector3 pos);

	// Set the terrain for the player info
	void SetTerrain(GroundEntity* m_pTerrain);
	// Get the terrain for the player info
	GroundEntity* GetTerrain(void);

	// Update
	void Update(double dt = 0.0333f);
private:
	GroundEntity* m_pTerrain;
	GenericEntity* bodyParts[6];
	double m_dSpeed;
	bool legless;
};
