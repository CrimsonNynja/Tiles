#include "CheckBox.h"

CheckBox::CheckBox()
{
}

CheckBox::CheckBox(bool* Variable)
{
	state = Variable;
}

bool CheckBox::IsChecked()
{
	return bActive;
}

void CheckBox::Update(sf::RenderWindow& window)		//need an event handler, so that the checkbox can be unchecked
{
	__super::Update(window);

	if (bActive == true)
	{
		*state = true;
	}
	else
	{
		*state = false;
	}
}