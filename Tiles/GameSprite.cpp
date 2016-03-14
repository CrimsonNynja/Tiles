#include "GameSprite.h"

GameSprite::GameSprite()
{
	Anim.setOwner(this);
}

void GameSprite::setDrawLayer(int Layer)
{
	drawLayer = Layer;
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
