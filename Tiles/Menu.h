#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "TextureHandler.h"
#include "ImageHandler.h"
#include "Button.h"
#include "CheckBox.h"
#include "UIContainer.h"

//used to decide if operating on a computer of mobile device
#define DEVICETYPE "MOBILE"

class Menu
{
public:
	Menu();

	void Update(sf::RenderWindow& window);
	std::string getMenuState();
	void Exit(sf::RenderWindow& window);

private:
	//on the main menu screen
	void Play();
	void MainMenu(sf::RenderWindow& window);
	void Options();
	void Shop();

	//for the pause menu overlay
	void Pause();
	void PauseOptions();
	void PauseToMain();

	//general variables
	enum MenuStates
	{
		MAIN,
		OPTIONS,
		SHOP,
		PAUSE,
		PLAY
	};
	MenuStates menuState = MAIN;

	//general Menu items
	sf::Text MenuTitle;

	//main menu items
	Button PlayBtn;
	Button OptionBtn;
	Button ShopBtn;
	Button QuitBtn;
};