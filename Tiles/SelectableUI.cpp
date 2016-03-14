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

void SelectableUI::setSelected(bool bTrue)
{
	bSelected = bTrue;
}

bool SelectableUI::IsSelected() const
{
	return bSelected;
}

void SelectableUI::Update(sf::RenderWindow& window)
{
	__super::Update();

	if (Collision.TestMouseCollision(window) == true)
	{
		bHover = true;
		bSelected = true;
	}
	else
	{
		bHover = false;
		bSelected = false;
	}

	if (bSelected == false)
	{
		Anim.LoadAnimation(AnimTex[0], width, height);
	}
	else
	{
		if (bHover == true)
		{
			Anim.LoadAnimation(AnimTex[1], width, height);

			if (Collision.TestMouseCollision(window) == true && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
			{
				bActive = true;
			}
		}
	}
	if (bActive == true)
	{
		Anim.LoadAnimation(AnimTex[2], width, height);
	}
}
