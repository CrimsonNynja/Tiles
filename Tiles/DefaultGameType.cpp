#include "DefaultGameType.h"

DefaultGameType::DefaultGameType()
{
	gameType = "DEFAULT";

	for (unsigned i = 0; i < 8; i ++)
	{
		Pickups.push_back(new Pickup);
		Pickups[i]->Reset();
		Pickups[i]->setHidden(true);
		CollisionMngr.AddComponent(Pickups[i]->getCollisionComponent());
		ImgHandler->AddToDrawList("Game", Pickups[i]);
	}
	ImgHandler->Sort("Game");
}

void DefaultGameType::Update()
{
	__super::Update();

	for (auto x: Pickups)
	{
		x->Update();

		if (x->IsHidden() == true)
		{
			randVar = rand() % (GameBoard.getBoardSize() - 1);
			x->setPosition(GameBoard.getTile(randVar)->getPosition());
			x->setHidden(false);
		}
	}

	if (static_cast<int>(TimeElapsed.asSeconds()) == moveCount && bMoved == false)
	{
		randVar = rand() % 2;

		if (randVar == 0)
		{
			randVar = rand() % 6 + 1;		//make dynamic later
			GameBoard.MoveRow(randVar);
		}
		else if (randVar == 1)
		{
			randVar = rand() % 11 + 1;		//make dyncamic later
			GameBoard.MoveCollumn(randVar);
		}

		time = TimeElapsed.asSeconds();
		bMoved = true;
	}
	if (static_cast<int>(TimeElapsed.asSeconds()) == FadeCount && bFaded == false)
	{
		if (fadeCount < fadeMax)
		{
			randVar = rand() % (GameBoard.getBoardSize() - 1);
			GameBoard.getTile(randVar)->FadeOut();
			bFaded = true;
			fadeCount++;
		}
	}
	

	if (static_cast<int>(TimeElapsed.asSeconds()) == 9)
	{
		Timer.restart();
		bFaded = false;
		bMoved = false;
	}
}
