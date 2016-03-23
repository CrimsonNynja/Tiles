#pragma once

#include <vector>
#include "GameSprite.h"

//test
#include <math.h>
#include <time.h>

class ParticleEmitter// : public GameSprite
{
public:
	ParticleEmitter();
	ParticleEmitter(int maxParticles, int minParticles, float particleDistance, float speed);

	void AddParticleImage(sf::Texture* tex);
	void AddParticleImage(sf::Texture* tex, int width, int height);
	sf::Texture* getParticleImage();

	void Stop();
	void Start();
	void setPosition(float x, float y);
	void Draw(sf::RenderWindow& window);		//may make return teh vector of game sprites
	void Update();

private:
	float DistanceBetweenPoints(float x1, float y1, float x2, float y2);

	std::vector<GameSprite> Particles;

	float x = 500;
	float y = 500;

	int maxParticles;
	int minParticles;
	float particleDistance;
	float speed;

	bool bStopped = false;
};