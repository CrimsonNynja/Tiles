#pragma once

#include "SelectableUI.h"
#include "GameText.h"

class Button : public SelectableUI
{
public:
	Button();
	void AddInnerImage();
	void AddText(std::string Text, sf::Font* Font, sf::Color Colour, float LocalX, float LocalY);
	void AddText(GameText* GameText, float LocalX, float LocalY);
	void CenterText();
	GameText* getText() const;
	void Update(sf::RenderWindow& window);

private:
	GameText ButtonText;
	GameText* ButtonTextPtr;
	float localX, localY;
};