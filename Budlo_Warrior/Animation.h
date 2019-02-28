#pragma once
#include<SFML\Graphics.hpp>
#include<iostream>
using namespace sf;
using std::vector;

class Animation
{
private:
	vector<IntRect> frames;
	vector<IntRect> flip_frames;
	float speed;
	float currentFrame = 0;
	bool isFlip;
	bool isPlaying;
	Sprite sprite;
	int widhtRect;
	int heightRect;
public:
	Animation() = default;
	Animation(Texture & t, int x, int y, int w, int h, float speed,int countFrames, int step);
	void Update(float time);
	void SetFlip(bool val);
	void Play();
	void Pause();
	Sprite & GetSprite();
	int GetWidhtRect();
	int GetHeightRect();
};