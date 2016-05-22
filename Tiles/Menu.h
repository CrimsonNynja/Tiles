#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "GameText.h"
#include "TextureHandler.h"
#include "ImageHandler.h"
#include "Button.h"
#include "CheckBox.h"
#include "UIContainer.h"

//used to decide if operating on a computer of mobile device
#define DEVICETYPE "MOBILE"

class Menu		//still need to find a place to put the high score at
{
public:
	Menu();

	void EventUpdate(sf::RenderWindow& window, sf::Event& bevent);
	void Update();
	std::string getMenuState();
	bool IsPaused();
	void Exit(sf::RenderWindow& window);

private:
	//on the main menu screen
	void Play();
	void MainMenu();
	void Options();
	void Shop();

	//for the pause menu overlay
	void Pause();
	void PauseOptions();
	void PauseToMain();

	//general
	void ResetButtons();

	//general variables
	enum MenuStates
	{
		MAIN,
		OPTIONS,
		SHOP,
		PAUSE,
		PLAY
	}menuState = MAIN;
	//MenuStates menuState = MAIN;

	//general Menu items
	sf::Text MenuTitle;
	Button BackBtn;

	//main menu items
	UIContainer MainContainer;
	Button PlayBtn;
	Button OptionBtn;
	Button ShopBtn;
	Button QuitBtn;

	//options Items
	CheckBox VSyncBox;
	GameText VSyncText;

	//menu variables

};