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
	void CreateBoard(int RowSize, int CollumnSize);		//might accept an image here later as well
	void Reset();
	Tile* getTile(int index);
	Tile* getTile(int row, int collumn);
	int getTileIndex(int row, int collumn);
	int getBoardSize();
	void MoveRow(int RowNo);		//ensure no tiles are moving before begining
	void MoveCollumn(int CollumnNo);
	bool IsOnBoundry(int index);

	void Update();

private:
	/* Board Variables */
	int rowSize = 0;
	int collumnSize = 0;

	sf::Vector2f Offset;

	std::vector<Tile*> Tiles;
	Tile* TempTile;	//used when moving a row or collumn, to go ont the end

	/* Moving Tile Vars */
	void(Board::*FunctPointer)(int) = NULL;
	int FptrBordMoving = 0;
	bool bMoving = false;
	short int MoveDirection = 0; // 1 is +ve and -1 is -ve, 0 is stationry
};

/*
class Board
{
public:
	void DeleteBoard();
	void PlacePlayer(TilesPlayer* Player, int row = -1, int collumn = -1);	//if -1, assume random placing 
	void SpawnPickup(int row = -1, int collumn = -1);

private:
	void OrganiseVector(bool bRow, bool bPositive, int index);

	void GameLoop();

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

	bool bOrganiseVector = false; 

]	std::vector<Pickup*> Pickups;
};
*/