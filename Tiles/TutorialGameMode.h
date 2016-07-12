#pragma once

#include "GameMode.h"
#include "Button.h"

class TutorialGameMode : public GameMode
{
public:
	TutorialGameMode();
	void Initialize();
	void EventUpdate(sf::Event event);
	void Update();

private:
	/* relating to tutorial messages */
	void UpdateTutorial();
	bool bPaused = false;
	bool bTaskDone = false;
	Button TextBox;
	GameText MessageText{ "", TexHandler->getFont(), sf::Color::Black };
	GameText TooltipText{ "", TexHandler->getFont(), sf::Color::Black };
	unsigned int messageIndex = 0;
	unsigned int tooltipIndex = 0;
	unsigned short moveDirectionCount = 0;
	std::vector<std::string> TutorialMessages
	{
		"Hello, and Welcome to 'Tiles'",
		
		"Before you start, lets show you how the game works",

		"Lets start by moving the player, by using the arrow keys or WASD",

		"Good Job. These shiny orbs that just spawned are pickups",

		"Pickups increace your score, and come in a few different colours",

		"Try picking a few up now",
		
		"Look, a gold coin has just spawned", 
		
		"These can be used to unlock different skins, themes, and games types",

		"However, they are quite rare, better pick this one up",

		"Nice, now the basic board mechanics will be explained",

		"As the game goes along, the board will get harder to navigate",

		"When the board does something, we say it is mutating",

		"Lets have a look at the most basic mutations",

		"The most common mutation is the board moving a row or collumn",
		
		"lets see that in action",

		"",

		"The other most common mutation, is a dissapearing tile",

		"",

		"As you can see, where once there was a tile, there now is none"	

		//add extra later, when there are more features to add
	};
	std::vector<std::string> ToolTips
	{
		"Press anything to continue",

		"Move the player UP, DOWN, LEFT and RIGHT",

		"Collect 3 pickups",

		"Collect the gold coin",

		"Wait for a row of collumn to move",

		"Wait for a tile to dissapear"

		//as above
	};
};