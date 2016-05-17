#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

class CollisionComponent
{
public:
	CollisionComponent();
	CollisionComponent(sf::Sprite* Owner);
	void AddCollision(sf::Sprite* Owner);
	void AddCollisionMask(sf::Vector2f origin, sf::Vector2f WidthHeight);
	bool TestMouseCollision(sf::RenderWindow& window);
	void Update();

//private:
	sf::Sprite* Owner;
	std::vector<CollisionComponent*> ObjectsInContactWith;

	sf::Vector2f Centre;
	sf::Vector2f Origin;
	sf::Vector2f BLCorner;

	sf::Vector2f MOrigin;
	sf::Vector2f MBLCorner;

	bool bSolid = true;
	bool bUpdateNeeded = true;
	bool bHasMask = false;
};
