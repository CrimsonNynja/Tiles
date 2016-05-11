#pragma once

#include "GameSprite.h"

class Entity : public GameSprite
{
public:
	Entity();
	void MoveObject(float X, float Y);

	bool IsDead() const;
	void Damage(float damage);
	void Heal(float amount);

	void setHealth(float amount);
	float getHealth() const;
	void Update();

protected:
	bool bIsDead = false;

	float health;
	float maxHealth;
};