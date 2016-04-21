#pragma once

#include <SFML/Graphics.hpp>
#include <algorithm>

#include "GameSprite.h"

class ImageHandler
{
public:
	static ImageHandler *s_instance;
	ImageHandler() {}

	static ImageHandler *instance()
	{
		if (!s_instance)
			s_instance = new ImageHandler;
		return s_instance;
	}

	void AddToDrawList(GameSprite* obj);
	void AddToDrawList(sf::Text* UI);
	void Draw(sf::RenderWindow& window);

private:
	void Sort();

	std::vector<GameSprite*> Drawables;
	std::vector<sf::Text*> UIDawables;

};