#pragma once

#include "SelectableUI.h"

class CheckBox : public SelectableUI
{
public:
	CheckBox();
	CheckBox(bool* Variable);
	bool IsChecked();
	void Update();

private:
	bool* State;

};