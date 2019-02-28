#include"Animation.h"

Animation::Animation(Texture & t, int x, int y, int w, int h, float speed,int countFrames, int step)
{
	widhtRect = w;
	heightRect = h;
	this->speed = speed;
	currentFrame = 0;
	sprite.setTexture(t);
	isPlaying = true;
	isFlip = false;

	for (int i = 0; i < countFrames; i++)
	{
		frames.push_back(IntRect(x + i*step, y, w, h));
		flip_frames.push_back(IntRect(x + i*step + w, y, -w, h));
	}
}

void Animation::Update(float time)
{
	if (!isPlaying)
		return;

	currentFrame += speed * time;
	if (currentFrame > frames.size())
		currentFrame -= frames.size();

	int i = static_cast<int>(currentFrame);


	if (isFlip)
		sprite.setTextureRect(flip_frames[i]);
	else
		sprite.setTextureRect(frames[i]);
	
}

void Animation::SetFlip(bool val) { isFlip = val; }

void Animation::Play() { isPlaying = true; }

void Animation::Pause() { isPlaying = false; }

Sprite & Animation::GetSprite() { return sprite; }

int Animation::GetWidhtRect() { return widhtRect; }

int Animation::GetHeightRect() { return heightRect; }