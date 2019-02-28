#include"GameObject.h"

GameObject::GameObject(float xS, float yS)
{
	xSpawn = xS;
	ySpawn = yS;
	Dx = 0;
	Dy = 0;
	speed = 0;
	isAlive = true;
	onGround = false;
	isAttack = false;
}

void GameObject::SetIsAlive(bool status)
{
	isAlive = status;
}

void GameObject::SetHealth(int value)
{
	health = value;
}

void GameObject::SetDamage(int value)
{
	damage = value;
}

void GameObject::SetSpawn(int x, int y)
{
	xSpawn = x;
	ySpawn = y;
}

int GameObject::GetDamage()
{
	return damage;
}

int GameObject::GetHealth()
{
	return health;
}

float GameObject::GetSpawnX()
{
	return xSpawn;
}

float GameObject::GetSpawnY()
{
	return ySpawn;
}

bool GameObject::GetIsAlive()
{
	return isAlive;
}

bool GameObject::GetIsAttack()
{
	return isAttack;
}


void GameObject::SetAttack(bool val)
{
	isAttack = val;
}

void GameObject::TakeDamage(int damage)
{
	health -= damage;
}