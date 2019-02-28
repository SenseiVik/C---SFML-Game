#include"Shoot.h"
#include"Map.h"

Shoot::Shoot(float xS, float yS, Texture & t,int direction) :GameObject(xS, yS)
{
	this->direction = direction;
	health = 1;
	damage = 35;
	shootAnimation.Create("shoot", t, 0, 0, 75, 25, 0.005, 1, 0);
	shootAnimation.GetSprite().setPosition(xSpawn, ySpawn);
}

Shoot::Shoot(float xS, float yS, Texture & t, int direction, bool xRay) :GameObject(xS, yS)
{
	this->direction = direction;
	health = 1;
	damage = 100;
	shootAnimation.Create("xray", t, 10, 40, 231, 30, 0.005, 1, 0);
	shootAnimation.GetSprite().setPosition(xSpawn, ySpawn);
}

void Shoot::Control()
{
	if (shootAnimation.GetType() == "shoot")
		speed = static_cast<float>(0.5);
	else
		speed = 0;
}

void Shoot::ColissionWithMap(float _Dx, float _Dy)
{
	for (int i = static_cast<int>(ySpawn / 32); i < (ySpawn + shootAnimation.GetHeightRect()) / 32; i++)
		for (int j = static_cast<int>(xSpawn / 32); j < (xSpawn + shootAnimation.GetWidhtRect()) / 32; j++)
			if (lvl_One[i][j] == 'S' || lvl_One[i][j] == 'G' || lvl_One[i][j] == 'g')
			{
				if (_Dx > 0)
				{
					Dx = 0;
					xSpawn = static_cast<float>(j * 32 - shootAnimation.GetWidhtRect() - 1);
					isAlive = false;
				}
				if (_Dx < 0)
				{
					Dx = 0;
					xSpawn = static_cast<float>(j * 32 + 32 + 1);
					isAlive = false;
				}

			}
}

void Shoot::Update(float time)
{
	if (shootAnimation.GetType() == "shoot")
	{
		if (isAlive)
		{
			Control();
			shootAnimation.Update(time);
			switch (direction)
			{
			case 1://left
				Dx = -speed;
				break;
			case 2://right
				Dx = speed;
				break;
			default:
				break;
			}

			xSpawn += Dx * time;
			ColissionWithMap(Dx, 0);
			shootAnimation.GetSprite().setPosition(xSpawn, ySpawn);
		}
	}
	else
	{
		if (isAlive)
		{
			Control();
			shootAnimation.Update(time);
			switch (direction)
			{
			case 1://left
				shootAnimation.SetFlipState(true);
				Dx = -speed;
				break;
			case 2://right
				shootAnimation.SetFlipState(false);
				Dx = speed;
				break;
			default:
				break;
			}

			xSpawn += Dx * time;
			ColissionWithMap(Dx, 0);
			shootAnimation.GetSprite().setPosition(xSpawn, ySpawn);
			//isAlive = false;
		}
	}
}

Sprite & Shoot::GetSprite() { return shootAnimation.GetSprite(); }

FloatRect Shoot::GetRect() { return FloatRect(xSpawn, ySpawn, shootAnimation.GetWidhtRect(), shootAnimation.GetHeightRect()); }

int Shoot::GetWidhtRect() { return shootAnimation.GetWidhtRect(); }

int Shoot::GetHeightRect() { return shootAnimation.GetHeightRect(); }