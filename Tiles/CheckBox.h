#pragma once

#include "SelectableUI.h"

class CheckBox : public SelectableUI
{
public:
	CheckBox();
	CheckBox(bool* Variable);
	bool IsChecked();
	void EventUpdate(sf::RenderWindow& window, sf::Event& bevent);
	void Update();

private:
	bool* state = nullptr;

};