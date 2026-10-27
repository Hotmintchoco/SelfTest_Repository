#include "pch.h"
#include "CEnemy.h"

CEnemy::CEnemy()
{
	cout << "Enemy 생성" << endl;
	m_eObjType = OBJTYPE::ENEMY;
}

CEnemy::~CEnemy()
{
	cout << "Enemy 소멸" << endl;
}

void CEnemy::Initialize()
{
}

void CEnemy::Update()
{
	string strIsDead = m_bIsDead ? "True" : "False";

	cout << "[Update/Enemy] ID : " << m_uID << " hp : " << m_iHp << " isDead : " << strIsDead << endl;
	
}

void CEnemy::LateUpdate()
{
}

void CEnemy::Render()
{
}
