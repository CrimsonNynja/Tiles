#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "CollisionComponent.h"

class GameSprite : public sf::Sprite
{
public:
	
	void Update();

//protected:
	Animation Anim{ this };
	CollisionComponent Collision{ this };
};