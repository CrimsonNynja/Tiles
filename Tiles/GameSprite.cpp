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

Animation* GameSprite::getAnimationComponent()
{
	return &Anim;
}

CollisionComponent* GameSprite::getCollisionComponent()
{
	return &Collision;
}

int GameSprite::getLayer() const
{
	return drawLayer;
}

void GameSprite::Update()
{
	Anim.Update();
	Collision.Update();
}
