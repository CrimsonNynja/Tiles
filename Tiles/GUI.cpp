#include "GUI.h"

GUI::GUI()
{
	Score.setPosition(1920 - 300, 25);
	ImageHandler::instance()->AddToDrawList("Game", &Score);

	Timer.setPosition(1920 - 300, 70);
	ImageHandler::instance()->AddToDrawList("Game", &Timer);

	Currency.setPosition(-200, -200);
	Currency.setColor(sf::Color(0, 255, 50, 150));
	ImageHandler::instance()->AddToDrawList("Game", &Currency);
}

void GUI::AddScore(int ammount)
{
	Score.setString("Score: " + std::to_string(ammount));
	Score.Throb(0.2, 10);
}

void GUI::AddCurrency(int ammount, sf::Vector2f position)
{
	CurrencyLastPosition = position;
	Currency.setPosition(position);
	Currency.setString("+ " + std::to_string(ammount) + " Coin");
	Currency.Throb(0.2, 20);
	bMoveCurrencyText = true;
}

void GUI::setTimer(int Time)
{
	Timer.setString(std::to_string(Time) + " sec");
}

void GUI::Update()
{
	Score.Update();
	Timer.Update();
	Currency.Update();

//	std::cout << Score.getScale().x << std::endl;
	if (Score.getScale().x < 1)
	{
		Score.Stop();
		Score.setScale(1.f, 1.f);
	}

	if (bMoveCurrencyText == true)
	{
		Currency.setPosition(Currency.getPosition().x, Currency.getPosition().y - 1);
		if (Currency.getPosition().y < CurrencyLastPosition.y - 40)
		{
			bMoveCurrencyText = false;
			Currency.setPosition(-200, -200);
		}
	}
}