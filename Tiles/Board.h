#pragma once

#include <vector>

#include "Tile.h"
#include "TilesPlayer.h"
#include "INIReader.h"

#include "ImageHandler.h"

class Board
{
public:
	void CreateBoard();
	void DeleteBoard();
	void PlacePlayer(TilesPlayer* Player, int TileX = -1, int TileY = -1);	//if -1, assume random placing 

private:
	std::vector<Tile> Tiles;	//12 x 7

};