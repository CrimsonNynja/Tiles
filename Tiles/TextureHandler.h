#pragma once

#include <map>
#include <string>

#include "SFML/Graphics.hpp"
#include "INIReader.h"

class TextureHandler
{
public:
	static TextureHandler *s_instance;
	TextureHandler();

	static TextureHandler *instance()
	{
		if (!s_instance)
			s_instance = new TextureHandler;
		return s_instance;
	}

	sf::Texture* getTexture(std::string TextureName);
	sf::Font* getFont();
	void setTexturePack(std::string TexturePackName);
	std::string getTexturePack();
	void ReloadTextures();

private:
	std::map<std::string, std::map<std::string, sf::Texture*>> Textures;
	sf::Font Akashi;

	std::string currentTexturePack = "NONE";

};