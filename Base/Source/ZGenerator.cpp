#include "ZGenerator.h"
#include "Zombi.h"
#include "Steve.h"

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

void ZGenerator::GenerateZombies(Vector3 target, std::string type)
{
	if (doGenerate)
	{
		for (int i = 0; i < 5; ++i)
		{
			Vector3 a;
			a = Vector3(Math::RandFloatMinMax(areaStart.x, areaEnd.x), -3, Math::RandFloatMinMax(areaStart.z, areaEnd.z));
			if (type == "zombie")
			{
				CZombie *zomzom = new CZombie();
				zomzom->Init(a);
				zomzom->SetTarget(target);
			}
			else if (type == "stevie")
			{
				CSteve *stevie = new CSteve();
				stevie->Init(a);
				stevie->SetTarget(target);
			}
		}
		doGenerate = false;
	}
}