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
		Particles[i].setPosition(500, 500);
		Particles[i].setRotation(rand() % 360);
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
//	srand(time(NULL));
//	for (auto x : Particles)
//	{
//		x.setPosition(500, 500);
//		x.setRotation(rand() % 360);
//
//	}

	//for (auto x : Particles)
	for (int i = 0; i < Particles.size(); i ++)
	{
		Particles[i].setAnimation(tex, width, height);
	//	x.setPosition(500, 500);
	//	std::cout << x.getRotation() << std::endl;

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

void ParticleEmitter::Draw(sf::RenderWindow & window)
{
	for (auto x: Particles)
	{
		window.draw(x);
	}
}

void ParticleEmitter::Update()
{
	if (bStopped == false)
	{
		for (int i = 0; i < Particles.size(); i ++)
		{
			Particles[i].Update();
			Particles[i].move(speed * std::cos(Particles[i].getRotation() * 3.14 / 2), speed * std::sin(Particles[i].getRotation() * 3.14 / 2));

			if (DistanceBetweenPoints(Particles[i].getPosition().x, Particles[i].getPosition().y, x, y) >= particleDistance)
			{
				Particles[i].setPosition(x, y);
				srand(time(NULL));
				for (int i = 0; i < Particles.size(); i++)
				{
					Particles[i].setRotation(rand() % 360);
				}
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
