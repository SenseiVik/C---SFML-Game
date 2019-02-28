#pragma once
#include"GameObject.h"
#include"AnimationManager.h"

class Shoot :public GameObject
{
	AnimationManager shootAnimation;
	int direction;
public:
	Shoot(float xS, float yS, Texture & t,int direction);
	Shoot(float xS, float yS, Texture & t, int direction, bool xRay);
	virtual void Control()override;
	virtual void ColissionWithMap(float _Dx, float _Dy)override;
	virtual void Update(float time)override;
	virtual Sprite & GetSprite()override;
	virtual FloatRect GetRect()override;
	virtual int GetWidhtRect()override;
	virtual int GetHeightRect()override;
};