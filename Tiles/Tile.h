#pragma once

#include "TextureHandler.h"
#include "GameSprite.h"

class Tile : public GameSprite
{
public:
	Tile();
	void setLastPosition();
	sf::Vector2f getLastPosition() const;
	void Update();

protected:
	sf::Vector2f lastPosition{ 0, 0 };
};