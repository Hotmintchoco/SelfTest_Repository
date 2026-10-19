#include "pch.h"
#include "CEnemy.h"

CEnemy::CEnemy()
{
	cout << "Enemy 생성" << endl;
}

CEnemy::~CEnemy()
{
	cout << "Enemy 소멸" << endl;
}

void CEnemy::Initialize()
{
	m_iHp = 3;
}

void CEnemy::Update()
{
	if (m_iHp <= 0)
		Set_IsDead();
}

void CEnemy::LateUpdate()
{
}

void CEnemy::Render()
{
}
