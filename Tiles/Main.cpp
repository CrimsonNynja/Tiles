#include <SFML/Graphics.hpp>

#include "GameSprite.h"
#include "Animation.h"

int main()
{

	sf::Texture Test;
	Test.loadFromFile("C:\\Users\\hudoc\\Desktop\\TestAnim.png");
	GameSprite Test_Spr;
//	sf::Sprite Test_Spr;
	Test_Spr.setPosition(100, 100);
	Animation TestAnim(&Test_Spr, &Test, 144, 224);
	TestAnim.setAnimSpeed(200);

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Tiles");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		TestAnim.Update();

		window.clear(sf::Color::White);
		window.draw(Test_Spr);
		window.display();
	}

	return 0;
}