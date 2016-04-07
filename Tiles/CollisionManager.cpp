#include "CollisionManager.h"

bool CollisionManager::TestCollision(CollisionComponent* Col1, CollisionComponent* Col2)
{
	return false;
}

void CollisionManager::DrawCollision(sf::RenderWindow & window, CollisionComponent* Col, sf::Color Colour)
{
	sf::VertexArray vertex;
	vertex.resize(4);
	vertex.setPrimitiveType(sf::Quads);

	vertex[0].color = Colour;
	vertex[1].color = Colour;
	vertex[2].color = Colour;
	vertex[3].color = Colour;
	
	vertex[0].position = Col->Origin;
	vertex[1].position.x = Col->BLCorner.x;
	vertex[1].position.y = Col->Origin.y;
	vertex[2].position = Col->BLCorner;
	vertex[3].position.x = Col->Origin.x;
	vertex[3].position.y = Col->BLCorner.y;

	window.draw(vertex);
}