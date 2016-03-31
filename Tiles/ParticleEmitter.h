#pragma once

#include <vector>
#include "GameSprite.h"

//test
#include <math.h>
#include <time.h>

class ParticleEmitter : public sf::Drawable
{
public:
	ParticleEmitter();
	ParticleEmitter(int maxParticles, int minParticles, float particleDistance, float speed);

	void AddParticleImage(sf::Texture* tex);
	void AddParticleImage(sf::Texture* tex, int width, int height);
	void setParticleDrawLayer(int Layer);
	sf::Texture* getParticleImage();

	void Stop();
	void Start();
	void setPosition(float x, float y);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void Update();

private:
	float DistanceBetweenPoints(float x1, float y1, float x2, float y2);

	std::vector<GameSprite> Particles;

	float x = 0;
	float y = 0;

	int maxParticles;
	int minParticles;
	float particleDistance;
	float speed;

	bool bStopped = false;
};