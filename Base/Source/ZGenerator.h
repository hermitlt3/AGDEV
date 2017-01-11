#pragma once
#include "Vector3.h"
#include <string>

class ZGenerator
{
public:
	ZGenerator();
	~ZGenerator();

	void SetGenerate(const bool& set) { doGenerate = set; }
	bool GetGenerate() { return doGenerate; }
	
	void SetStart(const Vector3& start) { areaStart = start; }
	Vector3& GetStart() { return areaStart; }

	void SetEnd(const Vector3& end) { areaEnd = end; }
	Vector3& GetEnd() { return areaEnd; }

	void Update(double dt);
	void GenerateZombies(Vector3 target, std::string type);

private:
	bool doGenerate;
	Vector3 areaStart;
	Vector3 areaEnd;
};