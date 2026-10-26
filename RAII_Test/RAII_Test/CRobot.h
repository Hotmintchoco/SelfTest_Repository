#pragma once
#include "CGameObject.h"

class CRobot : public CGameObject
{
public:
	CRobot();
	virtual ~CRobot();

	void	Initialize() override;
	void	Update() override;
	void	LateUpdate() override;
	void	Render() override;

public:
	bool	Attack(CGameObject* pTarget);

private:
	int		m_iDamage;
};

