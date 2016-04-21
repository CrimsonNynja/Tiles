#pragma once

#include <vector>
#include "GameSprite.h"
#include "TilesMath.h"

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
	void setHidden(bool bTrue);
	void setParticleDrawLayer(int Layer);
	sf::Texture* getParticleImage();

	void Stop();
	void Start();
	void setPosition(float x, float y);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void Update();

private:
	std::vector<GameSprite> Particles;

	sf::Vector2f Location{ 0, 0 };

	int maxParticles;
	int minParticles;
	float particleDistance;
	float speed;

	bool bStopped = false;
};