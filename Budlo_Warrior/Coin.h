#pragma once
#include<SFML\Graphics.hpp>
#include "GameObject.h"
#include "AnimationManager.h"

using namespace sf;

class Coin : public GameObject
{
	AnimationManager coinAnimation;
public:
	Coin(float xS, float yS, Texture & t);

	virtual void Control()override;
	virtual void ColissionWithMap(float _Dx, float _Dy)override;
	virtual void Update(float time)override;
	virtual Sprite & GetSprite()override;
	virtual /*IntRect*/FloatRect GetRect()override;
	virtual int GetWidhtRect()override;
	virtual int GetHeightRect()override;
};

