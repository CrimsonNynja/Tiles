#pragma once
#include <vector>
#include "UIElement.h"

class SelectableUI : public GameSprite
{
public:
	SelectableUI();
	SelectableUI(sf::Texture* Inactive, sf::Texture* Hover, sf::Texture* Active, int Width, int Height);
	void setImages(sf::Texture* Inactive, sf::Texture* Hover, sf::Texture* Active, int Width, int Height);
	void setAnimSpeed(float Speed);
	void setSelected(bool bTrue);
	void setActive(bool bTrue);
	bool IsActive() const;
	bool IsSelected() const;
	void EventUpdate(sf::RenderWindow& window, sf::Event& bevent);
	void Update(sf::RenderWindow& window);	//to be used without event handling

protected:
	std::vector<sf::Texture*> AnimTex;
	int width, height;

	bool bSelected = false;
	bool bHover = false;
	bool bActive = false;
};