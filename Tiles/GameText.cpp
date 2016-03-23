#include "GameText.h"

GameText::GameText()
{

}

GameText::GameText(std::string InitialValue, sf::Font* font)
{
	this->setFont(*font);
	this->setString(InitialValue);
}

void GameText::Throb(float Size, float Speed)
{

}

void GameText::Shrink(float Size, float Speed)
{

}

void GameText::Grow(float Size, float Speed)
{

}

void GameText::Update()
{

}
