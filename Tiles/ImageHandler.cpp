#include "ImageHandler.h"

void ImageHandler::AddToDrawList(GameSprite * obj)
{
	Drawables.push_back(obj);
	this->Sort();
}

void ImageHandler::AddToDrawList(sf::Text* UI)
{
	UIDawables.push_back(UI);
}

void ImageHandler::Draw(sf::RenderWindow & window)
{
	for (unsigned int i = 0; i < Drawables.size(); i ++)
	{
		window.draw(*Drawables[i]);
	}
	for (unsigned int i = 0; i < UIDawables.size(); i ++)
	{
		window.draw(*UIDawables[i]);
	}
}

void ImageHandler::Sort()
{
	for (unsigned int i = 0; i < Drawables.size(); i ++)
	{
		for (unsigned int j = 0; j < Drawables.size(); j++)
		{
			if (i != j)
			{
				if (Drawables[i]->getDrawLayer() > Drawables[j]->getDrawLayer())
				{
					std::iter_swap(Drawables.begin() + i, Drawables.begin() + j);
				}
			}
		}
	}
}
