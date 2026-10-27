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
	m_iPlayerID = player->Get_ID();

	m_vecObject.push_back(std::move(player));
	
	// 적 A
	auto enemy = make_unique<CEnemy>();
	enemy->Initialize();
	enemy->Set_Hp(8);
	m_vecObject.push_back(std::move(enemy));

	// 적 B, C
	for (int i = 0; i < 2; ++i)
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
	int iInput(0);
	uint32_t iFindID(UINT32_MAX);

	cout << "\n종료 : 0\t체력이 낮은 적 공격 : 1\t" << endl;
	cin >> iInput;

	switch (iInput)
	{
	case 0: 
		Set_Exit();
		break;
	case 1:
		iFindID = FindLowestHpEnemy();
		if (iFindID == UINT32_MAX)
			cout << "현재 적이 존재하지 않습니다." << endl;
		else
		{
			cout << "현재 Hp가 낮은 적의 ID : " << iFindID << endl;
			
			CGameObject* pPlayer = FindAliveID(m_iPlayerID);
			if (nullptr == pPlayer)
				break;

			CGameObject* pEnemy = FindAliveID(iFindID);
			if (nullptr == pEnemy)
				break;

			static_cast<CRobot*>(pPlayer)->Attack(pEnemy);

			uint32_t iNextID = FindLowestHpEnemy();
			cout << "다음 적의 ID : " << iNextID << endl;
		}
		break;
	default:
		break;
	}

	CGameObject* pEnemy = nullptr;

	if (iFindID != UINT32_MAX)
	{
		/* Enemy 처치 직후, 제거 전 ID 검색 */
		pEnemy = FindAliveID(iFindID);
		if (nullptr == pEnemy)
			cout << "Enemy 처치 완료 / nullptr 반환" << endl;
		else
			cout << "대상 생존\tID : " << iFindID << endl;
	}

	// 삭제 처리
	int iSize = m_vecObject.size();

	erase_if(m_vecObject, [](const auto& obj)
		{
			return obj->Get_IsDead();
		});

	if (iFindID != UINT32_MAX)
	{
		/* 제거 후 같은 ID 검색 */
		pEnemy = FindAliveID(iFindID);
		if (nullptr == pEnemy && m_vecObject.size() < iSize)
			cout << "제거 완료 / vecSize " << iSize << " -> " << m_vecObject.size() << endl;
	}
}

void CWorld::Render()
{
	// 후에 그려질 화면
}

unsigned int CWorld::FindLowestHpEnemy()
{
	uint32_t iFindID = UINT32_MAX;
	vector<CGameObject*> vecCandidates;

	for (auto& iter : m_vecObject)
	{
		if (iter->Get_ObjType() != OBJTYPE::ENEMY || iter->Get_IsDead())
			continue;

		vecCandidates.push_back(iter.get());
	}

	auto iter = std::min_element(vecCandidates.begin(), vecCandidates.end(),
		[](const CGameObject* a, const CGameObject* b) 
		{
			if (a->Get_Hp() == b->Get_Hp())
				return a->Get_ID() < b->Get_ID();
			else
				return a->Get_Hp() < b->Get_Hp();
		});

	if (iter != vecCandidates.end())
		iFindID = (*iter)->Get_ID();

	return iFindID; // 최대값을 반환받을 시에 존재하지 않는 것으로 판단
}

CGameObject* CWorld::FindAliveID(unsigned int id)
{
	auto iter = find_if(m_vecObject.begin(), m_vecObject.end(), [id](const auto& obj)
		{
			return obj->Get_ID() == id;
		});

	if (iter == m_vecObject.end())
		return nullptr;

	CGameObject* pObj = iter->get();

	if (pObj->Get_Hp() <= 0 || pObj->Get_IsDead())
		return nullptr;

	return pObj;
}

