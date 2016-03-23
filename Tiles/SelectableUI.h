#pragma once
#include <vector>
#include "UIElement.h"

class SelectableUI : public GameSprite
{
public:
	SelectableUI();
	SelectableUI(sf::Texture* Inactive, sf::Texture* Hover, sf::Texture* Active, int Width, int Height);
	void setImages(sf::Texture* Inactive, sf::Texture* Hover, sf::Texture* Active, int Width, int Height);
	void setSelected(bool bTrue);
	void setActive(bool bTrue);
	bool IsSelected() const;
	void Update(sf::RenderWindow& window);	//Overload

protected:
	std::vector<sf::Texture*> AnimTex;
	int width, height;

	bool bSelected = false;
	bool bHover = false;
	bool bActive = false;
};