#pragma once
#include"GameObject.h"
#include"AnimationManager.h"

class Boss :public GameObject
{
	int direction;
	bool LowHp;
	bool secondFaza;
	bool comeback;
	bool bubble;
	int countDamage;
	int countBubble;
	AnimationManager bossAnimation;
public:
	Boss(float xS, float yS, Texture & t);
	virtual void Control()override;
	virtual void ColissionWithMap(float _Dx, float _Dy)override;
	virtual void Update(float time)override;
	virtual Sprite & GetSprite()override;
	virtual int GetWidhtRect()override;
	virtual int GetHeightRect()override;
	virtual FloatRect GetRect()override;
	virtual void TakeDamage(int damage)override;

	void SetDirection(int direction);
	void GiveJump();
	int GetStatus();
	int GetHealth();
	void AddCountDamage();
	bool GetSecondFazaState();
	bool GetBubbleState();
};