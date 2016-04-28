#include "ImageHandler.h"

void ImageHandler::AddToDrawList(std::string ListName, GameSprite* obj)
{
	Drawables[ListName].push_back(obj);
	this->Sort(ListName);
}

void ImageHandler::AddToDrawList(std::string ListName, sf::Text* UI)
{
	UIDawables[ListName].push_back(UI);
}

void ImageHandler::Draw(std::string ListName, sf::RenderWindow & window)
{
	for (unsigned int i = 0; i < Drawables[ListName].size(); i ++)
	{
		window.draw(*Drawables[ListName][i]);
	}
	for (unsigned int i = 0; i < UIDawables[ListName].size(); i ++)
	{
		window.draw(*UIDawables[ListName][i]);
	}
}

void ImageHandler::Sort(std::string ListName)
{
	for (unsigned int i = 0; i < Drawables[ListName].size(); i ++)
	{
		for (unsigned int j = 0; j < Drawables[ListName].size(); j++)
		{
			if (i != j)
			{
				if (Drawables[ListName][i]->getDrawLayer() > Drawables[ListName][j]->getDrawLayer())
				{
					std::iter_swap(Drawables[ListName].begin() + i, Drawables[ListName].begin() + j);
				}
			}
		}
	}
}
