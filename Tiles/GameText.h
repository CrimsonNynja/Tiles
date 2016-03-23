#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class GameText : public sf::Text
{
public:
	GameText();
	GameText(std::string InitialValue, sf::Font* font);
	void Throb(float Size, float Speed);
	void Shrink(float Size, float Speed);
	void Grow(float Size, float Speed);
	void Update();

private:
	sf::Clock Timer;
	sf::Time TimeElapsed;

	

};