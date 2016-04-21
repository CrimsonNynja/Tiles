#include "Menu.h"

Menu::Menu()
{
	//Menu Title Text
	MenuTitle.setFont(*TextureHandler::instance()->getFont());
	MenuTitle.setCharacterSize(70);
	MenuTitle.setColor(sf::Color::Black);
	MenuTitle.setPosition((std::stoi(getValueFromFile("FrameWidth", "Default.ini")) / 2) - 100, 50);	//change to proper position later
	MenuTitle.setString("Tiles");
	ImageHandler::instance()->AddToDrawList(&MenuTitle);



}
