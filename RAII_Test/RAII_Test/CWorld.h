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
	vector<unique_ptr<CGameObject>> m_vecObject;
	bool							m_bExit = false;
};

