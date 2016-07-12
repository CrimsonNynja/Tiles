#include "Tile.h"

Tile::Tile()
{
	this->setAnimation(TextureHandler::instance()->getTexture("Tile"), 144, 124);
	this->drawLayer = 4;
	//lastPosition = this->getPosition();
}

void Tile::setLastPosition()
{
	lastPosition = this->getPosition();
}

sf::Vector2f Tile::getLastPosition() const
{
	return lastPosition;
}

void Tile::FadeOut()
{
	fade = -1;
	if (getColor().a > 7)
	{
		this->setColor(sf::Color(getColor().r, getColor().g, getColor().b, getColor().a - 7));
	}
	if (getColor().a <= 7)
	{
		this->setColor(sf::Color(getColor().r, getColor().g, getColor().b, 0));
		setHidden(true);
		fade = 0;
	}
}

void Tile::FadeIn()
{
	fade = 1;
	setHidden(false);				//fix as done above later, take in the 7 to accound
	if (getColor().a < 255)
	{
		this->setColor(sf::Color(getColor().r, getColor().g, getColor().b, getColor().a + 1));
	}
	if (getColor().a == 254)
	{
		this->setColor(sf::Color(getColor().r, getColor().g, getColor().b, 255));
		fade = 0;
	}
}

void Tile::Update()
{
	__super::Update();

	if (fade == -1)
	{
		FadeOut();
	}
	else if (fade == 1)
	{
		FadeIn();
	}
}
