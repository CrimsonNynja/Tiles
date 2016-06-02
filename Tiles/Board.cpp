#include "Board.h"

Board::~Board()
{
	delete TempTile;

	for (auto x : Pickups)
	{
		delete x;
	}
//	for (unsigned i = 0; i < Tiles.size(); i ++)
//	{
//		for (unsigned j = 0; j < Tiles[i].size(); j ++)
//		{
//			delete Tiles[i][j];		//error up after doing the resettihng of the vector, stops at 5?
//		}
//	}
	Tiles.clear();
}

void Board::CreateBoard()
{
//	srand(time(0));

	Timer.restart();	//should do after starting game, also needs to pause with the game later
	this->Reset();

	for (unsigned i = 0; i < 12; i ++)
	{
		Pickups.push_back(new Pickup());
	}

	for (unsigned int i = 0; i < Pickups.size(); i ++)
	{
		CollisionMngr.AddComponent(Pickups[i]->getCollisionComponent());
		SpawnPickup(rand() % 7, rand() % 12);
	}
	TempTile = new Tile;
	TempTile->setPosition(-200, -200);
	ImgHandler->AddToDrawList("Game", TempTile);
	ImgHandler->Sort("Game");
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
		for (unsigned j = 0; j < 12; j ++)
		{
			Tiles[i].push_back(new Tile());
		}
	}

	float x = 80, y = 124;

	for (unsigned int i = 0; i < Tiles.size(); i++)
	{
		for (unsigned int j = 0; j < Tiles[i].size(); j++)
		{
			Tiles[i][j]->setPosition(x, y);
			x += Tiles[i][j]->getGlobalBounds().width;
//			std::cout << x << std::endl;
			ImageHandler::instance()->AddToDrawList("Game", Tiles[i][j]);
			CollisionMngr.AddComponent(Tiles[i][j]->getCollisionComponent());
		}
		x = 80;
		y += Tiles[i][1]->getGlobalBounds().height;
	}
}

void Board::PlacePlayer(TilesPlayer* Player, int row, int collumn)
{
	CollisionMngr.AddComponent(Player->getCollisionComponent());

	Player->setPosition(Tiles[row][collumn]->getPosition().x, Tiles[row][collumn]->getPosition().y - 100);

	//TODO random spawns if -1
}

void Board::SpawnPickup(int row, int collumn)		//all pickups being added to the list, but only the last one comes back detected
{
	float x = Tiles[row][collumn]->getPosition().x;
	float y = Tiles[row][collumn]->getPosition().y;

	for (unsigned int i = 0; i < Pickups.size(); i++)
	{
		if (Pickups[i]->getPosition().x == -200 && Pickups[i]->getPosition().y == -200)
		{
			Pickups[i]->setPosition(x, y);
			for (unsigned int j = 0; j < Pickups.size(); j++)
			{
				if (Pickups[i]->getPosition() == Pickups[j]->getPosition() && i != j)
				{
					Pickups[i]->setPosition(-200, -200);
					//SpawnPickup(1, 1);
				}
			}
			break;
		}
	}
}

void Board::Update()
{
	//collision testing goes here
	GameLoop();

	for (unsigned int i = 0; i < Pickups.size(); i ++)
	{
		Pickups[i]->Update();
	}
	for (unsigned int i = 0; i < Tiles.size(); i ++)
	{
		for (unsigned int j = 0; j < Tiles[i].size(); j ++)
		{
			Tiles[i][j]->Update();
		}
	}
	CollisionMngr.TestCollisions();
	SpawnPickup(rand() % 7, rand() % 12);


	if (BoardDirection == ROW)		//need to reorganise the Tiles vector, so that after movign they are all lastInsex +- 1, will need the temp node before i do this
	{
		for (unsigned int i = 0; i < Tiles[Placement].size(); i ++)
		{
			if (bMovePositivly == true)
			{
				Tiles[Placement][i]->setPosition(Tiles[Placement][i]->getPosition().x + 8, Tiles[Placement][i]->getPosition().y);
				if (Tiles[Placement][i]->getPosition().x - Tiles[Placement][i]->getLastPosition().x > 144)
				{
					Tiles[Placement][i]->setPosition(Tiles[Placement][i]->getLastPosition().x + 144, Tiles[Placement][i]->getPosition().y);
					BoardDirection = IDLE;
				}
			}
			else
			{
				Tiles[Placement][i]->setPosition(Tiles[Placement][i]->getPosition().x - 8, Tiles[Placement][i]->getPosition().y);
				if (Tiles[Placement][i]->getLastPosition().x - Tiles[Placement][i]->getPosition().x > 144)
				{
					Tiles[Placement][i]->setPosition(Tiles[Placement][i]->getLastPosition().x - 144, Tiles[Placement][i]->getPosition().y);
					BoardDirection = IDLE;
				}
			}
		}

	}
	else if (BoardDirection == COLLUMN)
	{
		for (unsigned int i = 0; i < Tiles.size(); i++)
		{
			if (bMovePositivly == true)
			{
				Tiles[i][Placement]->setPosition(Tiles[i][Placement]->getPosition().x, Tiles[i][Placement]->getPosition().y + 8);
				if (Tiles[i][Placement]->getPosition().y - Tiles[i][Placement]->getLastPosition().y > 124)
				{
					Tiles[i][Placement]->setPosition(Tiles[i][Placement]->getPosition().x, Tiles[i][Placement]->getLastPosition().y + 124);
					BoardDirection = IDLE;
				}
			}
			else
			{
				Tiles[i][Placement]->setPosition(Tiles[i][Placement]->getPosition().x, Tiles[i][Placement]->getPosition().y - 8);
				if (Tiles[i][Placement]->getLastPosition().y - Tiles[i][Placement]->getPosition().y > 124)
				{
					Tiles[i][Placement]->setPosition(Tiles[i][Placement]->getPosition().x, Tiles[i][Placement]->getLastPosition().y - 124);
					BoardDirection = IDLE;
				}
			}
		}
	}
	else
	{
		for (unsigned int i = 0; i < Tiles.size(); i++)
		{
			for (unsigned int j = 0; j < Tiles[i].size(); j++)
			{
				Tiles[i][j]->setLastPosition();
			}
		}
	}

	if (bOrganiseVector == true)
	{
		if (BoardDirection == ROW)
		{
			OrganiseVector(true, bMovePositivly, Placement);
		}
		else if (BoardDirection == COLLUMN)
		{
			OrganiseVector(false, bMovePositivly, Placement);
		}
	}
}

void Board::MoveRow(int row)
{
	BoardDirection = ROW;
	Placement = row;
	bMovePositivly = rand() % 2;
}

void Board::MoveCollumn(int collumn)
{
	BoardDirection = COLLUMN;
	Placement = collumn;
	bMovePositivly = rand() % 2;
}

void Board::OrganiseVector(bool bRow, bool bPositive, int index)
{
	if (bRow == true)
	{
		for (unsigned i = 0; i < Tiles[index].size(); i ++)
		{
			if (bPositive == true)
			{
				if (i == Tiles[Placement].size() - 1)
				{
					Tiles[Placement][0] = Tiles[Placement][i];
					Tiles[Placement][0]->setPosition(80, Tiles[Placement][0]->getPosition().y);
				}
				else
				{
					Tiles[Placement][i] = Tiles[Placement][i + 1];
				}
			}
			else
			{
				if (i == 0)
				{
					Tiles[Placement][Tiles[Placement].size() - 1] = Tiles[Placement][0];
					Tiles[Placement][Tiles[Placement].size() - 1]->setPosition(80 + (Tiles[0][i]->getGlobalBounds().width * 11), Tiles[Placement][Tiles[Placement].size() - 1]->getPosition().y);
				}
				else
				{
					Tiles[Placement][i] = Tiles[Placement][i - 1];
				}
			}
		}
	}
	else
	{
		for (unsigned i = 0; i < Tiles.size(); i ++)
		{
			if (bPositive == true)
			{
				if (i == Tiles[Placement].size() - 1)
				{
					Tiles[0][Placement] = Tiles[i][Placement];
					//Tile;
				}
				else
				{
					Tiles[i][Placement] = Tiles[i + 1][Placement];
				}
			}
			else
			{
//				if ()
//				{
//
//				}
//				else
//				{
//
//				}
			}
		}
	}

}

void Board::GameLoop()
{
	TimeElapsed = Timer.getElapsedTime();

	if (bActivateEvent == true)
	{
		if (TimeElapsed.asSeconds() > 1 && TimeElapsed.asSeconds() < 2)		//set all randoms vars for a time cycle
		{
			RowCollumn = rand() % 10;
			RowColNum = rand() % 7;		//allow it to use the full range of collumn later
			bActivateEvent = false;
			evnetTime = TimeElapsed.asSeconds();
		}
		if (TimeElapsed.asSeconds() > 4  && TimeElapsed.asSeconds() < 5)	//move row/collumn
		{
	//		if (RowCollumn % 2 == 0)
			{ 
				MoveRow(RowColNum);
			}
	//		else if (RowCollumn % 2 == 1)
	//		{
	//			MoveCollumn(RowColNum);
	//		}
			bActivateEvent = false;
			evnetTime = TimeElapsed.asSeconds();
		}
	}

	if (TimeElapsed.asSeconds() > (evnetTime + 1))
	{
		bActivateEvent = true;
	}

	if (TimeElapsed.asSeconds() > 10)
	{
		Timer.restart();
	}
}
