#include"Stone.h"
#include"Map.h"

Stone::Stone(float xS, float yS, Texture & t, int direction) :GameObject(xS, yS)
{
	this->direction = direction;
	isAlive = false;
	health = 20;
	damage = 1000;
	stoneAnimation.Create("update", t, 5, 5, 71, 60, 0.005f, 5, 71);
}

void Stone::Control()
{
	speed = static_cast<float>(0.6);
}

void Stone::ColissionWithMap(float _Dx, float _Dy)
{
	for (int i = static_cast<int>(ySpawn / 32); i < (ySpawn + stoneAnimation.GetHeightRect()) / 32; i++)
		for (int j = static_cast<int>(xSpawn / 32); j < (xSpawn + stoneAnimation.GetWidhtRect()) / 32; j++)
		{
			if (lvl_One[i][j] == 'S' || lvl_One[i][j] == 'g' || lvl_One[i][j] == 'G' || lvl_One[i][j] == 't' || lvl_One[i][j] == 'T')
			{
				if (_Dx > 0)
				{
					Dx = 0;
					xSpawn = static_cast<float>(j * 32 - stoneAnimation.GetWidhtRect());
					isAlive = false;
				}

				if (_Dx < 0)
				{
					Dx = 0;
					xSpawn = static_cast<float>(j * 32 + 32);
				}

				if (_Dy > 0)
				{
					Dy = 0;
					ySpawn = static_cast<float>(i * 32 - stoneAnimation.GetHeightRect());
					onGround = true;

				}

				if (_Dy < 0)
				{
					Dy = 0;
					ySpawn = static_cast<float>(i * 32 + 32);
				}

			}

		}
}

void Stone::Update(float time)
{
	if (isAlive)
	{
		Control();
		stoneAnimation.Update(time);

		switch (direction)
		{
		case 1: //left
			Dx = -speed;
			break;
		case 2: //right
			Dx = speed;
			break;
		default:
			break;
		}
		
		xSpawn += Dx * time;
		ColissionWithMap(Dx, 0);
		ySpawn += Dy * time;
		ColissionWithMap(0, Dy);
		stoneAnimation.GetSprite().setPosition(xSpawn, ySpawn);

		Dy += static_cast<float>(0.0007) * time;
	}
}

Sprite & Stone::GetSprite()
{
	return stoneAnimation.GetSprite();
}

int Stone::GetWidhtRect()
{
	return stoneAnimation.GetWidhtRect();
}

int Stone::GetHeightRect()
{
	return stoneAnimation.GetHeightRect();
}

FloatRect Stone::GetRect()
{
	return FloatRect(xSpawn, ySpawn, stoneAnimation.GetWidhtRect(), stoneAnimation.GetHeightRect());
}

void Stone::TakeDamage(int damage)
{
	health -= damage;
}