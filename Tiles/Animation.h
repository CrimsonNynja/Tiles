#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Animation
{
public:
	Animation();
	Animation(sf::Sprite* Owner);
	Animation(sf::Sprite* Owner, sf::Texture* SpriteSheet, int FrameWidth, int FrameHeight);
	void setOwner(sf::Sprite* Owner);
	void LoadAnimation(sf::Texture* SpriteSHeet, int FrameWidth, int FrameHeight);
	void Stop();
	void Pause(bool bPaused);
	void setAnimSpeed(float Speed);	//in milliseconds
	void setFrame(int FrameNo);
	bool IsPaused() const;
	int getCurrentFrame() const;
	void Update();

	/*
	TODO
	add a play in reverse option
	add option to not loop
	*/

private:
	sf::Sprite* Owner;
	sf::Texture* AnimationSheet;

	std::vector<sf::IntRect> AnimFrames;
	int frameHeight;
	int frameWidth;

	sf::Clock Timer;
	sf::Time TimeElapsed;
	float animSpeed = 200;

	int currentFrame = 0;
	int maxFrame = 0;
	bool bIsLooping = true;
	bool bPaused = false;
	bool bIsForwards = true;

};