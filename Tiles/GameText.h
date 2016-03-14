#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class GameText : public sf::Text
{
public:
	GameText();
	GameText(std::string InitialValue);
	void Throb(float Size, float Speed);
	void Shrink(float Size);
	void Grow(float Size);
	void Update();

private:


};