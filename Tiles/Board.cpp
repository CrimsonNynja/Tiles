#include "Board.h"

void Board::CreateBoard()
{
	this->Reset();
}

void Board::DeleteBoard()
{
	Tiles.clear();
}

void Board::Reset()
{
	Tiles.resize(7);
	for (int i = 0; i < Tiles.size(); i++)
	{
		Tiles[i].resize(12);
	}

	float x = 80, y = 124;

	for (unsigned int i = 0; i < Tiles.size(); i++)
	{
		for (unsigned int j = 0; j < Tiles[i].size(); j++)
		{
			Tiles[i][j].setPosition(x, y);
			x += Tiles[i][j].getGlobalBounds().width;
			ImageHandler::instance()->AddToDrawList("Game", &Tiles[i][j]);
		}
		x = 80;
		y += Tiles[i][1].getGlobalBounds().height;
	}

	ImageHandler::instance()->Sort("Game");
}

void Board::PlacePlayer(TilesPlayer * Player, int TileX, int TileY)
{
}

void Board::Update()
{
}

void Board::MoveRow(int row)
{

}

void Board::MoveCollumn(int collumn)
{
}
