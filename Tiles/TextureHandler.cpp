#include "TextureHandler.h"

TextureHandler::TextureHandler()
{
	Akashi.loadFromFile(getValueFromFile("Directory", "Default.ini") + "Akashi.ttf");
	this->ReloadTextures();
}

sf::Texture* TextureHandler::getTexture(std::string TextureName)
{
	return &Textures[currentTexturePack][TextureName];
}

sf::Font* TextureHandler::getFont()
{
	return &Akashi;
}

void TextureHandler::setTexturePack(std::string TexturePackName)
{
	currentTexturePack = TexturePackName;
}

std::string TextureHandler::getTexturePack()
{
	return currentTexturePack;
}

void TextureHandler::ReloadTextures()
{
//potentially seperate the loaded images from device type
	//all texture to be loaded in here
	Textures[currentTexturePack]["m-MenuCardIA"].loadFromFile(getValueFromFile("Directory", "Default.ini") + "MenuCard.png");
	Textures[currentTexturePack]["m-MenuCardH"].loadFromFile(getValueFromFile("Directory", "Default.ini") + "MenuCardHover.png");
	Textures[currentTexturePack]["m-MenuCardA"].loadFromFile(getValueFromFile("Directory", "Default.ini") + "MenuCardActive.png");

	Textures[currentTexturePack]["p-MenuCardIA"].loadFromFile(getValueFromFile("Directory", "Default.ini") + "PCButtonIA.png");
	Textures[currentTexturePack]["p-MenuCardH"].loadFromFile(getValueFromFile("Directory", "Default.ini") + "PCButtonH.png");
	Textures[currentTexturePack]["p-MenuCardA"].loadFromFile(getValueFromFile("Directory", "Default.ini") + "PCButtonA.png");

	Textures[currentTexturePack]["CheckBoxIA"].loadFromFile(getValueFromFile("Directory", "Default.ini") + "InactiveT.png");
	Textures[currentTexturePack]["CheckBoxH"].loadFromFile(getValueFromFile("Directory", "Default.ini") + "HoverT.png");
	Textures[currentTexturePack]["CheckBoxA"].loadFromFile(getValueFromFile("Directory", "Default.ini") + "ActiveT.png");

	Textures[currentTexturePack]["Tile"].loadFromFile(getValueFromFile("Directory", "Default.ini") + "Tile_Temp.png");
	Textures[currentTexturePack]["Pickup"].loadFromFile(getValueFromFile("Directory", "Default.ini") + "Pickup.png");

	Textures[currentTexturePack]["Player"].loadFromFile(getValueFromFile("Directory", "Default.ini") + "TestPlayer.png");

	Textures[currentTexturePack]["BackButton"].loadFromFile(getValueFromFile("Directory", "Default.ini") + "BackButton.png");
	Textures[currentTexturePack]["BackButtonH"].loadFromFile(getValueFromFile("Directory", "Default.ini") + "BackButtonHover.png");

	Textures[currentTexturePack]["PauseCard"].loadFromFile(getValueFromFile("Directory", "Default.ini") + "PauseCard.png");
	Textures[currentTexturePack]["PauseButtonIA"].loadFromFile(getValueFromFile("Directory", "Default.ini") + "Inactive.png");
	Textures[currentTexturePack]["PauseButtonH"].loadFromFile(getValueFromFile("Directory", "Default.ini") + "Hover.png");

//	for (unsigned int i = 0; i < Textures[currentTexturePack].size(); i ++)
//	{		
//		Textures[currentTexturePack][i].setSmooth(StringToBool(getValueFromFile("Antialiasing", "Default.ini")));
//	}
//	Textures[currentTexturePack][""].setSmooth(StringToBool(getValueFromFile("Antialiasing", "Default.ini")));
}
