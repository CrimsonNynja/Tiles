#pragma once

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <map>

#include "GameSprite.h"

#define ImgHandler ImageHandler::instance()

//make later so that the game does nbot draw that which is off screen

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

	void AddToDrawList(std::string ListName, GameSprite* obj);
	void AddToDrawList(std::string, sf::Text* UI);
	void Draw(std::string ListName, sf::RenderWindow& window);
	void Sort(std::string ListName);		//slow if used on every add, so need to use it only after adding most items


private:
	std::map<std::string, std::vector<GameSprite*>> Drawables;
	std::map<std::string, std::vector<sf::Text*>> UIDawables;

};