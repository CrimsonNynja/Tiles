#include "CollisionManager.h"

void CollisionManager::AddComponent(CollisionComponent * Component)
{
	CollisionObjects.push_back(Component);
}

void CollisionManager::TestCollisions()
{
	for (unsigned int i = 0; i < CollisionObjects.size(); i ++)
	{
		for (unsigned int j = 0; j < CollisionObjects.size(); j ++)
		{
			if (i != j)
			{
				//if (CollisionObjects[i]->bUpdateNeeded == true), not working at the moment fix later
				{
					CollisionObjects[i]->ObjectsInContactWith.clear();

					if (TestCollision(CollisionObjects[i], CollisionObjects[j]) == true)
					{
						CollisionObjects[i]->ObjectsInContactWith.push_back(CollisionObjects[j]);
					}
					//CollisionObjects[i]->bUpdateNeeded = false;
				}
			}
		}
	}
}

bool CollisionManager::TestCollision(CollisionComponent* Col1, CollisionComponent* Col2)
{
	unsigned int dummy = 0;

	xAxisProduct.x = Col1->Centre.x;
	xAxisProduct.y = Col2->Centre.x;
	yAxisProduct.x = Col1->Centre.y;
	yAxisProduct.y = Col2->Centre.y;

	C1DataX.x = Col1->Centre.x;
	C1DataY.x = Col1->Centre.y;
	C2DataX.x = Col2->Centre.x;
	C2DataY.x = Col2->Centre.y;

	if (Col1->Centre.x > Col2->Centre.x)
	{
		C1DataX.y = Col1->Origin.x;
		C2DataX.y = Col2->BLCorner.x;
	}
	else
	{
		C1DataX.y = Col1->BLCorner.x;
		C2DataX.y = Col2->Origin.x;
	}
	if (Col1->Centre.y > Col2->Centre.y)
	{
		C1DataY.y = Col1->Origin.y;
		C2DataY.y = Col2->BLCorner.y;
	}
	else
	{
		C1DataY.y = Col1->BLCorner.y;
		C2DataY.y = Col2->Origin.y;
	}

	if (MakePositive(xAxisProduct.x, xAxisProduct.y) < (MakePositive(C1DataX.x, C1DataX.y) + MakePositive(C2DataX.x, C2DataX.y)))
	{
		dummy +=1;
	}
	if (MakePositive(yAxisProduct.x, yAxisProduct.y) < (MakePositive(C1DataY.x, C1DataY.y) + MakePositive(C2DataY.x, C2DataY.y)))
	{
		dummy += 1;
	}

	if (dummy == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CollisionManager::DrawCollision(sf::RenderWindow& window, CollisionComponent* Col, sf::Color Colour)
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

float CollisionManager::MakePositive(float arg1, float arg2)
{
	if ((arg1 - arg2) > 0)
	{
		return arg1 - arg2;
	}
	else
	{
		return arg2 - arg1;
	}
}
