#pragma once

#include "TextureHandler.h"
#include "ImageHandler.h"
#include "GameSprite.h"

class Pickup : public GameSprite
{
public:
	Pickup();
	int getscoreAmmount() const;
	void Update();

protected:
	int scoreAmmount = 1;
};