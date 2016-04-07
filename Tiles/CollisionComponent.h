#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class CollisionComponent
{
public:
	CollisionComponent();
	CollisionComponent(sf::Sprite* Owner);
	void AddCollision(sf::Sprite* Owner);
	bool TestMouseCollision(sf::RenderWindow& window);
	void Update();

//private:
	sf::Sprite* Owner;

	sf::Vector2f Centre;
	sf::Vector2f Origin;
	sf::Vector2f BLCorner;

	bool bSolid = true;
};
