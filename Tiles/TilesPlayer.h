#pragma once

#include "TextureHandler.h"
#include "ImageHandler.h"
#include "Profile.h"
#include "Entity.h" 
#include "GUI.h"
#include "Pickup.h"

class TilesPlayer : public Entity
{
public:
	TilesPlayer();

	void LoadFromProfile(Profile* profile);
	void SaveToProfile(Profile* profile);
	void Move(std::string direction);
	bool IsMoving();
	void Update();

private:
	GUI gui;

	enum direction
	{
		IDLE = 0,
		LEFT,
		RIGHT,
		UP,
		DOWN
	} Direction, NextDirection;
	sf::Vector2f LastPosition;

	int score = 0;

};