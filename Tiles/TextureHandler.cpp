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
	Textures[currentTexturePack]["MenuCardIA"].loadFromFile(getValueFromFile("Directory", "Default.ini") + "MenuCard.png");
	Textures[currentTexturePack]["MenuCardH"].loadFromFile(getValueFromFile("Directory", "Default.ini") + "MenuCardHover.png");
	Textures[currentTexturePack]["MenuCardA"].loadFromFile(getValueFromFile("Directory", "Default.ini") + "MenuCardActive.png");
}
