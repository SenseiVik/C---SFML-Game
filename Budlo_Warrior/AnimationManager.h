#pragma once
#include"Animation.h"
#include<SFML\Graphics.hpp>
using namespace sf;
using std::map;

class AnimationManager
{
	String currentType;
	map<String, Animation> animList;
public:
	AnimationManager() = default;
	void Create(String type, Texture & t, int x, int y, int w, int h, float speed, int countFrames, int step);
	void SetType(String type);
	void SetFlipState(bool val);
	void Pause();
	void Play();
	void Update(float time);
	Sprite & GetSprite();
	int GetWidhtRect();
	int GetHeightRect();
	String GetType();
};