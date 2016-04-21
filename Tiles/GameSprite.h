#pragma once
//#include <Vector>
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "CollisionComponent.h"

class GameSprite : public sf::Sprite
{
public:
	GameSprite();
	void setDrawLayer(int Layer);
	void setAnimation(sf::Texture* tex, int width, int height);
	void setHidden(bool bTrue);
	bool IsHidden() const;
	Animation* getAnimationComponent();
	CollisionComponent* getCollisionComponent();
	int getDrawLayer() const;
	void Update();

protected:
	Animation Anim{ this };
	CollisionComponent Collision{ this };

	int drawLayer = 0;
	bool bidden = false;
};