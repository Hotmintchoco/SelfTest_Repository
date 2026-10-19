#pragma once
#include "CGameObject.h"
class CEnemy : public CGameObject
{
public:
	CEnemy();
	virtual ~CEnemy();

public:
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render() override;
};

