#include <SFML/Graphics.hpp>

#include "Button.h"
#include "ParticleEmitter.h"
#include "CheckBox.h"
#include "INIReader.h"
#include "Entity.h"
#include "CollisionManager.h"

int main()
{
	sf::Texture Test;
	Test.loadFromFile(getValueFromFile("Directory", "Default.ini") + "ButtonTest.png");

	sf::Font Akashi;
	Akashi.loadFromFile(getValueFromFile("Directory", "Default.ini") + "Akashi.ttf");

	sf::RenderWindow window(sf::VideoMode(
		stoi(getValueFromFile("FrameWidth", "Default.ini")), 
		stoi(getValueFromFile("FrameHeight", "Default.ini"))), 
		"Engine Test");
	
	window.setVerticalSyncEnabled(StringToBool(getValueFromFile("V-syncEnabled", "Default.ini")));
	window.setFramerateLimit(stoi(getValueFromFile("FPSLimit", "Default.ini")));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear(sf::Color::White);
		window.display();
	}

	return 0;
}