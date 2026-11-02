#include "pch.h"
#include "CGameObject.h"

unsigned int CGameObject::s_uObjectID = 0;

CGameObject::CGameObject() : m_uID(s_uObjectID), m_bIsDead(false), m_iHp(0)
{
	cout << "GameObject 생성 / id : " << m_uID << endl;
	s_uObjectID++;
}

CGameObject::~CGameObject()
{
	cout << "GameObject 소멸 / id : " << m_uID << endl;
}

void CGameObject::Hit(int iDamage)
{
	if (Get_IsDead())
	{
		cout << "id : " << m_uID << " 사망 상태 / Hit 불가\n";
		return;
	}

	m_iHp -= iDamage;

	if (m_iHp <= 0)
		Set_IsDead();
}


