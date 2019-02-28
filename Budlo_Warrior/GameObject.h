#pragma once
#include<SFML\Graphics.hpp>
using namespace sf;

class GameObject
{
protected:
	float xSpawn;
	float ySpawn;
	float Dx;
	float Dy;
	float speed;
	bool isAlive;
	bool onGround;
	bool isAttack;
	int health;
	int damage;
public:
	GameObject(float xS, float yS);
	virtual void Control() = 0;
	virtual void ColissionWithMap(float _Dx,float _Dy) = 0;
	virtual void Update(float time) = 0;
	virtual Sprite & GetSprite() = 0;
	virtual int GetWidhtRect() = 0;
	virtual int GetHeightRect() = 0;
	virtual FloatRect GetRect() = 0;
	virtual void TakeDamage(int damage);

	void	SetIsAlive(bool status);
	void	SetHealth(int value);
	void	SetDamage(int value);
	void	SetSpawn(int x, int y);
	void	SetAttack(bool val);


	int		GetDamage();
	int		GetHealth();
	float	GetSpawnX();
	float	GetSpawnY();
	bool	GetIsAlive();
	bool	GetIsAttack();
};