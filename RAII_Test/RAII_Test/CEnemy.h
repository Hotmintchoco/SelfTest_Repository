#pragma once
#include "CGameObject.h"

using DeathCallback = std::function<void(uint32_t)>;

class CEnemy : public CGameObject
{
public:
	CEnemy();
	virtual ~CEnemy();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

	virtual void Set_IsDead() override; 

public:
	void SetDeathCallback(DeathCallback callback);

private:
	DeathCallback m_OnDeath;
};

