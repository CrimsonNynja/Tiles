#include "Tile.h"

Tile::Tile()
{
	this->setTexture(*TextureHandler::instance()->getTexture("Tile"));
	this->drawLayer = 4;;
}
