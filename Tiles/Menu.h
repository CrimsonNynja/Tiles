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
#define DEVICETYPE PC

class Menu
{
public:
	Menu();

	void Update();
	void Exit();

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

	sf::Text MenuTitle;
};