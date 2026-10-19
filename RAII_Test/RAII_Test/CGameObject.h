#pragma once

class CGameObject
{
public:
	 CGameObject();
	 virtual ~CGameObject();

public:
	virtual void	Initialize() abstract;
	virtual void	Update() abstract;
	virtual void	LateUpdate() abstract;
	virtual void	Render() abstract;

public:
	unsigned int	Get_ID() const { return m_uID; }

	void			Set_IsDead() { m_bIsDead = true; }
	bool			Get_IsDead() const { return m_bIsDead; }

	void			Set_Hp(int iHp) { m_iHp = iHp; }
	int				Get_Hp() const { return m_iHp; }

	void			Hit(int iDamage) { m_iHp -= iDamage; }

protected:
	static unsigned int s_uObjectID;
	unsigned int		m_uID;
	bool				m_bIsDead;
	int					m_iHp;
};

