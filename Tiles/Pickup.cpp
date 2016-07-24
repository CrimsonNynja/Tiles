#include "Pickup.h"

Pickup::Pickup()
{
//	srand(time(NULL));		may need boards time seed passes in here
	this->setPosition(-200, -200);
	Reset();
	this->setAnimation(TexHandler->getTexture("Pickup"), 144, 124);	//should make this dependednt on the enum, when more images have been added
	this->drawLayer = 3;
	//ImageHandler::instance()->AddToDrawList("Game", this);
}

void Pickup::Reset()
{
	int randNum = rand() % 51;
//	std::cout << randNum << std::endl;

	if (randNum  < 40)
	{
		scoreType = DEFAULT;
		scoreAmmount = 1;
		bScoreType = true;
		this->setAnimation(TexHandler->getTexture("Pickup"), 144, 124);
		this->setColor(sf::Color(255, 255, 255, 255));
	}
	else if (randNum > 45 && randNum != 50)
	{
		scoreType = BONUS;
		scoreAmmount = 5;
		bScoreType = true;
		this->setAnimation(TexHandler->getTexture("Pickup"), 144, 124);
		this->setColor(sf::Color(255, 0, 0, 255));
	}
	else if (randNum == 50)
	{
		scoreType = COIN;
		scoreAmmount = 1;
		bScoreType = false;
		this->setAnimation(TexHandler->getTexture("Coin"), 144, 124);
		//this->setColor(sf::Color(0, 255, 0, 255));
		//add later
	}
}

int Pickup::getscoreAmmount() const
{
	return scoreAmmount;
}

void Pickup::setScoreType(std::string Type)
{
	if (Type == "BONUS")
	{
		scoreType = BONUS;
		this->setAnimation(TexHandler->getTexture("Pickup"), 144, 124);
		this->setColor(sf::Color(255, 0, 0, 255));
	}
	else if ("COIN")
	{
		scoreType = COIN;
		this->setAnimation(TexHandler->getTexture("Coin"), 144, 124);
		//this->setColor(sf::Color(0, 255, 0, 255));
	}
	else
	{
		scoreType = DEFAULT;
		this->setAnimation(TexHandler->getTexture("Pickup"), 144, 124);
		this->setColor(sf::Color(255, 255, 255, 255));
	}
}

std::string Pickup::getType()
{
	if (scoreType == DEFAULT)
	{
		return "Default";
	}
	else if (scoreType == BONUS)
	{
		return "Bonus";
	}
	else
	{
		return "Coin";
	}
}

void Pickup::Update()
{
	__super::Update();
}
