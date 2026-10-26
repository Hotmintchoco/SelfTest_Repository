#include "pch.h"
#include "CRobot.h"

CRobot::CRobot()
{
	cout << "Robot 생성" << endl;
	m_eObjType = OBJTYPE::PLAYER;
}

CRobot::~CRobot()
{
	cout << "Robot 소멸" << endl;
}

void CRobot::Initialize()
{
}

void CRobot::Update()
{
	if (m_iHp <= 0)
		Set_IsDead();

	string strIsDead = m_bIsDead ? "True" : "False";

	cout << "[Update/Robot] ID : " << m_uID << " hp : " << m_iHp << " isDead : " << strIsDead << endl;
}

void CRobot::LateUpdate()
{
}

void CRobot::Render()
{
}
