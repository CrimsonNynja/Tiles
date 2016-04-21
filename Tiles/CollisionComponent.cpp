#include "CollisionComponent.h"

CollisionComponent::CollisionComponent()
{
}

CollisionComponent::CollisionComponent(sf::Sprite * Owner)
{
	this->Owner = Owner;
	Update();
}

void CollisionComponent::AddCollision(sf::Sprite* Owner)
{
	this->Owner = Owner;
	Update();
}

bool CollisionComponent::TestMouseCollision(sf::RenderWindow& window)
{
	if (sf::Mouse::getPosition(window).x >= Origin.x && sf::Mouse::getPosition(window).y >= Origin.y &&
		sf::Mouse::getPosition(window).x <= Origin.x + Owner->getGlobalBounds().width &&
		sf::Mouse::getPosition(window).y <= Origin.y + Owner->getGlobalBounds().height)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CollisionComponent::Update()
{
	//if ((int)Origin.x != (int)Owner->getPosition().x || (int)Origin.y != (int)Owner->getPosition().y)//not working for some reason, fix later
	{
//		bUpdateNeeded = true;

		Centre.x = Owner->getPosition().x + Owner->getGlobalBounds().width / 2;
		Centre.y = Owner->getPosition().y + Owner->getGlobalBounds().height / 2;
		Origin.x = Owner->getPosition().x;
		Origin.y = Owner->getPosition().y;
		BLCorner.x = Owner->getPosition().x + Owner->getGlobalBounds().width;
		BLCorner.y = Owner->getPosition().y + Owner->getGlobalBounds().height;
	}
}
