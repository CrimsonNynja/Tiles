#include "GameMode.h"

GameMode::GameMode()
{

}

void GameMode::Initialize()
{
	GameBoard.CreateBoard(7, 12);

	Player.setPosition(GameBoard.getTile(0)->getPosition());

	for (unsigned i = 0; i < GameBoard.getBoardSize(); i ++)
	{
		CollisionMngr.AddComponent(GameBoard.getTile(i)->getCollisionComponent());
	}
	CollisionMngr.AddComponent(Player.getCollisionComponent());



	GameBoard.MoveRow(2);
}

void GameMode::Update()		//need to move the timer here as well
{
	CollisionMngr.TestCollisions();

	GameBoard.Update();
	Player.Update();
}
