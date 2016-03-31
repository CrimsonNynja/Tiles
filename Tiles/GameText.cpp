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
	bActive = true;
}

void GameText::Shrink(float Size, float Speed)
{
	bActive = true;
}

void GameText::Grow(float Size, float Speed)
{
	bActive = true;
}

void GameText::Stop()
{
	bActive = false;
}

void GameText::Update()
{
	if (bActive == true)
	{
		TimeElapsed = Timer.getElapsedTime();

		if (TimeElapsed.asMilliseconds() >= /*speed goes here*/1)
		{
			Timer.restart();
		}
	}
}
