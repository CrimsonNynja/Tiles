#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "CollisionComponent.h"

class GameSprite : public sf::Sprite
{
public:
	void setDrawLayer(int Layer);
	Animation* getAnimationComponent() const;
	CollisionComponent* getCollisionComponent() const;
	void getLayer() const;
	void Update();

protected:
	Animation Anim{ this };
	CollisionComponent Collision{ this };

	int drawLayer = 0;
};