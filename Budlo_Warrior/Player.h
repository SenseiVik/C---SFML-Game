#pragma once
#include"GameObject.h"
#include"AnimationManager.h"
#include"Map.h"


class Player :public GameObject
{
	int countCoins = 0;
	int countSalve = 0;
	AnimationManager playerAnimation;
	enum StateObject{stay,left,right,jump,down,run};
	StateObject playerState;
	bool XRay;
	bool fly;
public:
	Player(float xS, float yS,Texture & t);
	virtual void Control()override;
	virtual void ColissionWithMap(float _Dx,float _Dy)override;
	virtual void Update(float time)override;
	virtual Sprite & GetSprite()override;
	virtual FloatRect GetRect()override;
	virtual int GetWidhtRect()override;
	virtual int GetHeightRect()override;
	virtual void TakeDamage(int damage)override;

	void	AddCoin();
	int		GetCountCoins();
	void	SetCountCoins(int count);
	int		GetStatus();
	bool	GetOnGroundState();
	bool	GetXRayState();
	void	SetXRayState(bool val);
	int		GetCountSalve();
	void	AddSalve();
	void	SubmSalve();
	void	SetFly(bool val);
	bool	GetFly();
	String	GetAnimType();
};