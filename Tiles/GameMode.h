#pragma once

#include <SFML/System.hpp>
#include "CollisionManager.h"
#include "TilesPlayer.h"
#include "Board.h"
#include "Profile.h"
#include "Pickup.h"
#include <ctime>

class GameMode
{
public:
	GameMode();
	void Initialize();
	void Reset();
	std::string getGameType();
	TilesPlayer* getPlayer();
	void Update();

protected:
	CollisionManager CollisionMngr;
	Board GameBoard;
	TilesPlayer Player;
	std::vector<Pickup*> Pickups;

	sf::Clock Timer;
	sf::Time TimeElapsed;

	std::string gameType;
};