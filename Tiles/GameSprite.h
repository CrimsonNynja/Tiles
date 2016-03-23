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
	Animation* getAnimationComponent();
	CollisionComponent* getCollisionComponent();
	int getLayer() const;
	void Update();

protected:
	//std::vector<Animation> Anim{ 1 };
	Animation Anim{ this };
	CollisionComponent Collision{ this };

	int drawLayer = 0;
};