#ifndef SCENE_TEXT_H
#define SCENE_TEXT_H

//#include "irrKlang.h"
#include "Scene.h"
#include "Mtx44.h"
#include "PlayerInfo/PlayerInfo.h"
#include "GroundEntity.h"
#include "FPSCamera.h"
#include "Mesh.h"
#include "MatrixStack.h"
#include "GenericEntity.h"
#include "SceneGraph/UpdateTransformation.h"
#include "Enemy\Zombie.h"

class ShaderProgram;
class SceneManager;
class TextEntity;
class Light;
class Windmill;
//using namespace irrklang;
class SceneText : public Scene
{	
public:
	SceneText();
	~SceneText();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

private:
	SceneText(SceneManager* _sceneMgr); // This is used to register to SceneManager

	ShaderProgram* currProg;
	CPlayerInfo* playerInfo;
	GroundEntity* groundEntity;
	FPSCamera camera;
	TextEntity* textObj[3];
	Light* lights[2];

	GenericEntity* theCube;
	CZombie* theEnemy;
	Windmill *mill;

	//ISoundEngine* Sound_Engine;
	//ISound* Sound;

	static SceneText* sInstance; // The pointer to the object that gets registered
};

#endif