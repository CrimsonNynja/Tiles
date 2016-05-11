#pragma once

#include <SFML/System.hpp>
#include "ImageHandler.h"
#include "TextureHandler.h"
#include "GameText.h"

class GUI
{
public:
	GUI();
	void AddScore(int ammount);
	void Update();

private:
	GameText Score{"Score: 0", TextureHandler::instance()->getFont(), sf::Color::Black};
	GameText Timer{"Timer: 0s", TextureHandler::instance()->getFont(), sf::Color::Black};


};