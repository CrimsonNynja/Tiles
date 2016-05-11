#include "GUI.h"

GUI::GUI()
{
	Score.setPosition(1920 - 300, 25);
	ImageHandler::instance()->AddToDrawList("Game", &Score);

	Timer.setPosition(1920 - 300, 70);
	ImageHandler::instance()->AddToDrawList("Game", &Timer);
}

void GUI::AddScore(int ammount)
{
	Score.setString("Score: " + std::to_string(ammount));
	Score.Throb(0.3, 10);

}

void GUI::Update()
{
	Score.Update();
	Timer.Update();

//	std::cout << Score.getScale().x << std::endl;
	if (Score.getScale().x < 1)
	{
		Score.Stop();
		Score.setScale(1.f, 1.f);
	}
}