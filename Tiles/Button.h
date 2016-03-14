#pragma once

#include "SelectableUI.h"
#include "GameText.h"

class Button : public SelectableUI
{
public:
	Button();
	void AddInnerImage();
	void AddText();
	void Update(sf::RenderWindow& window);

private:


};