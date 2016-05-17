#include "CollisionComponent.h"

CollisionComponent::CollisionComponent()
{
}

CollisionComponent::CollisionComponent(sf::Sprite* Owner)
{
	this->Owner = Owner;
	Update();
}

void CollisionComponent::AddCollision(sf::Sprite* Owner)
{
	this->Owner = Owner;
	Update();
}

void CollisionComponent::AddCollisionMask(sf::Vector2f origin, sf::Vector2f WidthHeight)		//i think there is something left in the collision at arrounf 0,0
{
	MOrigin.x = Owner->getPosition().x + origin.x;
	MOrigin.y = Owner->getPosition().y + origin.y;
	MBLCorner.x = MOrigin.x + WidthHeight.x;
	MBLCorner.y = MOrigin.y + WidthHeight.y;
	Centre.x = MOrigin.x + (WidthHeight.x / 2);
	Centre.y = MOrigin.y + (WidthHeight.y / 2);
	bHasMask = true;
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
		if (bHasMask == false)
		{
			Centre.x = Owner->getPosition().x + Owner->getGlobalBounds().width / 2;
			Centre.y = Owner->getPosition().y + Owner->getGlobalBounds().height / 2;
			Origin.x = Owner->getPosition().x;
			Origin.y = Owner->getPosition().y;
			BLCorner.x = Owner->getPosition().x + Owner->getGlobalBounds().width;
			BLCorner.y = Owner->getPosition().y + Owner->getGlobalBounds().height;
		}
		else
		{
			Origin = Owner->getPosition() + MOrigin;
			BLCorner = Owner->getPosition() + MBLCorner;
			Centre.x = Owner->getPosition().x + (MBLCorner.x / 2);
			Centre.y = Owner->getPosition().y + (MBLCorner.y / 2);
		}
	}
}
