#pragma once

#include <vector>
#include <ctime>

#include "Tile.h"
#include "TilesPlayer.h"
#include "INIReader.h"
#include "Pickup.h"
#include "ImageHandler.h"
#include "CollisionManager.h"

class Board
{
public:
	~Board();
	void CreateBoard();
	void DeleteBoard();
	void Reset();
	void PlacePlayer(TilesPlayer* Player, int row = -1, int collumn = -1);	//if -1, assume random placing 
	void SpawnPickup(int row = -1, int collumn = -1);
	void Update();

private:
	void MoveRow(int row);
	void MoveCollumn(int collumn);
	void OrganiseVector(bool bRow, bool bPositive, int index);

	void GameLoop();

	CollisionManager CollisionMngr;

	sf::Clock Timer;
	sf::Time TimeElapsed;

	enum boardDirection
	{
		IDLE = 0,
		ROW,
		COLLUMN
	}BoardDirection;
	unsigned int Placement = 0;
	bool bMovePositivly = rand() % 2;

	bool bActivateEvent = true;
	int evnetTime = 0;

	bool RowCollumn = 0;
	int RowColNum;

	bool bOrganiseVector = false;

	std::vector<std::vector<Tile*>> Tiles;	//12 x 7
	Tile* TempTile;
	std::vector<Pickup*> Pickups;
};