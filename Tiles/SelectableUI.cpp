#include "SelectableUI.h"

SelectableUI::SelectableUI()
{
	
}

SelectableUI::SelectableUI(sf::Texture * Inactive, sf::Texture * Hover, sf::Texture * Active, int Width, int Height)
{
	setImages(Inactive, Hover, Active, Width, Height);
}

void SelectableUI::setImages(sf::Texture * Inactive, sf::Texture * Hover, sf::Texture * Active, int Width, int Height)
{
	AnimTex.push_back(Inactive);
	AnimTex.push_back(Hover);
	AnimTex.push_back(Active);

	Anim.LoadAnimation(AnimTex[0], Width, Height);

	width = Width;
	height = Height;
}

void SelectableUI::setAnimSpeed(float Speed)
{
	Anim.setAnimSpeed(Speed);
}

void SelectableUI::setSelected(bool bTrue)
{
	bSelected = bTrue;
}

void SelectableUI::setActive(bool bTrue)
{
	bActive = bTrue;
}

bool SelectableUI::IsActive() const
{
	return bActive;
}

bool SelectableUI::IsSelected() const
{
	return bSelected;
}

void SelectableUI::EventUpdate(sf::RenderWindow& window, sf::Event& bevent)
{
	//do event handling and collision here

	if (Collision.TestMouseCollision(window) == true && bActive == false)
	{
		bHover = true;
		bSelected = true;
	}
	else
	{
		bHover = false;
		bSelected = false;
	}

	if (bSelected == true && bActive == false && bHover == true && bevent.type == sf::Event::MouseButtonReleased)
	{
		if (Collision.TestMouseCollision(window) == true && (bevent.mouseButton.button == sf::Mouse::Left))
		{
			bActive = true;
		}
	}
}

void SelectableUI::Update()
{
	__super::Update();

	//do anim setting here
	if (bSelected == false && bActive == false)
	{
		int frame = Anim.getCurrentFrame();
		Anim.LoadAnimation(AnimTex[0], width, height);
		Anim.setFrame(frame);
	}
	else
	{
		if (bHover == true)
		{
			int frame = Anim.getCurrentFrame();
			Anim.LoadAnimation(AnimTex[1], width, height);
			Anim.setFrame(frame);
		}
	}
	if (bActive == true)
	{
		int frame = Anim.getCurrentFrame();
		Anim.LoadAnimation(AnimTex[2], width, height);
		Anim.setFrame(frame);
	}
}
