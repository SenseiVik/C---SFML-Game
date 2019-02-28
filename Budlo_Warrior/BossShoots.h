#pragma once
#include"GameObject.h"
#include"AnimationManager.h"

class BossShoots :public GameObject
{
	AnimationManager bossShootAnimation;
	int direction;
	bool verticalShoot;
public:
	BossShoots(float xS, float yS, Texture & t, int direction);
	virtual void Control()override;
	virtual void ColissionWithMap(float _Dx, float _Dy)override;
	virtual void Update(float time)override;
	virtual Sprite & GetSprite()override;
	virtual FloatRect GetRect()override;
	virtual int GetWidhtRect()override;
	virtual int GetHeightRect()override;

	bool GetVerticalShootState();
	void SetVerticalShootState(bool val);
};