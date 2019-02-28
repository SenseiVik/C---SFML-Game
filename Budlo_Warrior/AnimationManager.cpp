#include"AnimationManager.h"

void AnimationManager::Create(String type, Texture & t, int x, int y, int w, int h, float speed, int countFrames, int step)
{
	animList[type] = Animation(t, x, y, w, h, speed, countFrames, step);
	currentType = type;
}

void AnimationManager::SetType(String type) { currentType = type; }

void AnimationManager::SetFlipState(bool val)
{
	for (auto & currentAnim : animList)
		currentAnim.second.SetFlip(val);
}

void AnimationManager::Pause()
{
	animList[currentType].Pause();
}

void AnimationManager::Play()
{
	animList[currentType].Play();
}

void AnimationManager::Update(float time)
{
	animList[currentType].Update(time);
}

Sprite & AnimationManager::GetSprite()
{
	return animList[currentType].GetSprite();
}

int AnimationManager::GetWidhtRect()
{
	return animList[currentType].GetWidhtRect();
}

int AnimationManager::GetHeightRect()
{
	return animList[currentType].GetHeightRect();
}

String AnimationManager::GetType()
{
	return currentType;
}
