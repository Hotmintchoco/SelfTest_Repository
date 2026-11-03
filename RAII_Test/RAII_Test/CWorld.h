#pragma once

class CGameObject;



class CWorld
{
public:
	/* 구조체 설정 */
	struct CombatStats
	{
		uint32_t			iScore = 0;
		vector<uint32_t>	vecDeadID;
	};

public:
	CWorld();
	~CWorld();

public:
	void	Initialize();
	void	Update();
	void	LateUpdate();
	void	Render();

public:
	void	Set_Exit() { m_bExit = true; }
	bool	Get_Exit() { return m_bExit; }

private:
	/* 체력이 낮은 Enenmy 찾기 */
	unsigned int	FindLowestHpEnemy();
	/* ID로 검색 */
	CGameObject*	FindAliveID(unsigned int id);

private:
	vector<unique_ptr<CGameObject>> m_vecObject;
	uint32_t						m_iScore = 0;
	uint32_t						m_iPlayerID = 0;
	bool							m_bExit = false;

	CombatStats						m_CombatStats;
};

/* 함수 객체 */
struct DeathRecoder
{
	CWorld::CombatStats* pCombatStats = nullptr;

	explicit DeathRecoder(CWorld::CombatStats* pCombatStats)
		: pCombatStats(pCombatStats) { }

	void operator()(uint32_t iDeadID) const
	{
		if (nullptr == pCombatStats)
			return;

		pCombatStats->iScore += 100;
		pCombatStats->vecDeadID.push_back(iDeadID);
		cout << "============================================\n";
		cout << "처치 id : " << iDeadID << ", 점수 : " << pCombatStats->iScore << endl;
	}
};
