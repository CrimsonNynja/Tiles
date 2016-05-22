#include "Button.h"

Button::Button()
{

}

void Button::AddInnerImage()
{

}

void Button::AddText(std::string Text, sf::Font* Font, sf::Color Colour, int FontSize, float LocalX, float LocalY)
{
	ButtonText.setString(Text);
	ButtonText.setFont(*Font);
	ButtonText.setColor(Colour);
	ButtonText.setCharacterSize(FontSize);
	ButtonText.setPosition(this->getPosition().x + LocalX, this->getPosition().y + LocalY);
	ButtonTextPtr = &ButtonText;
	localX = LocalX;
	localY = LocalY;
}

void Button::AddText(GameText* GameText, float LocalX, float LocalY)
{
	ButtonTextPtr = GameText;
	ButtonTextPtr->setPosition(this->getPosition().x + LocalX, this->getPosition().y + LocalY);
	localX = LocalX;
	localY = LocalY;
}

void Button::CenterText()
{
	localX = (this->getGlobalBounds().width / 2) - (ButtonTextPtr->getGlobalBounds().width / 2);
	localY = (this->getGlobalBounds().height / 2) - (ButtonTextPtr->getGlobalBounds().height);// /2 SFML ERROR HERE CANT FIX, found work arround
}

GameText* Button::getText() const
{
	return ButtonTextPtr;
}

void Button::EventUpdate(sf::RenderWindow & window, sf::Event & bevent)
{
	__super::EventUpdate(window, bevent);
}

void Button::Update()
{
	__super::Update();
	ButtonTextPtr->Update();
	ButtonTextPtr->setPosition(this->getPosition().x + localX, this->getPosition().y + localY);
}
