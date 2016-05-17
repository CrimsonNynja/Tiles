#include "Tile.h"

Tile::Tile()
{
	this->setAnimation(TextureHandler::instance()->getTexture("Tile"), 144, 124);
	this->drawLayer = 4;;
}

void Tile::setLastPosition()
{
	lastPosition = this->getPosition();
}

sf::Vector2f Tile::getLastPosition() const
{
	return lastPosition;
}

void Tile::Update()
{
	__super::Update();
}
