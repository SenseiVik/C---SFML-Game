#include"Boss.h"
#include"Map.h"

Boss::Boss(float xS, float yS, Texture & t) :GameObject(xS, yS)
{
	health = 5000;
	damage = 15;
	direction = 1;
	countDamage = 0;
	LowHp = false;
	secondFaza = false;
	comeback = false;
	bubble = false;
	countBubble = 0;
	bossAnimation.Create("stay", t, 0, 104, 121, 112, 0.008f, 4, 121);
	bossAnimation.SetFlipState(true);
	isAttack = true;
}

void Boss::Control()
{
	speed = static_cast<float>(0.2);
	if (health <= 4000)
		secondFaza = true;
}

void Boss::ColissionWithMap(float _Dx, float _Dy)
{
	for (int i = static_cast<int>(ySpawn / 32); i < (ySpawn + bossAnimation.GetHeightRect()) / 32; i++)
		for (int j = static_cast<int>(xSpawn / 32); j < (xSpawn + bossAnimation.GetWidhtRect()) / 32; j++)
			if (lvl_One[i][j] == 'S' || lvl_One[i][j] == 't' || lvl_One[i][j] == 'T' || lvl_One[i][j] == 'g')
			{
				if (_Dx > 0)
				{
					Dx = 0;
					xSpawn = static_cast<float>(j * 32 - bossAnimation.GetWidhtRect() - 1);
					direction = 2;
					comeback = true;
				}
				if (_Dx < 0)
				{
					Dx = 0;
					xSpawn = static_cast<float>(j * 32 + 32 + 1);
					direction = 1;
				}
				if (_Dy > 0)
				{
					Dy = 0;
					ySpawn = static_cast<float>(i * 32 - bossAnimation.GetHeightRect());
					onGround = true;
					direction = 2;
				}
				if (_Dy < 0)
				{
					Dy = 0;
					ySpawn = static_cast<float>(i * 32 + 32 + 1);
					direction = 1;
				}

			}

}

void Boss::Update(float time)
{
	if (health <= 0)
		isAlive = false;

	if (isAlive)
	{
		Control();
		bossAnimation.Update(time);
		switch (direction)
		{
		case 0:
			break;
		case 1:
			
			if (countDamage >= 15)
			{
				if (!secondFaza)
				{
					speed = static_cast<float>(0.6);
					Dx = -speed;
					countDamage = 0;
					comeback = true;
					isAttack = false;
				}
				else
				{
					if (countBubble < 2 && bubble == false)
					{
						bubble = true;
						Dx = 0;
						Dy += speed;
						countDamage = 0;
						countBubble++;
					}
					else if (countDamage >= 15 && bubble == true)
					{
						bubble = false;
						countDamage = 0;
					}
					else if (bubble == false)
					{
						speed = static_cast<float>(0.6);
						Dx = -speed;
						countDamage = 0;
						comeback = true;
						isAttack = false;
					}
				}
			}
			if(!bubble)
				Dy = speed;
			break;
		case 2:
			if (comeback)
			{
				speed = static_cast<float>(0.2);
				Dx = speed;
				comeback = false;
				isAttack = true;
			}
			Dy = -speed;
			break;
		default:
			break;
		}

		if (bubble)
		{
			health += 1;
			Dy += static_cast<float>(0.0007) * time;
		}

		if (!bubble)
		{
			xSpawn += Dx * time;
			ColissionWithMap(Dx, 0);
			ySpawn += Dy * time;
			ColissionWithMap(0, Dy);
			bossAnimation.GetSprite().setPosition(xSpawn, ySpawn);
		}
		else
		{
			ColissionWithMap(Dy, 0);
			bossAnimation.GetSprite().setPosition(xSpawn, ySpawn);
		}
	}

}

Sprite & Boss::GetSprite()
{
	return bossAnimation.GetSprite();
}

int Boss::GetWidhtRect()
{
	return bossAnimation.GetWidhtRect();
}

int Boss::GetHeightRect()
{
	return bossAnimation.GetHeightRect();
}

FloatRect Boss::GetRect()
{
	return FloatRect(xSpawn, ySpawn, bossAnimation.GetWidhtRect(), bossAnimation.GetHeightRect());
}

void Boss::TakeDamage(int damage)
{
	if(!bubble)
		health -= damage;
}

void Boss::SetDirection(int direction)
{
	this->direction = direction;
}

void Boss::GiveJump()
{
	Dy = static_cast<float>(-0.4);
}

int Boss::GetStatus()
{
	return direction;
}

int Boss::GetHealth()
{
	return health;
}

void Boss::AddCountDamage()
{
	countDamage++;
}

bool Boss::GetSecondFazaState()
{
	return secondFaza;
}

bool Boss::GetBubbleState()
{
	return bubble;
}