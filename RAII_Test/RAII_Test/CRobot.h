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
};

