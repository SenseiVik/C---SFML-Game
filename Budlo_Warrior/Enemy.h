#pragma once
#include"GameObject.h"
#include"AnimationManager.h"


class Enemy :public GameObject
{
	int direction;
	bool LowHp;
	AnimationManager enemyAnimation;
public:
	Enemy(float xS,float  yS, Texture & t);
	virtual void Control()override;
	virtual void ColissionWithMap(float _Dx, float _Dy);
	virtual void Update(float time)override;
	virtual Sprite & GetSprite()override;
	virtual /*IntRect*/FloatRect GetRect()override;
	virtual int GetWidhtRect()override;
	virtual int GetHeightRect()override;

	void SetDirection(int direction);
	void GiveJump();
};