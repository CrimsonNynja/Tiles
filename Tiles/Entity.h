#pragma once

#include "GameSprite.h"

class Entity : public GameSprite
{
public:
	Entity();
	void MoveObject(float X, float Y);

	bool IsDead();
	void Damage(float damage);
	void Heal(float amount);

	void setHealth(float amount);
	float getHealth();

protected:
	bool bIsDead = false;

	float health;
	float maxHealth;
};