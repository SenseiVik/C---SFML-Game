#include "Coin.h"
#include"Map.h"

Coin::Coin(float xS, float yS, Texture & t) : GameObject(xS, yS)
{
	coinAnimation.Create("stay", t, 13, 11, 30, 37, 0.01f, 6, 29);
	coinAnimation.GetSprite().setPosition(xSpawn, ySpawn);
}

void Coin::Control()
{
	return;
	speed = static_cast<float>(0.2);
}

void Coin::ColissionWithMap(float _Dx, float _Dy)
{
	for (int i = static_cast<int>(ySpawn / 32); i < (ySpawn + coinAnimation.GetHeightRect()) / 32; i++)
		for (int j = static_cast<int>(xSpawn / 32); j < (xSpawn + coinAnimation.GetWidhtRect()) / 32; j++)
			if (lvl_One[i][j] == 'S' || lvl_One[i][j] == 'g' || lvl_One[i][j] == 'G')
			{
				if (_Dy > 0)
				{
					Dy = 0;
					ySpawn = static_cast<float>(i * 32 - coinAnimation.GetHeightRect());
				}
				if (_Dy < 0)
				{
					Dy = 0;
					ySpawn = static_cast<float>(i * 32 + 32 + 1);
				}
			}
}

void Coin::Update(float time)
{
	coinAnimation.Update(time);
	ySpawn += Dy * time;
	ColissionWithMap(0, Dy);
	coinAnimation.GetSprite().setPosition(xSpawn, ySpawn);
	Dy += static_cast<float>(0.0007) * time;
}

Sprite & Coin::GetSprite()
{
	return coinAnimation.GetSprite();
}

/*IntRect*/FloatRect Coin::GetRect()
{
	return FloatRect(xSpawn, ySpawn, coinAnimation.GetWidhtRect(), coinAnimation.GetHeightRect());
}

int Coin::GetWidhtRect() { return coinAnimation.GetWidhtRect(); }

int Coin::GetHeightRect() { return coinAnimation.GetHeightRect(); }