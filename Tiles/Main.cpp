#include <iostream>
#include <SFML/Graphics.hpp>

#include "TextureHandler.h"
#include "ImageHandler.h"
#include "INIReader.h"

#include "Menu.h"
#include "Board.h"

TextureHandler *TextureHandler::s_instance = 0;
ImageHandler *ImageHandler::s_instance = 0;

int main()
{
	sf::RenderWindow window(sf::VideoMode(
		stoi(getValueFromFile("FrameWidth", "Default.ini")),
		stoi(getValueFromFile("FrameHeight", "Default.ini"))),
		"Tiles v" + getValueFromFile("CurrentVersion", "Default.ini"));

	window.setVerticalSyncEnabled(StringToBool(getValueFromFile("V-syncEnabled", "Default.ini")));
	window.setFramerateLimit(stoi(getValueFromFile("FPSLimit", "Default.ini")));

	TextureHandler::instance()->setTexturePack("Default");
	Menu TilesMenu;

	Board TilesBoard;
	TilesBoard.CreateBoard();

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

		//Updates
		TilesMenu.Update(window);


		//draws
		window.clear(sf::Color::White);
		if (TilesMenu.getMenuState() == "UI-Play")
		{
			ImageHandler::instance()->Draw("Game", window);
		}
		else
		{
			ImageHandler::instance()->Draw(TilesMenu.getMenuState(), window);
		}
		window.display();
	}

	return 0;
}