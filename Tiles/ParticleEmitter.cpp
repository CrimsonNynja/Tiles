#include "ParticleEmitter.h"

ParticleEmitter::ParticleEmitter()
{
}

ParticleEmitter::ParticleEmitter(int maxParticles, int minParticles, float particleDistance, float speed)
{
	this->maxParticles = maxParticles;
	this->minParticles = minParticles;
	this->particleDistance = particleDistance;
	this->speed = speed;

	Particles.resize(maxParticles);

	srand(time(nullptr));
	for (unsigned int i = 0; i < Particles.size(); i ++)
	{
		Particles[i].setPosition(Location.x, Location.y);
		Particles[i].setRotation(static_cast<float> (rand()) / (static_cast<float> (RAND_MAX / 360.0)));
	}
}

void ParticleEmitter::AddParticleImage(sf::Texture* tex)
{
	for (auto x: Particles)
	{
		x.setTexture(*tex);
	}
}

void ParticleEmitter::AddParticleImage(sf::Texture* tex, int width, int height)
{
	for (unsigned int i = 0; i < Particles.size(); i ++)
	{
		Particles[i].setAnimation(tex, width, height);
	}
}

void ParticleEmitter::setHidden(bool bTrue)
{
	for (unsigned int i = 0; i < Particles.size(); i ++)
	{
		Particles[i].setHidden(bTrue);
	}
}

void ParticleEmitter::setParticleDrawLayer(int Layer)
{
	for (unsigned int i = 0; i < Particles.size(); i ++)
	{
		Particles[i].setDrawLayer(Layer);
	}
}

sf::Texture* ParticleEmitter::getParticleImage()
{
	return nullptr;//Particles[0].getTexture();
}

void ParticleEmitter::Stop()
{
	bStopped = true;
}

void ParticleEmitter::Start()
{
	bStopped = false;
}

void ParticleEmitter::setPosition(float x, float y)
{
	Location.x = x;
	Location.y = y;
	this->Update();
}

void ParticleEmitter::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto x : Particles)
	{
		if (x.IsHidden() == false)
		{
			target.draw(x);
		}
	}
}

void ParticleEmitter::Update()
{
	if (bStopped == false)
	{
		for (unsigned int i = 0; i < Particles.size(); i ++)
		{
			Particles[i].Update();
			Particles[i].move(((static_cast<float> (rand()) / (static_cast<float> (RAND_MAX / speed)))) * std::cos(Particles[i].getRotation() * 3.14 / 2)
				, ((static_cast<float> (rand()) / (static_cast<float> (RAND_MAX / speed)))) * std::sin(Particles[i].getRotation() * 3.14 / 2));
			//still need improving, currently it does even out, but only after a few cycles

			if (DistanceBetweenToPoints(Particles[i].getPosition(), Location) >= particleDistance)
			{
				Particles[i].setPosition(Location.x, Location.y);
				Particles[i].setRotation(static_cast<float> (rand()) / (static_cast<float> (RAND_MAX / 360.0)));
			}
		}
	}
}