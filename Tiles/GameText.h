#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class GameText : public sf::Text
{
public:
	GameText();
	GameText(std::string InitialValue, sf::Font* font, sf::Color Colour);
	void Throb(float Size, float Speed);
	void Shrink(float Size, float Speed);
	void Grow(float Size, float Speed);
	//add a colout morph function, that can be used while the other 3 are in effect
	void Stop();
	void Update();

private:
	sf::Clock Timer;
	sf::Time TimeElapsed;

	bool bActive = false;

	float lastStaticSize = 1.0;	//may make function local
};