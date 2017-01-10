#include "ZGenerator.h"
#include "Zombi.h"

ZGenerator::ZGenerator() :
doGenerate(false),
areaStart(Vector3(-5 ,0, -5)),
areaEnd(Vector3(5, 0, 5))
{

}

ZGenerator::~ZGenerator()
{

}

void ZGenerator::Update(double dt)
{
	
}

void ZGenerator::GenerateZombies(Vector3 target)
{
	if (doGenerate)
	{
		for (int i = 0; i < 5; ++i)
		{
			Vector3 a;
			a = Vector3(Math::RandFloatMinMax(areaStart.x, areaEnd.x), -3, Math::RandFloatMinMax(areaStart.z, areaEnd.z));
			CZombie *zomzom = new CZombie();
			zomzom->Init(a);
			zomzom->SetTarget(target);
		}
		doGenerate = false;
	}
}