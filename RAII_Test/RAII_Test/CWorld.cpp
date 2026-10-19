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
	m_vecObject.push_back(std::move(player));
	
	for (int i = 0; i < 3; ++i)
	{
		auto enemy = make_unique<CEnemy>();
		enemy->Initialize();
		enemy->Set_Hp(3);
		m_vecObject.push_back(std::move(enemy));
	}
}

void CWorld::Update()
{
	for (auto& iter : m_vecObject)
		iter->Update();
}

void CWorld::LateUpdate()
{
	// 전투 처리
	for (auto& iter : m_vecObject)
	{
		if (iter->Get_ID() > 1)
			iter->Hit(5);
	}

	m_vecObject.erase(
		remove_if(m_vecObject.begin(), m_vecObject.end(),
			[](const auto& obj)
			{
				return obj->Get_IsDead();
			}),
		m_vecObject.end());

	// 종료 조건
	if (m_vecObject.size() < 3)
		Set_Exit();
}

void CWorld::Render()
{
	// 후에 그려질 화면
}

