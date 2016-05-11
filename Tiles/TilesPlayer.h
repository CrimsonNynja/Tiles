#pragma once

#include "TextureHandler.h"
#include "ImageHandler.h"
#include "Profile.h"
#include "Entity.h" 
#include "GUI.h"

class TilesPlayer : public Entity
{
public:
	TilesPlayer();

	void LoadFromProfile(Profile* profile);
	void SaveToProfile(Profile* profile);
	void Update();

private:
	GUI gui;

	int score = 0;

};