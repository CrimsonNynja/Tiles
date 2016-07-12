#pragma once

#include <vector>

#include "CollisionComponent.h"
//#include "TilesMath.h"

class CollisionManager
{
public:
	void AddComponent(CollisionComponent* Component);
	void TestCollisions();
	bool TestCollision(CollisionComponent* Col1, CollisionComponent* Col2);
	void DrawCollision(sf::RenderWindow& window, CollisionComponent* Col, sf::Color Colour);

private:
	std::vector<CollisionComponent*> CollisionObjects;
	float MakePositive(float arg1, float arg2);

	/* points used to calculate the collision */
	sf::Vector2f xAxisProduct;		//centre point to centre point
	sf::Vector2f yAxisProduct;
	sf::Vector2f C1DataX;
	sf::Vector2f C1DataY;
	sf::Vector2f C2DataX;
	sf::Vector2f C2DataY;
};