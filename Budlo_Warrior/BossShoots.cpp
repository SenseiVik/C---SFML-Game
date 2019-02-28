#include"BossShoots.h"
#include"Map.h"

BossShoots::BossShoots(float xS, float yS, Texture & t, int direction) :GameObject(xS, yS)
{
	this->direction = direction;
	verticalShoot = false;
	health = 1;
	damage = 100;
	bossShootAnimation.Create("shoot", t, 48, 515, 186, 53, 0.005, 1, 0);
	bossShootAnimation.Create("snaryad", t, 846, 30, 31, 145, 0.005, 1, 0);
	bossShootAnimation.GetSprite().setPosition(xSpawn, ySpawn);
	bossShootAnimation.SetType("shoot");
}

void BossShoots::Control()
{
	if (direction == 2)
	{
		bossShootAnimation.SetFlipState(true);
	}
	if (direction == 1)
	{
		bossShootAnimation.SetFlipState(false);
	}

	speed = static_cast<float>(0.32);
	
}

void BossShoots::ColissionWithMap(float _Dx, float _Dy)
{
	for (int i = static_cast<int>(ySpawn / 32); i < (ySpawn + bossShootAnimation.GetHeightRect()) / 32; i++)
		for (int j = static_cast<int>(xSpawn / 32); j < (xSpawn + bossShootAnimation.GetWidhtRect()) / 32; j++)
			if (lvl_One[i][j] == 'S' || lvl_One[i][j] == 'g' || lvl_One[i][j] == 'G')
			{
				if (_Dx > 0)
				{
					Dx = 0;
					xSpawn = static_cast<float>(j * 32 - bossShootAnimation.GetWidhtRect() - 1);
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

void BossShoots::Update(float time)
{
	if (isAlive)
	{
		Control();
		bossShootAnimation.Update(time);
		switch (direction)
		{
		case 1://left
			if (!verticalShoot)
				Dx = -speed;
			else
				Dy = -speed;
			break;
		case 2://right
			if (!verticalShoot)
				Dx = speed;
			else
				Dy = speed;
			break;
		default:
			break;
		}
		
		xSpawn += Dx * time;
		ColissionWithMap(Dx, 0);
		
		bossShootAnimation.GetSprite().setPosition(xSpawn, ySpawn);
	}
}

Sprite & BossShoots::GetSprite() { return bossShootAnimation.GetSprite(); }

FloatRect BossShoots::GetRect() { return FloatRect(xSpawn, ySpawn, bossShootAnimation.GetWidhtRect(), bossShootAnimation.GetHeightRect()); }

int BossShoots::GetWidhtRect() { return bossShootAnimation.GetWidhtRect(); }

int BossShoots::GetHeightRect() { return bossShootAnimation.GetHeightRect(); }

bool BossShoots::GetVerticalShootState()
{
	return verticalShoot;
}

void BossShoots::SetVerticalShootState(bool val)
{
	verticalShoot = val;
}