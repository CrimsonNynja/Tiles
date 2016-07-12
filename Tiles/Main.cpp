#include <iostream>
#include <SFML/Graphics.hpp>

#include "CollisionManager.h"

#include "TextureHandler.h"
#include "ImageHandler.h"
#include "INIReader.h"

#include "Menu.h"
#include "Profile.h"

#include "GameMode.h"
#include "DefaultGameType.h"
#include "TutorialGameMode.h"

TextureHandler *TextureHandler::s_instance = 0;
ImageHandler *ImageHandler::s_instance = 0;

int main()
{
	ChangeValue("CurrentVersion", "0.04", "Default.ini");

	sf::RenderWindow window(sf::VideoMode(
		stoi(getValueFromFile("FrameWidth", "Default.ini")),
		stoi(getValueFromFile("FrameHeight", "Default.ini"))),
		"Tiles v" + getValueFromFile("CurrentVersion", "Default.ini"));

	window.setKeyRepeatEnabled(false);
	window.setVerticalSyncEnabled(StringToBool(getValueFromFile("V-syncEnabled", "Default.ini")));		//need to alow these to change on the fly later, mabee oput them in the option update section
	window.setFramerateLimit(stoi(getValueFromFile("FPSLimit", "Default.ini")));

	TexHandler->setTexturePack("Default");
	Menu TilesMenu;

	Profile PlayerProfile;
	DefaultGameType gameMode;
	//TutorialGameMode gameMode;

	gameMode.Initialize();
	//TilesBoard.PlacePlayer(&Player, 0, 0);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))		//add an exception so that when an error is sent when a computer resumes from hybnernation, the game doesnt crash
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)//&& Player.IsMoving() == false	//half works
			{
				if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
				{
					gameMode.getPlayer()->Move("up");
				}
				if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
				{
					gameMode.getPlayer()->Move("down");
				}
				if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
				{
					gameMode.getPlayer()->Move("left");
				}
				if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
				{
					gameMode.getPlayer()->Move("right");
				}
			}

			TilesMenu.EventUpdate(window, event);
			if (TilesMenu.getMenuState() == "UI-Play")
			{
	//			gameMode.EventUpdate(event);
			}
		}

		TilesMenu.Update();
		if (TilesMenu.getMenuState() == "UI-Play")
		{
			gameMode.Update();
		}

		if (TilesMenu.getMenuState() == "UI-Menu")		//optomise this later
		{
		//	TilesBoard.Reset();
		//	TilesBoard.PlacePlayer(&Player, 0, 0);
		}

		//draws
		window.clear(sf::Color::White);
		if (TilesMenu.getMenuState() == "UI-Play" || TilesMenu.getMenuState() == "UI-Pause")
		{
			ImgHandler->Draw("Game", window);
			if (TilesMenu.getMenuState() == "UI-Pause")
			{
				ImgHandler->Draw(TilesMenu.getMenuState(), window);
			}
		}
		else
		{
			ImgHandler->Draw(TilesMenu.getMenuState(), window);
		}
		window.display();
	}

	return 0;
}