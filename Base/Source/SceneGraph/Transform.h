﻿#pragma once
#include "Mtx44.h"
#include "UpdateTransformation.h"
#include "Vector3.h"
class CTransform
{
protected:
	Mtx44 Mtx, DefaultMtx;
	CUpdateTransformation* theUpdateTransformation;
public:
	enum AXIS
	{
		X_AXIS = 0,
		Y_AXIS,
		Z_AXIS,
		NUM_AXIS
	};

	// Default Constructor
	CTransform(void);
	// Overloaded Constructor
	CTransform( const float dx, const float dy, const float dz  );
	// Destructor
	~CTransform(void);

	// Apply a translation to the Transformation Matrix
	void ApplyTranslate( const float dx, const float dy, const float dz  );
	// Get the translation from the Transformation Matrix
	void GetTranslate(float& x, float& y, float& z);
	Vector3 GetTranslate() {
		return Vector3(Mtx.a[12], Mtx.a[13], Mtx.a[14]);
	}
	void SetTranslate(Vector3 pos) {
		Mtx.a[12] = pos.x; Mtx.a[13] = pos.y; Mtx.a[14] = pos.z;
	}
	void SetRotate(float angle, const float x, const float y, const float z)
	{
		Mtx44 tempMtx;
		tempMtx.SetToRotation(angle, x, y, z);
		Mtx = tempMtx;
	}
	// Apply a rotation to the Transformation Matrix
	void ApplyRotate(const float angle, const float rx, const float ry, const float rz);
	// Get the rotation from the Transformation Matrix
	float GetRotate(const AXIS theAxis);
	// Set the scale of the Transformation Matrix
	void SetScale(const float sx, const float sy, const float sz);
	// Get the scale from the Transformation Matrix
	void GetScale(float& x, float& y, float& z);

	// Apply a Transformation Matrix to the Transformation Matrix here
	void ApplyTransform(Mtx44 newMTX);

	// Reset the transformation matrix to identity matrix
	void Reset (void); //reset to identity
	
	// Get the transformation matrix
	Mtx44& GetTransform(void);
	// Set the Update Transformation
	void SetUpdateTransformation(CUpdateTransformation* theUpdateTransformation=NULL);
	// Get the update transformation matrix
	Mtx44 GetUpdateTransform(void);

	// Print Self
	void PrintSelf(void) const;
};
