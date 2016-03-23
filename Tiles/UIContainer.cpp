#include "UIContainer.h"

UIContainer::UIContainer()
{
}

void UIContainer::AddElement(SelectableUI * Element)
{
	Container.push_back(Element);
}

void UIContainer::Update(sf::RenderWindow& window)
{
	for (auto x: Container)
	{
		x->Update(window);

		if (sf::Joystick::isConnected(0) == true)
		{	//test. need to add hover, and clicking A suport later
			Container[selected]->setActive(true);

			if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 40)
			{
				if (selected < Container.size() - 1)
				{
					selected += 1;
					Container[selected - 1]->setActive(false);
				}
			/*	else if (selected == Container.size() - 1)
				{
					selected = 0;
					Container[Container.size() - 1]->setActive(false);
				}	//*/
			}
			else if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) <- 40)
			{
			//	if ()
			//	{

			//	}
			}
		}
	}
}
