#pragma once

#include "TextureHandler.h"
#include "ImageHandler.h"
#include "Profile.h"
#include "Entity.h" 
#include "GUI.h"
#include "Pickup.h"
#include "Tile.h"

class TilesPlayer : public Entity
{
public:
	TilesPlayer();

	void LoadFromProfile(Profile* profile);
	void SaveToProfile(Profile* profile);
	void Move(std::string direction);
	bool IsMoving();
	GUI* getGUI();
	int getScore() const;
	int getCurrency() const;
	void Update();

private:
	void Die();

	GUI gui;
	Profile* PlayerProfile;

	enum direction
	{
		IDLE = 0,
		LEFT,
		RIGHT,
		UP,
		DOWN
	} Direction, NextDirection;
	sf::Vector2f LastPosition;

	sf::Clock Timer;
	sf::Time TimeElapsed;
	int score = 0;
	int currency = 0;
};