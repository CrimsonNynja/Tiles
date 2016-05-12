#pragma once

#include <vector>

#include "Tile.h"
#include "TilesPlayer.h"
#include "INIReader.h"
#include "Pickup.h"
#include "ImageHandler.h"
#include "CollisionManager.h"

class Board
{
public:
	void CreateBoard();
	void DeleteBoard();
	void Reset();
	void PlacePlayer(TilesPlayer* Player, int row = -1, int collumn = -1);	//if -1, assume random placing 
	void SpawnPickup(int row, int collumn);
	void Update();

//private:
	void MoveRow(int row);
	void MoveCollumn(int collumn);

	CollisionManager CollisionMngr;

	std::vector<std::vector<Tile>> Tiles;	//12 x 7
	std::vector<Pickup> Pickups;
};