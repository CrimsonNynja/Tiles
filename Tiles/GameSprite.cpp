#include "GameSprite.h"

GameSprite::GameSprite()
{
	Anim.setOwner(this);
}

void GameSprite::setDrawLayer(int Layer)
{
	drawLayer = Layer;
}

void GameSprite::setAnimation(sf::Texture* tex, int width, int height)
{
	Anim.LoadAnimation(tex, width, height);
}

void GameSprite::setHidden(bool bTrue)
{
	bHidden = bTrue;

	if (bHidden == true)
	{
		this->setColor(sf::Color(this->getColor().r, this->getColor().g, this->getColor().b, 0));
	}
	else
	{	//note the if the alpha value is to be save, it isnt doing that here, change later, it might even be worth just not drawing the tile here as well
		this->setColor(sf::Color(this->getColor().r, this->getColor().g, this->getColor().b, 255));
	}
}

bool GameSprite::IsHidden() const
{
	return bHidden;
}

Animation* GameSprite::getAnimationComponent()
{
	return &Anim;
}

CollisionComponent* GameSprite::getCollisionComponent()
{
	return &Collision;
}

int GameSprite::getDrawLayer() const
{
	return drawLayer;
}

void GameSprite::Update()
{
	Anim.Update();
	Collision.Update();
}
