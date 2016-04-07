#pragma once

#include "CollisionComponent.h"

class CollisionManager
{
public:
	
	bool TestCollision(CollisionComponent* Col1, CollisionComponent* Col2);
	void DrawCollision(sf::RenderWindow& window, CollisionComponent* Col, sf::Color Colour);

private:


};