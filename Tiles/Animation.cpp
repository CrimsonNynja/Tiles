#include "Animation.h"

Animation::Animation()
{
	std::cout << "Warning, no Object to attach to, Please Attach an owner with the 'setOwner' function" << std::endl;
}

Animation::Animation(sf::Sprite* Owner)
{
	this->Owner = Owner;
}

Animation::Animation(sf::Sprite* Owner, sf::Texture* SpriteSheet, int FrameWidth, int FrameHeight)
{
	this->Owner = Owner;
	this->LoadAnimation(SpriteSheet, FrameWidth, FrameHeight);
}

void Animation::setOwner(sf::Sprite* Owner)
{
	this->Owner = Owner;
}

void Animation::LoadAnimation(sf::Texture* SpriteSheet, int FrameWidth, int FrameHeight)
{
	if (SpriteSheet != Owner->getTexture())
	{
		Owner->setTexture(*SpriteSheet);
		frameHeight = FrameHeight;
		frameWidth = FrameWidth;

		int virtical = SpriteSheet->getSize().x / frameWidth;
		int horizontal = SpriteSheet->getSize().y / frameHeight;

		if (horizontal == 0)
		{
			horizontal = 1;
		}
		maxFrame = virtical * horizontal;

		int X = 0;
		int Y = 0;

		for (int i = 0; i < (virtical * horizontal); i++)
		{		
			AnimFrames.push_back(sf::IntRect(X, Y, (frameWidth), (frameHeight)));

			X = X + FrameWidth;
			if (X >= SpriteSheet->getSize().x)
			{
				Y = Y + frameHeight;
			}
		}

		currentFrame = 0;
		Owner->setTextureRect(AnimFrames[currentFrame]);
	}
}

void Animation::Stop()
{
	Pause(true);
	setFrame(0);
}

void Animation::Pause(bool bPaused)
{
	this->bPaused = bPaused;
}

void Animation::setAnimSpeed(float Speed)
{
	animSpeed = Speed;
}

void Animation::setFrame(int FrameNo)
{
	if (FrameNo < maxFrame - 1)
	{
		currentFrame = FrameNo;
		Owner->setTextureRect(AnimFrames[currentFrame]);
	}
}

bool Animation::IsPaused() const
{
	return bPaused;
}

int Animation::getCurrentFrame() const
{
	return currentFrame;
}

void Animation::Update()
{
	if (bPaused == false)
	{
		TimeElapsed = Timer.getElapsedTime();

		if (TimeElapsed.asMilliseconds() >= animSpeed)
		{
			if (currentFrame < maxFrame - 1)
			{
				currentFrame++;
			}
			else
			{
				currentFrame = 0;
			}

			Timer.restart();
			Owner->setTextureRect(AnimFrames[currentFrame]);
		}
	}
}
