#include "GameMode.h"

GameMode::GameMode()
{
	gameType = "NONE";
}

void GameMode::Initialize()
{
	srand(std::time(NULL));

	GameBoard.CreateBoard(7, 12);

	for (unsigned i = 0; i < GameBoard.getBoardSize(); i ++)
	{
		CollisionMngr.AddComponent(GameBoard.getTile(i)->getCollisionComponent());
	}
	CollisionMngr.AddComponent(Player.getCollisionComponent());

	Player.setPosition(GameBoard.getTile(0)->getPosition().x, GameBoard.getTile(0)->getPosition().y - 100);

	Timer.restart();
}

void GameMode::Reset()
{
	Timer.restart();
}

std::string GameMode::getGameType()
{
	return gameType;
}

TilesPlayer* GameMode::getPlayer()
{
	return &Player;
}

void GameMode::Update()		//need to move the timer here as well
{
	CollisionMngr.TestCollisions();

	GameBoard.Update();
	Player.Update();

	TimeElapsed = Timer.getElapsedTime();
}

void GameMode::EventUpdate(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
		{
			Player.Move("up");
		}
		if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
		{
			Player.Move("down");
		}
		if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
		{
			Player.Move("left");
		}
		if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
		{
			Player.Move("right");
		}
	}
}
