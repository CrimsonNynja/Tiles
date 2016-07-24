#include "TutorialGameMode.h"

TutorialGameMode::TutorialGameMode()
{
	MessageText.setPosition(600, 900);		//not the right position, will fix when a text box has been created
	TooltipText.setPosition(500, 170);		//as above
	MessageText.setCharacterSize(40);
	TooltipText.setCharacterSize(20);

	TextBox.setImages(TexHandler->getTexture("TextBox"), TexHandler->getTexture("TextBox"), TexHandler->getTexture("TextBox"), 1600, 200);
	TextBox.AddText(&MessageText, 50, 50);
	TextBox.setPosition(140, 870);
	TextBox.CenterText();

	for (unsigned i = 0; i < 3; i ++)
	{
		Pickups.push_back(new Pickup);
		Pickups[i]->setPosition(-200, -200);
		ImgHandler->AddToDrawList("Game", Pickups[i]);
		CollisionMngr.AddComponent(Pickups[i]->getCollisionComponent());
	}

	ImgHandler->AddToDrawList("Game", &MessageText);
	ImgHandler->AddToDrawList("Game", &TooltipText);
	ImgHandler->AddToDrawList("Game", &TextBox);
}

void TutorialGameMode::Initialize()
{
	srand(std::time(NULL));

	GameBoard.CreateBoard(5, 7);

	for (unsigned i = 0; i < GameBoard.getBoardSize(); i++)
	{
		CollisionMngr.AddComponent(GameBoard.getTile(i)->getCollisionComponent());
	}
	CollisionMngr.AddComponent(Player.getCollisionComponent());

	Player.setPosition(GameBoard.getTile(17)->getPosition().x, GameBoard.getTile(17)->getPosition().y - 100);

	Timer.restart();
}

void TutorialGameMode::EventUpdate(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.x && tooltipIndex == 0)
	{
		messageIndex += 1;
	}
	if (bPaused == false)
	{
		__super::EventUpdate(event);
		
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
			{
				moveDirectionCount += 1;
			}
			if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
			{
				moveDirectionCount += 1;
			}
			if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
			{
				moveDirectionCount += 1;
			}
			if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
			{
				moveDirectionCount += 1;
			}
		}
	}
}

void TutorialGameMode::Update()
{
	UpdateTutorial();

	CollisionMngr.TestCollisions();
	GameBoard.Update();
	TextBox.Update();
	TextBox.CenterText();

	for (auto x:Pickups)
	{
		x->Update();
	}

	Player.Update();

/*	if (Player.IsDead() == true)
	{
		//the tutorial was failed somehow
		MessageText.setString("Don't know how you managed to die on the tutorial, lets try again");
		TextBox.CenterText();
	}	*/
}

void TutorialGameMode::UpdateTutorial()		//add a hidden option for GameText
{
	try
	{
		MessageText.setString(TutorialMessages.at(messageIndex));
		TooltipText.setString(ToolTips.at(tooltipIndex));
	}
	catch (const std::out_of_range& e)
	{
		MessageText.setString("You have now completed the tutorial");
	}

	if (tooltipIndex == 0)
	{
		bPaused = true;
	}
	else
	{
		bPaused = false;
	}

	if (messageIndex == 2)
	{
		tooltipIndex = 1;
		
		if (moveDirectionCount == 4)
		{
			bPaused = true;
			messageIndex += 1;
		}
	}
	else if (messageIndex == 3)
	{
		Pickups[0]->setPosition(GameBoard.getTile(3)->getPosition());
		Pickups[1]->setPosition(GameBoard.getTile(12)->getPosition());
		Pickups[2]->setPosition(GameBoard.getTile(20)->getPosition());
		tooltipIndex = 0;
	}
	else if (messageIndex == 5)
	{
		bPaused = false;
		tooltipIndex = 2;
		if (Player.getScore() >= 3)
		{
			bPaused = true;
			messageIndex += 1;
			tooltipIndex = 0;
		}
	}
	else if (messageIndex == 6)
	{
		Pickups[0]->setPosition(GameBoard.getTile(15)->getPosition());
		Pickups[0]->setScoreType("COIN");
	}
	else if (messageIndex == 8)
	{
		bPaused = false;
		tooltipIndex = 3;
		if (Player.getCurrency() >= 1)
		{
			bPaused = true;
			messageIndex += 1;
			tooltipIndex = 0;
		}
	}
	else if (messageIndex == 15)
	{
		tooltipIndex = 4;
		if (bTaskDone == false)
		{
			GameBoard.MoveRow(3);
			bTaskDone = true;
		}
		else
		{
			messageIndex += 1;
		}
	}
	else if (messageIndex == 17)
	{
		tooltipIndex = 5;
		if (bTaskDone == false)
		{
			GameBoard.getTile(2, 1)->FadeOut();
			bTaskDone = true;
		}
		else
		{
			messageIndex += 1;
		}
	}
	else
	{
		bTaskDone = false;
		tooltipIndex = 0;
	}
}