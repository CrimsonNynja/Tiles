#include "GameText.h"

GameText::GameText()
{

}

GameText::GameText(std::string InitialValue, sf::Font* font, sf::Color Colour)
{
	this->setFont(*font);
	this->setString(InitialValue);
	this->setColor(Colour);
}

void GameText::Throb(float Size, float Speed)
{
	float sizeRate = Size / Speed;

	if (FunctPointer != &GameText::Throb)
	{
		FunctPointer = &GameText::Throb;
		size = Size;
		speed = Speed;
		bActive = true;
	} 
	else
	{
		if (bShrink == false)
		{
			this->setScale(getScale().x + sizeRate, getScale().y + sizeRate);
			if (this->getScale().x >= 1 + Size)
			{
				bShrink = true;
			}
		}
		else if (bShrink == true)
		{
			this->setScale(getScale().x - sizeRate, getScale().y - sizeRate);
			if (this->getScale().x <= 1 - Size || this->getScale().x <= 0) 
			{
				bShrink = false;
			}
		}
	}
}

void GameText::Shrink(float Size, float Speed) 
{
	if (FunctPointer != &GameText::Shrink) 
	{
		FunctPointer = &GameText::Shrink;
		size = Size;
		speed = Speed;
		bActive = true;
	} 
	else
	{
		float shrinkRate = (Size / Speed);
		this->setScale(getScale().x - shrinkRate, getScale().y - shrinkRate);

		if (this->getScale().x <= Size)
		{
			FunctPointer = &GameText::NFP;
		}
	}
}

void GameText::Grow(float Size, float Speed)
{
	if (FunctPointer != &GameText::Grow) 
	{
		FunctPointer = &GameText::Grow;
		size = Size;
		speed = Speed;
		bActive = true;
	} 
	else 
	{
		float growRate = (Size / Speed) / 2;
		this->setScale(getScale().x + growRate, getScale().y + growRate);

		if (this->getScale().x >= Size) 
		{
			FunctPointer = &GameText::NFP;
		}
	}
}

void GameText::ChangeColour(sf::Color ColourToChangeTo, float speed) 
{
	float HSB[] = {0,0,0};
	float ChangeToHSB[] = { 0,0,0 };
	RGBtoHSB(getColor().r, getColor().g, getColor().b, HSB);
	RGBtoHSB(ColourToChangeTo.r, ColourToChangeTo.g, ColourToChangeTo.b, ChangeToHSB);
	int RGB[3];
	if (HSB[0] - ChangeToHSB[0] >= speed) 
	{
		HSBtoRGB(ChangeToHSB[0], ChangeToHSB[1], ChangeToHSB[2], RGB);
	} 
	else 
	{
		HSB[0] += speed;
		HSBtoRGB(HSB[0], HSB[1], HSB[2], RGB);
	}
	setColor(sf::Color(RGB[0], RGB[1], RGB[2]));
}

void GameText::Stop() 
{
	FunctPointer = &GameText::NFP;
	bActive = false;
}

void GameText::Update() 
{
	if (bActive == true) 
	{
		TimeElapsed = Timer.getElapsedTime();

		if (TimeElapsed.asMilliseconds() >= speed) 
		{
			//ChangeColour(sf::Color::Blue, 0.0005);	//here as a test
			(*this.*FunctPointer)(size, speed);
			Timer.restart();
		}
	}
}

void GameText::RGBtoHSB(int r, int g, int b, float HSBValues[3]) 
{
	float hue, saturation, brightness;
	if (HSBValues == NULL) 
	{
		HSBValues = new float[3];
	}

	int cmax = (r > g) ? r : g;
	if (b > cmax) cmax = b;
	int cmin = (r < g) ? r : g;
	if (b < cmin) cmin = b;

	brightness = ((float) cmax) / 255.0f;
	if (cmax != 0)
		saturation = ((float) (cmax - cmin)) / ((float) cmax);
	else
		saturation = 0;
	if (saturation == 0)
		hue = 0;
	else 
	{
		float redc = ((float) (cmax - r)) / ((float) (cmax - cmin));
		float greenc = ((float) (cmax - g)) / ((float) (cmax - cmin));
		float bluec = ((float) (cmax - b)) / ((float) (cmax - cmin));

		if (r == cmax)
			hue = bluec - greenc;
		else if (g == cmax)
			hue = 2.0f + redc - bluec;
		else
			hue = 4.0f + greenc - redc;
		hue = hue / 6.0f;
		if (hue < 0)
			hue = hue + 1.0f;

	}
	HSBValues[0] = hue;
	HSBValues[1] = saturation;
	HSBValues[2] = brightness;
}

void GameText::HSBtoRGB(float hue, float saturation, float brightness,int RGB[3])
{
	int r = 0, g = 0, b = 0;
	if (saturation == 0) 
	{
		r = g = b = (int) (brightness * 255.0f + 0.5f);
	} 
	else 
	{
		float h = (hue - (float) floor(hue)) * 6.0f;
		float f = h - (float) floor(h);
		float p = brightness * (1.0f - saturation);
		float q = brightness * (1.0f - saturation * f);
		float t = brightness * (1.0f - (saturation * (1.0f - f)));
		switch ((int) h) 
		{
			case 0:
				r = (int) (brightness * 255.0f + 0.5f);
				g = (int) (t * 255.0f + 0.5f);
				b = (int) (p * 255.0f + 0.5f);
				break;
			case 1:
				r = (int) (q * 255.0f + 0.5f);
				g = (int) (brightness * 255.0f + 0.5f);
				b = (int) (p * 255.0f + 0.5f);
				break;
			case 2:
				r = (int) (p * 255.0f + 0.5f);
				g = (int) (brightness * 255.0f + 0.5f);
				b = (int) (t * 255.0f + 0.5f);
				break;
			case 3:
				r = (int) (p * 255.0f + 0.5f);
				g = (int) (q * 255.0f + 0.5f);
				b = (int) (brightness * 255.0f + 0.5f);
				break;
			case 4:
				r = (int) (t * 255.0f + 0.5f);
				g = (int) (p * 255.0f + 0.5f);
				b = (int) (brightness * 255.0f + 0.5f);
				break;
			case 5:
				r = (int) (brightness * 255.0f + 0.5f);
				g = (int) (p * 255.0f + 0.5f);
				b = (int) (q * 255.0f + 0.5f);
				break;
		}
	}
	RGB[0] = r;
	RGB[1] = g;
	RGB[2] = b;
}
