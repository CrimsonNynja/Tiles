#include "Tile.h"

Tile::Tile()
{
	this->setTexture(*TextureHandler::instance()->getTexture("Tile"));
	this->setDrawLayer(4);
}
