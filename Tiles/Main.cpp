#include <iostream>
#include <SFML/Graphics.hpp>

#include "CollisionManager.h"

#include "TextureHandler.h"
#include "ImageHandler.h"
#include "INIReader.h"

#include "Menu.h"
#include "Board.h"
#include "TilesPlayer.h"
#include "Profile.h"

TextureHandler *TextureHandler::s_instance = 0;
ImageHandler *ImageHandler::s_instance = 0;

int main()
{
	sf::RenderWindow window(sf::VideoMode(
		stoi(getValueFromFile("FrameWidth", "Default.ini")),
		stoi(getValueFromFile("FrameHeight", "Default.ini"))),
		"Tiles v" + getValueFromFile("CurrentVersion", "Default.ini"));

	window.setKeyRepeatEnabled(false);
	window.setVerticalSyncEnabled(StringToBool(getValueFromFile("V-syncEnabled", "Default.ini")));
	window.setFramerateLimit(stoi(getValueFromFile("FPSLimit", "Default.ini")));

	TextureHandler::instance()->setTexturePack("Default");
	Menu TilesMenu;		//only sets itsself after moving the mouse once, due to the events

	Board TilesBoard;
	TilesPlayer Player;
	Profile PlayerProfile;

	TilesBoard.CreateBoard();

	TilesBoard.PlacePlayer(&Player, 0, 0);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)//&& Player..IsMoving() == false	//half works
			{
				if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
				{
					Player.Move("up");
				}
				if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
				{
					Player.Move("down");
				}
				if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
				{
					Player.Move("left");
				}
				if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
				{
					Player.Move("right");
				}

//				if (event.key.code == sf::Keyboard::Escape)
//				{
//					//pause the game, bring up the pause menu
//				}
			}

			//Updates
			TilesMenu.Update(window, event);		//only updates the menu when a mouse or key does something
		}
		if (TilesMenu.getMenuState() == "UI-Play")
		{
			TilesBoard.Update();
			Player.Update();
		}

		//draws
		window.clear(sf::Color::White);
		if (TilesMenu.getMenuState() == "UI-Play" || TilesMenu.getMenuState() == "UI-Pause")
		{
			ImageHandler::instance()->Draw("Game", window);
			if (TilesMenu.getMenuState() == "UI-Pause")
			{
				ImageHandler::instance()->Draw(TilesMenu.getMenuState(), window);
			}
		}
		else
		{
			ImageHandler::instance()->Draw(TilesMenu.getMenuState(), window);
		}
		window.display();
	}

	return 0;
}