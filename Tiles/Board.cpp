#include "Board.h"

void Board::CreateBoard()
{
	this->Reset();

	Pickups.resize(12);
	for (unsigned int i = 0; i < Pickups.size(); i ++)
	{
		CollisionMngr.AddComponent(Pickups[i].getCollisionComponent());
		SpawnPickup(3, i);
	}

	ImageHandler::instance()->Sort("Game");
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
}

void Board::PlacePlayer(TilesPlayer* Player, int row, int collumn)
{
	CollisionMngr.AddComponent(Player->getCollisionComponent());

	Player->setPosition(Tiles[row][collumn].getPosition().x, Tiles[row][collumn].getPosition().y - 124);

	//TODO random spawns if -1
}

void Board::SpawnPickup(int row, int collumn)		//all pickups being added to the list, but only the last one comes back detected
{
	float x = Tiles[row][collumn].getPosition().x;
	float y = Tiles[row][collumn].getPosition().y;

	for (unsigned int i = 0; i < Pickups.size(); i ++)
	{
		if (Pickups[i].getPosition().x == 0 && Pickups[i].getPosition().y == 0)
		{
			Pickups[i].setPosition(x, y);
			break;
		}
	}	
}

void Board::Update()
{
	//collision testing goes here
	for (unsigned int i = 0; i < Pickups.size(); i ++)
	{
		Pickups[i].Update();
	}
	CollisionMngr.TestCollisions();
}

void Board::MoveRow(int row)
{

}

void Board::MoveCollumn(int collumn)
{
}
