#pragma once

#include "TextureHandler.h"
#include "GameSprite.h"

class Tile : public GameSprite
{
public:
	Tile();
	void setLastPosition();
	sf::Vector2f getLastPosition() const;
	void FadeOut();		//hides after comleteing
	void FadeIn();
	void Update();

protected:
	sf::Vector2f lastPosition{ 0, 0 };
	int fade = 0;

};