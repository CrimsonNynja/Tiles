#pragma once

#include "SelectableUI.h"
#include "GameText.h"

class Button : public SelectableUI
{
public:
	Button();
	void AddInnerImage();
	void AddText(std::string Text, sf::Font* Font, sf::Color Colour, int FontSize, float LocalX, float LocalY);
	void AddText(GameText* GameText, float LocalX, float LocalY);
	void CenterText();
	GameText* getText() const;
	void EventUpdate(sf::RenderWindow& window, sf::Event& bevent);
	void Update();

private:
	GameText ButtonText;
	GameText* ButtonTextPtr;
	float localX, localY;
};