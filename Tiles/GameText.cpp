#include "GameText.h"

GameText::GameText()
{

}

GameText::GameText(std::string InitialValue, sf::Font* font, sf::Color Colour)
{
	this->setFont(*font);
	this->setString(InitialValue);
	this->setColor(Colour);
}

void GameText::Throb(float Size, float Speed)
{
	float sizeRate = Size / Speed;

	if (FunctPointer != &GameText::Throb)
	{
		FunctPointer = &GameText::Throb;
		size = Size;
		speed = Speed;
		bActive = true;
	}
	else
	{
		if (bShrink == false)
		{
			this->setScale(getScale().x + sizeRate, getScale().y + sizeRate);
			if (this->getScale().x >= 1 + Size)
			{
				bShrink = true;
			}
		}
		else if (bShrink == true)
		{
			this->setScale(getScale().x - sizeRate, getScale().y - sizeRate);
			if (this->getScale().x <= 1 - Size || this->getScale().x <= 0)
			{
				bShrink = false;
			}
		}
	}
}

void GameText::Shrink(float Size, float Speed)
{
	if (FunctPointer != &GameText::Shrink)
	{
		FunctPointer = &GameText::Shrink;
		size = Size;
		speed = Speed;
		bActive = true;
	}
	else
	{
		float shrinkRate = (Size / Speed);
		this->setScale(getScale().x - shrinkRate, getScale().y - shrinkRate);

		if (this->getScale().x <= Size)
		{
			FunctPointer = &GameText::NFP;
		}
	}
}

void GameText::Grow(float Size, float Speed)
{
	if (FunctPointer != &GameText::Grow)
	{
		FunctPointer = &GameText::Grow;
		size = Size;
		speed = Speed;
		bActive = true;
	}
	else
	{
		float growRate = (Size / Speed) / 2;
		this->setScale(getScale().x + growRate, getScale().y + growRate);

		if (this->getScale().x >= Size)	
		{
			FunctPointer = &GameText::NFP;
		}
	}
}

void GameText::ChangeColour(sf::Color ColourToChengeTo)
{
}

void GameText::Stop()
{
	FunctPointer = &GameText::NFP;
	bActive = false;
}

void GameText::Update()
{
	if (bActive == true)
	{
		TimeElapsed = Timer.getElapsedTime();

		if (TimeElapsed.asMilliseconds() >= speed)
		{
			(*this.*FunctPointer)(size, speed);
			Timer.restart();
		}
	}
}
