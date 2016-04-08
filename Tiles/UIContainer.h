#pragma once

#include <vector>
#include "SelectableUI.h"

class UIContainer
{
public:
	UIContainer();
	void AddElement(SelectableUI* Element);
	void Update(sf::RenderWindow& window);

private:
	std::vector<SelectableUI*> Container;
	unsigned int selected = 0;		//controller only
};