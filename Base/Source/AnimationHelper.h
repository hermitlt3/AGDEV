#pragma once
#include "SingletonTemplate.h"
#include <list>
#include <queue>
#include "Vector3.h"

class SpriteAnimation;
class Animation;
class AnimHelper : public Singleton<AnimHelper>
{
	friend class AnimHelper;

public:
	bool AddAnimation(SpriteAnimation* s);
	void UpdateAnimation(double dt);
	void RenderAnimation();
	
	void SetAnimationActive(std::string meshName);

	~AnimHelper();

private:
	std::list<SpriteAnimation*>spriteList;
};

namespace Create
{
	SpriteAnimation* SAnimation(const std::string meshName, 
		int startFrame, int endFrame, int repeat, float time, bool active);
}