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

	srand(time(NULL));
	for (int i = 0; i < Particles.size(); i ++)
	{
		Particles[i].setPosition(x, y);
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
	for (int i = 0; i < Particles.size(); i ++)
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
	this->x = x;
	this->y = y;
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
		for (int i = 0; i < Particles.size(); i ++)
		{
			Particles[i].Update();
			Particles[i].move(((static_cast<float> (rand()) / (static_cast<float> (RAND_MAX / speed)))) * std::cos(Particles[i].getRotation() * 3.14 / 2)
				, ((static_cast<float> (rand()) / (static_cast<float> (RAND_MAX / speed)))) * std::sin(Particles[i].getRotation() * 3.14 / 2));
			//still need improving, currently it does even out, but only after a few cycles

			if (DistanceBetweenPoints(Particles[i].getPosition().x, Particles[i].getPosition().y, x, y) >= particleDistance)
			{
				Particles[i].setPosition(x, y);
				Particles[i].setRotation(static_cast<float> (rand()) / (static_cast<float> (RAND_MAX / 360.0)));
			}
		}
	}
}

float ParticleEmitter::DistanceBetweenPoints(float x1, float y1, float x2, float y2)
{
	float a;
	float b;

	if (y1 > y2)
	{
		a = (y1 - y2) * (y1 - y2);
	}
	else
	{
		a = (y2 - y1) * (y2 - y1);
	}
	if (x1 > x2)
	{
		b = (x1 - x2) * (x1 - x2);
	}
	else
	{
		b = (x2 - x1) * (x2 - x1);
	}

	return sqrt(a + b);
}
