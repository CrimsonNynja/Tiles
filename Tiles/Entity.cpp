#include "Entity.h"

Entity::Entity()
{

}

void Entity::MoveObject(float X, float Y) 
{
	setPosition(getPosition().x + X, getPosition().y + Y);
}

bool Entity::IsDead() const
{
	return bIsDead;
}

void Entity::Damage(float damage) 
{
	if (IsDead() == false)
	{
		setHealth(getHealth() - damage);
		if (health <= 0) 
		{
			bIsDead = true;
			setHealth(0);
		}
	}
}

void Entity::Heal(float amount)
{
	if (IsDead() == false)
	{
		setHealth(getHealth() + amount);
		if (health > maxHealth) 
		{
			setHealth(maxHealth);
		}
	}
}

void Entity::setHealth(float amount) 
{
	health = amount;

	if (health <= 0)
	{
		bIsDead = true;
	}
}

float Entity::getHealth() const 
{
	return health;
}

void Entity::Update()
{
	__super::Update();
}

