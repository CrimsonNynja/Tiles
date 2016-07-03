#pragma once

#include <SFML/System.hpp>
#include "CollisionManager.h"
#include "TilesPlayer.h"
#include "Board.h"
#include "Profile.h"


class GameMode
{
public:
	GameMode();
	void Initialize();
	std::string getGameType();
	void Update();

protected:
	CollisionManager CollisionMngr;
	Board GameBoard;
	TilesPlayer Player;

	sf::Clock Timer;
	sf::Time TimeElapsed;

	enum gameType//may havethe gametypes extend off of this, and they can then just overide the Update() function to do their own unique thing
	{
		DEFAULT = 0,
		ENDLESS,
		SURVIVAL,
		TUTORIAL
	} GameType;

};