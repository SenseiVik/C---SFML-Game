#include"Player.h"

Player::Player(float xS, float yS,Texture & t) :GameObject(xS, yS)
{
	health = 300;
	damage = 10;
	XRay = false;
	fly = false;
	playerAnimation.Create("stay", t, 2, 7, 55, 60, 0.008, 8, 55);
	playerAnimation.Create("run", t, 2, 85, 55, 60, 0.012, 8, 54);
	playerAnimation.Create("jump", t, 110, 85, 55, 60, 0.003, 2, 55);
	playerAnimation.Create("shoot", t, 292, 319, 74, 60, 0.006, 2, 75);
	playerAnimation.GetSprite().setPosition(xSpawn, ySpawn);
}

void Player::Control()
{
	if (countCoins >= 30)
		damage = 50;

	if (onGround)
		playerAnimation.SetType("stay");
	else
		playerAnimation.SetType("jump");

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		if (fly)
			speed = static_cast<float>(0.4);
		else
			speed = static_cast<float>(0.2);
		playerState = right;
		playerAnimation.SetFlipState(false);

		if (onGround)
			playerAnimation.SetType("run");
	}

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		if (fly)
			speed = static_cast<float>(0.4);
		else
			speed = static_cast<float>(0.2);
		playerState = left;
		playerAnimation.SetFlipState(true);

		if (onGround)
			playerAnimation.SetType("run");
	}

	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		isAttack = true;
		playerAnimation.SetType("shoot");
	}

	if (Keyboard::isKeyPressed(Keyboard::Up) && onGround == true)
	{
		Dy = static_cast<float>(-0.4);
		playerAnimation.SetType("jump");
		onGround = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down) && onGround == false)
	{
		Dy = static_cast<float>(0.7);
	}
	if (Keyboard::isKeyPressed(Keyboard::R))
	{
		XRay = true;
	}
	
	
}

void Player::Update(float time)
{
	if (isAlive)
	{
		Control();
		playerAnimation.Update(time);

		switch (playerState)
		{
		case left:
			Dx = -speed;
			break;
		case right:
			Dx = speed;
			break;
		}

		xSpawn += Dx * time;
		ColissionWithMap(Dx, 0);
		ySpawn += Dy * time;
		ColissionWithMap(0, Dy);
		speed = 0;

		if (health <= 0)
			isAlive = false;

		playerAnimation.GetSprite().setPosition(xSpawn, ySpawn);

		if (!fly)
			Dy += static_cast<float>(0.0007) * time;
	}
}

Sprite & Player::GetSprite()
{
	return playerAnimation.GetSprite();
}

void Player::ColissionWithMap(float _Dx,float _Dy)
{
	for (int i = static_cast<int>(ySpawn / 32); i < (ySpawn + playerAnimation.GetHeightRect())/32;i++)
		for (int j = static_cast<int>(xSpawn / 32); j < (xSpawn + playerAnimation.GetWidhtRect()) / 32; j++)
		{
			if (lvl_One[i][j] == 'S' || lvl_One[i][j] == 'G' || lvl_One[i][j] == 'g')
			{
				if (_Dx > 0)
				{
					Dx = 0;
					xSpawn = static_cast<float>(j * 32 - playerAnimation.GetWidhtRect());
				}

				if (_Dx < 0)
				{
					Dx = 0;
					xSpawn = static_cast<float>(j * 32 + 32);
				}

				if (_Dy > 0)
				{
					Dy = 0;
					ySpawn = static_cast<float>(i * 32 - playerAnimation.GetHeightRect());
					onGround = true;
				}

				if (_Dy < 0)
				{
					Dy = 0;
					ySpawn = static_cast<float>(i * 32 + 32);
				}

			}
			if (lvl_One[i][j] == 'W' || lvl_One[i][j] == 'L')
				isAlive = false;
			
		}

}

FloatRect Player::GetRect()
{
	return FloatRect(xSpawn, ySpawn, playerAnimation.GetWidhtRect(), playerAnimation.GetHeightRect());
}

void Player::AddCoin() { countCoins++; }

int Player::GetCountCoins() { return countCoins; }

int Player::GetStatus() { return playerState; }

int Player::GetWidhtRect() { return playerAnimation.GetWidhtRect(); }

int Player::GetHeightRect() { return playerAnimation.GetHeightRect(); }

void Player::TakeDamage(int damage)
{
	health -= damage;
}

bool Player::GetOnGroundState()
{
	return onGround;
}

bool Player::GetXRayState()
{
	return XRay;
}

void Player::SetXRayState(bool val)
{
	XRay = val;
}

String Player::GetAnimType()
{
	return playerAnimation.GetType();
}

void Player::SetCountCoins(int count)
{
	countCoins = count;
}

int Player::GetCountSalve()
{
	return countSalve;
}

void Player::AddSalve()
{
	++countSalve;
}

void Player::SubmSalve()
{
	--countSalve;
}

void Player::SetFly(bool val)
{
	fly = val;
}

bool Player::GetFly()
{
	return fly;
}