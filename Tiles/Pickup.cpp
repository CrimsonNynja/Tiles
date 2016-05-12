#include "Pickup.h"

Pickup::Pickup()
{
	this->setAnimation(TextureHandler::instance()->getTexture("Pickup"), 144, 124);
	this->drawLayer = 3;
	ImageHandler::instance()->AddToDrawList("Game", this);
}

void Pickup::Update()
{
	__super::Update();
}
