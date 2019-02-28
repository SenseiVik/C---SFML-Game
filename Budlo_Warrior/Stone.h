#pragma once
#include"GameObject.h"
#include"AnimationManager.h"

class Stone:public GameObject
{
	AnimationManager stoneAnimation;
	int direction;
public:
	Stone(float xS, float yS, Texture & t, int direction);
	virtual void Control()override;
	virtual void ColissionWithMap(float _Dx, float _Dy)override;
	virtual void Update(float time)override;
	virtual Sprite & GetSprite()override;
	virtual int GetWidhtRect()override;
	virtual int GetHeightRect()override;
	virtual FloatRect GetRect()override;
	virtual void TakeDamage(int damage)override;
};