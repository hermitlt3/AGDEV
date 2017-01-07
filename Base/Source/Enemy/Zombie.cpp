#include "Zombie.h"
#include "../EntityManager.h"
#include "GraphicsManager.h"
#include "RenderHelper.h"
#include "../GenericEntity.h"
#include "../GroundEntity.h"
#include "../SceneGraph/SceneNode.h"
#include "../SceneGraph/SceneGraph.h"

CZombie::CZombie() :
	m_pTerrain(NULL)
{
}

CZombie::~CZombie()
{
}

void CZombie::Init(Vector3 pos)
{
	bodyParts[0] = Create::Entity("ZHead", Vector3(0, 2.5f, 0), Vector3(1.f, 1.f, 1.f), false);
	bodyParts[1] = Create::Entity("ZHand", Vector3(1, 1, -1.6f), Vector3(1.f, 1.f, 1.f), false);
	bodyParts[2] = Create::Entity("ZHand", Vector3(1, 1, 1.6f), Vector3(1.f, 1.f, 1.f), false);
	bodyParts[3] = Create::Entity("ZTorso", Vector3(pos.x, pos.y, pos.z), Vector3(1.5f, 1.5f, 1.5f), false);
	bodyParts[4] = Create::Entity("ZLeg", Vector3(0, -3, -0.5f), Vector3(1.f, 1.f, 1.f), false);
	bodyParts[5] = Create::Entity("ZLeg", Vector3(0, -3, 0.5f), Vector3(1.f, 1.f, 1.f), false);

	for (int i = 0; i < 6; ++i) {
		bodyParts[i]->SetCollider(true);
	}

	bodyParts[0]->SetAABB(Vector3(1.5f, 1.5f, 1.5f), Vector3(-1.5f, -1.5f, -1.5f));
	bodyParts[1]->SetAABB(Vector3(1.5f, 1.f, 1.f), Vector3(-1.5f, -1.f, -1.f));
	bodyParts[2]->SetAABB(Vector3(1.5f, 1.f, 1.f), Vector3(-1.5f, -1.f, -1.f));
	bodyParts[3]->SetAABB(Vector3(1.f, 2.f, 1.6f), Vector3(-1.f, -2.f, -1.6f));
	bodyParts[4]->SetAABB(Vector3(1.f, 2.f, 1.f), Vector3(-1.f, -2.f, -1.f));
	bodyParts[5]->SetAABB(Vector3(1.f, 2.f, 0.8f), Vector3(-1.f, -2.f, -0.8f));

	CSceneNode* bodyNode = CSceneGraph::GetInstance()->AddNode(bodyParts[3]);
	CSceneNode* headNode = bodyNode->AddChild(bodyParts[0]);
	CSceneNode* lhandNode = bodyNode->AddChild(bodyParts[1]);
	lhandNode->ApplyRotate(90.f, 0, 1, 0);
	CSceneNode* rhandNode = bodyNode->AddChild(bodyParts[2]);
	rhandNode->ApplyRotate(90.f, 0, 1, 0);
	CSceneNode* llegNode = bodyNode->AddChild(bodyParts[4]);
	CSceneNode* rlegNode = bodyNode->AddChild(bodyParts[5]);

	for (int i = 0; i < 6; ++i) {
		CSpatialPartition::GetInstance()->Add(bodyParts[i]);
	}
}

// Set the terrain for the player info
void CZombie::SetTerrain(GroundEntity* m_pTerrain)
{
	if (m_pTerrain != NULL)
	{
		this->m_pTerrain = m_pTerrain;
	}
}

// Get the terrain for the player info
GroundEntity* CZombie::GetTerrain(void)
{
	return m_pTerrain;
}

// Update
void CZombie::Update(double dt)
{
	if (CSceneGraph::GetInstance()->GetNode(bodyParts[3]))
		CSceneGraph::GetInstance()->GetNode(bodyParts[3])->ApplyTranslate(dt * -10, 0, 0);
}