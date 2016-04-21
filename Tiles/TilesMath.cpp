#include "TilesMath.h"

float DistanceBetweenToPoints(float x1, float y1, float x2, float y2)
{
	float a;
	float b;

	if (y1 > y2)
	{
		a = (y1 - y2) * (y1 - y2);
	}
	else
	{
		a = (y2 - y1) * (y2 - y1);
	}
	if (x1 > x2)
	{
		b = (x1 - x2) * (x1 - x2);
	}
	else
	{
		b = (x2 - x1) * (x2 - x1);
	}

	return sqrt(a + b);
}

float DistanceBetweenToPoints(sf::Vector2f Point1, sf::Vector2f Point2)
{
	return DistanceBetweenToPoints(Point1.x, Point1.y, Point2.x, Point2.y);
}
