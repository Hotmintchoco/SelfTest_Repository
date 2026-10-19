#include "pch.h"
#include "CWorld.h"
#include "CGameObject.h"
#include "CRobot.h"
#include "CEnemy.h"

CWorld::CWorld()
{
	cout << "World 생성" << endl;
}

CWorld::~CWorld()
{
	cout << "World 소멸" << endl;
}

void CWorld::Initialize()
{
	auto player = make_unique<CRobot>();
	player->Initialize();
	player->Set_Hp(10);
	m_vecObejct.push_back(std::move(player));
	
	for (int i = 0; i < 3; ++i)
	{
		auto enemy = make_unique<CEnemy>();
		enemy->Initialize();
		enemy->Set_Hp(3);
		m_vecObejct.push_back(std::move(enemy));
	}
}

void CWorld::Update()
{
	for (auto& iter : m_vecObejct)
		iter->Update();
}

void CWorld::LateUpdate()
{
	// 전투 처리
	for (auto& iter : m_vecObejct)
	{
		if (iter->Get_ID() > 1)
			iter->Hit(5);
	}

	m_vecObejct.erase(
		remove_if(m_vecObejct.begin(), m_vecObejct.end(),
			[](const auto& obj)
			{
				return obj->Get_IsDead();
			}),
		m_vecObejct.end());
}

void CWorld::Render()
{
	if (m_vecObejct.size() < 3)
		Set_Exit();
}

