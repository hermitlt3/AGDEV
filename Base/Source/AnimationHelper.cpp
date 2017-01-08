#include "AnimationHelper.h"
#include "SpriteAnimation.h"
#include "MeshBuilder.h"
#include "GraphicsManager.h"
#include "RenderHelper.h"

bool AnimHelper::AddAnimation(SpriteAnimation* s)
{
	for (std::list<SpriteAnimation*>::iterator it = spriteList.begin();
		it != spriteList.end(); ++it)
	{
		if ((*it)->name == s->name) {
			return false;
		}
	}
	spriteList.push_back(s);
	return true;
}

void AnimHelper::UpdateAnimation(double dt)
{
	for (std::list<SpriteAnimation*>::iterator it = spriteList.begin();
		it != spriteList.end(); ++it)
	{
		(*it)->Update(dt);
	}
}

void AnimHelper::RenderAnimation()
{
	/*modelStack.PushMatrix();
	modelStack.Translate(position.x, position.y, position.z);
	float angle = Math::RadianToDegree(atan2((playerPos - position).x, (playerPos - position).z));
	modelStack.Rotate(90, 0, 1, 0);
	modelStack.Scale(scale.x, scale.y, scale.z);
	RenderHelper::RenderMesh(MeshBuilder::GetInstance()->GetMesh(meshName));
	modelStack.PopMatrix();*/
}

SpriteAnimation* Create::SAnimation(const std::string meshName,
	int startFrame, int endFrame, int repeat, float time, bool active)
{
	SpriteAnimation* s = dynamic_cast<SpriteAnimation*>(MeshBuilder::GetInstance()->GetMesh(meshName));
	if (s){
		s->m_anim = new Animation();
		s->m_anim->Set(startFrame, endFrame, repeat, time, active);
		AnimHelper::GetInstance()->AddAnimation(s);
	}
	return s;
}

AnimHelper::~AnimHelper()
{

}

void AnimHelper::SetAnimationActive(std::string meshName)
{
	for (std::list<SpriteAnimation*>::iterator it = spriteList.begin();
		it != spriteList.end(); ++it)
	{
		if ((*it)->name == meshName) {
			(*it)->m_anim->animActive = true;
			return;
		}
	}
}
