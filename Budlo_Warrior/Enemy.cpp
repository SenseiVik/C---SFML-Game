#include"Enemy.h"
#include"Map.h"

Enemy::Enemy(float xS, float yS, Texture & t) :GameObject(xS, yS)
{
	direction = 0;
	health = 100;
	damage = 10;
	LowHp = false;
	enemyAnimation.Create("stay", t, 5, 0, 42, 62, 0.008f, 8, 43);
	enemyAnimation.Create("run", t, 418, 0, 55, 60, 0.012f, 8, 54);
	//enemyAnimation.Create("jump");
}

void Enemy::Control()
{
	if (direction == 0)
		enemyAnimation.SetType("stay");
	if (direction == 1)
	{
		enemyAnimation.SetFlipState(true);
		enemyAnimation.SetType("run");
	}
	if (direction == 2)

	{
		enemyAnimation.SetFlipState(false);
		enemyAnimation.SetType("run");
	}
	if (direction == 3 && onGround == true)
	{
		Dy = static_cast<float>(-0.5);
		onGround = false;
	}

	if (health <= 30)
		LowHp = true;
	if (LowHp)
		speed = static_cast<float>(0.4);
	else
		speed = static_cast<float>(0.18);
}

void Enemy::ColissionWithMap(float _Dx, float _Dy)
{
	for (int i = static_cast<int>(ySpawn / 32); i < (ySpawn + enemyAnimation.GetHeightRect()) / 32; i++)
	{
		for (int j = static_cast<int>(xSpawn / 32); j < (xSpawn + enemyAnimation.GetWidhtRect()) / 32; j++)
		{
			if (lvl_One[i][j] == 'S' || lvl_One[i][j] == 'G' || lvl_One[i][j] == 'g' || lvl_One[i][j] == 'T')
			{
				if (_Dx > 0)
				{
					Dx = 0;
					xSpawn = static_cast<float>(j * 32 - enemyAnimation.GetWidhtRect() - 1);
					direction = 0;
				}
				if (_Dx < 0)
				{
					Dx = 0;
					xSpawn = static_cast<float>(j * 32 + 32 + 1);
					direction = 0;
				}
				if (_Dy > 0)
				{
					Dy = 0;
					ySpawn = static_cast<float>(i * 32 - enemyAnimation.GetHeightRect());
					direction = 0;
					onGround = true;
				}
				if (_Dy < 0)
				{
					Dy = 0;
					ySpawn = static_cast<float>(i * 32 + 32 + 1);
				}

			}
			if (lvl_One[i][j] == 'W' || lvl_One[i][j] == 'L')
				isAlive = false;
		}
	}
}

void Enemy::Update(float time)
{
	if (isAlive)
	{
		Control();
		enemyAnimation.Update(time);

		switch (direction)
		{
		case 0:
			Dx = 0;
			break;
		case 1:
			Dx = -speed;
			break;
		case 2:
			Dx = speed;
			break;
		case 3:
			break;
		}

		xSpawn += Dx * time;
		ColissionWithMap(Dx, 0);
		ySpawn += Dy * time;
		ColissionWithMap(0, Dy);
		speed = 0;

		if (health <= 0)
			isAlive = false;

		enemyAnimation.GetSprite().setPosition(xSpawn, ySpawn);
		Dy += static_cast<float>(0.0007) * time;
	}
}

void Enemy::SetDirection(int direction) { this->direction = direction; }

Sprite & Enemy::GetSprite() { return enemyAnimation.GetSprite(); }

/*IntRect*/FloatRect Enemy::GetRect() { return FloatRect(xSpawn, ySpawn, enemyAnimation.GetWidhtRect(), enemyAnimation.GetHeightRect()); }

int Enemy::GetWidhtRect() { return enemyAnimation.GetWidhtRect(); }

int Enemy::GetHeightRect() { return enemyAnimation.GetHeightRect(); }

void Enemy::GiveJump()
{
	direction = 3;
}
