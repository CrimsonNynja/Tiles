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

void CheckBox::EventUpdate(sf::RenderWindow & window, sf::Event & bevent)
{
	if (bActive == false)
	{
		__super::EventUpdate(window, bevent);
	}
	else
	{
		if (bevent.type == sf::Event::MouseButtonReleased)
		{
			if (Collision.TestMouseCollision(window) == true && (bevent.mouseButton.button == sf::Mouse::Left))
			{
				bActive = false;
			}
		}
	}
}

void CheckBox::Update()		//need an event handler, so that the checkbox can be unchecked
{
	std::cout << bActive << std::endl;
	__super::Update();

	if (state != nullptr)
	{
		if (bActive == true)
		{
			*state = true;
		}
		else
		{
			*state = false;
		}
	}
}