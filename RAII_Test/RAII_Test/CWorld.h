#pragma once

class CGameObject;

class CWorld
{
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
	unsigned int					m_iPlayerID = 0;
	bool							m_bExit = false;
};

