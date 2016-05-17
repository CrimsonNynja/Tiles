#include "TilesPlayer.h"

TilesPlayer::TilesPlayer()
{
	this->setAnimation(TextureHandler::instance()->getTexture("Player"), 144, 224);
	this->getAnimationComponent()->setAnimSpeed(100);
	this->drawLayer = 2;
	ImageHandler::instance()->AddToDrawList("Game", this);

	getCollisionComponent()->AddCollisionMask(sf::Vector2f(0, 100), sf::Vector2f(144, 124));	//stuffs up the collision somewhere, dont know where
}

void TilesPlayer::LoadFromProfile(Profile* profile)
{

}

void TilesPlayer::SaveToProfile(Profile* profile)
{

}

void TilesPlayer::Move(std::string direction)
{
	if (direction == "right") 
	{
		if (Direction == IDLE)
		{
			Direction = RIGHT;
		}
		else
		{
			NextDirection = RIGHT;
		}
	}
	else if (direction == "left")
	{
		if (Direction == IDLE)
		{
			Direction = LEFT;
		}
		else
		{
			NextDirection = LEFT;
		}
	}
	else if (direction == "up")
	{
		if (Direction == IDLE)
		{
			Direction = UP;
		}
		else
		{
			NextDirection = UP;
		}
	}
	else
	{
		if (Direction == IDLE)
		{
			Direction = DOWN;
		}
		else
		{
			NextDirection = DOWN;
		}
	}
}

bool TilesPlayer::IsMoving()
{
	if (Direction == IDLE)
	{
		return false;
	}
	return true;
}

void TilesPlayer::Update()	//note the player dies upon startng the match, then work as intended
{
	__super::Update();
	gui.Update();
	
	bool bOnBoard = false;

	if (getCollisionComponent()->ObjectsInContactWith.size() > 0)
	{
		for (auto x: getCollisionComponent()->ObjectsInContactWith)
		{
			if (dynamic_cast<Pickup*>(x->Owner))
			{
				score += 1;
				gui.AddScore(score);
				x->Owner->setPosition(-200, -200);
			}
			if (dynamic_cast<Tile*>(x->Owner))
			{
				bOnBoard = true;
			}
		}
	}

	if (bOnBoard == false)
	{
		std::cout << "YOU DIED!!!!!!!!!!!!" << std::endl;
	}
	
	//move code
	if (Direction == RIGHT)
	{
		this->setPosition(getPosition().x + 8, getPosition().y);
		if ((this->getPosition().x - LastPosition.x) >= 144)
		{
			this->setPosition(LastPosition.x + 144, this->getPosition().y);
			Direction = IDLE;

//			Direction = NextDirection;
//			NextDirection = IDLE;
		}
	}
	if (Direction == LEFT)
	{
		this->setPosition(getPosition().x - 8, getPosition().y);
		if ((LastPosition.x - this->getPosition().x) >= 144)
		{
			this->setPosition(LastPosition.x - 144, this->getPosition().y);
			Direction = IDLE;

//			Direction = NextDirection;
//			NextDirection = IDLE;

		}
	}
	else if (Direction == UP)
	{
		this->setPosition(getPosition().x, getPosition().y - 8);
		if ((LastPosition.y - this->getPosition().y) >= 124)
		{
			this->setPosition(this->getPosition().x, LastPosition.y - 124);
			Direction = IDLE;
//			Direction = NextDirection;
//			NextDirection = IDLE;

		}
	}
	else if (Direction == DOWN)
	{
		this->setPosition(getPosition().x, getPosition().y + 8);
		if ((this->getPosition().y - LastPosition.y) >= 124)
		{
			this->setPosition(this->getPosition().x, LastPosition.y + 124);
			Direction = IDLE;

//			Direction = NextDirection;
//			NextDirection = IDLE;

		}
	}
	else if (Direction == IDLE)
	{
		LastPosition = this->getPosition();
	}

//	std::cout << Direction << "< " << NextDirection << std::endl;
}
