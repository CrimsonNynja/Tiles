#pragma once

#include <iostream>
#include <math.h>

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
	void ChangeColour(sf::Color ColourToChangeTo, float speed);
	void Stop();
	void Update();

private:
	void NFP(float a, float b) {};
	void RGBtoHSB(int r, int g, int b, float HSBValues[3]);
	void HSBtoRGB(float hue, float saturation, float brightness, int RGB[3]);

	sf::Clock Timer;
	sf::Time TimeElapsed;

	void(GameText::*FunctPointer)(float, float) = NULL;
	bool bShrink = false;

	float size = 1;
	float speed = 1000;

	bool bColorChangeComplete = false;

	bool bActive = false;

	float lastStaticSize = 1.0;	//may make function local
};