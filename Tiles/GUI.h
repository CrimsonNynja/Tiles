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
	void AddCurrency(int ammount, sf::Vector2f position);		//need a position to place this, as it will come out of the gem
	void setTimer(int Time);
	
	void Update();

private:
	GameText Score{"Score: 0", TextureHandler::instance()->getFont(), sf::Color::Black};
	GameText Timer{"Timer: 0s", TextureHandler::instance()->getFont(), sf::Color::Black};
	GameText Currency{ "0 Coins", TextureHandler::instance()->getFont(), sf::Color::Black };

	sf::Vector2f CurrencyLastPosition;

	bool bMoveCurrencyText = false;
};