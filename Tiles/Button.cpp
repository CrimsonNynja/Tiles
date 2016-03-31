#include "Button.h"

Button::Button()
{

}

void Button::AddInnerImage()
{

}

void Button::AddText(std::string Text, sf::Font* Font, sf::Color Colour, float LocalX, float LocalY)
{
	ButtonText.setString(Text);
	ButtonText.setFont(*Font);
	ButtonText.setColor(Colour);
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
	localY = (this->getGlobalBounds().height / 2) - (ButtonTextPtr->getGlobalBounds().height / 2);
}

GameText* Button::getText() const
{
	return ButtonTextPtr;
}

void Button::Update(sf::RenderWindow& window)
{
	__super::Update(window);
	ButtonTextPtr->Update();
	ButtonTextPtr->setPosition(this->getPosition().x + localX, this->getPosition().y + localY);

}
