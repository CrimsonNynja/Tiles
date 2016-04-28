#include "Menu.h"

Menu::Menu()
{
	//Menu Title Text
	MenuTitle.setFont(*TextureHandler::instance()->getFont());
	MenuTitle.setCharacterSize(70);
	MenuTitle.setColor(sf::Color::Black);
	MenuTitle.setPosition((std::stoi(getValueFromFile("FrameWidth", "Default.ini")) / 2) - 100.f, 50);
	MenuTitle.setString("Tiles");
	ImageHandler::instance()->AddToDrawList("UI", &MenuTitle);

	if (DEVICETYPE == "PC")
	{
	//MAIN MENU
		//Play Button
		MainContainer.AddElement(&PlayBtn);
		PlayBtn.setImages(TextureHandler::instance()->getTexture("p-MenuCardIA"),
			TextureHandler::instance()->getTexture("p-MenuCardH"),
			TextureHandler::instance()->getTexture("p-MenuCardA"), 490, 150);
		PlayBtn.setPosition(160, 290);
		PlayBtn.AddText("Play", TextureHandler::instance()->getFont(), sf::Color::Black, 35, 0, 0);
		PlayBtn.CenterText();
		ImageHandler::instance()->AddToDrawList("UI-Menu", &PlayBtn);
		ImageHandler::instance()->AddToDrawList("UI-Menu", PlayBtn.getText());

		//Options Button
		MainContainer.AddElement(&OptionBtn);
		OptionBtn.setImages(TextureHandler::instance()->getTexture("p-MenuCardIA"),
			TextureHandler::instance()->getTexture("p-MenuCardH"),
			TextureHandler::instance()->getTexture("p-MenuCardA"), 490, 150);
		OptionBtn.setPosition(315, 490);
		OptionBtn.AddText("Options", TextureHandler::instance()->getFont(), sf::Color::Black, 35, 0, 0);
		OptionBtn.CenterText();
		ImageHandler::instance()->AddToDrawList("UI-Menu", &OptionBtn);
		ImageHandler::instance()->AddToDrawList("UI-Menu", OptionBtn.getText());

		//Shop Button
		MainContainer.AddElement(&ShopBtn);
		ShopBtn.setImages(TextureHandler::instance()->getTexture("p-MenuCardIA"),
			TextureHandler::instance()->getTexture("p-MenuCardH"),
			TextureHandler::instance()->getTexture("p-MenuCardA"), 490, 150);
		ShopBtn.setPosition(315, 705);
		ShopBtn.AddText("Shop", TextureHandler::instance()->getFont(), sf::Color::Black, 35, 0, 0);
		ShopBtn.CenterText();
		ImageHandler::instance()->AddToDrawList("UI-Menu", &ShopBtn);
		ImageHandler::instance()->AddToDrawList("UI-Menu", ShopBtn.getText());

		//Quit Button
		MainContainer.AddElement(&QuitBtn);
		QuitBtn.setImages(TextureHandler::instance()->getTexture("p-MenuCardIA"),
			TextureHandler::instance()->getTexture("p-MenuCardH"),
			TextureHandler::instance()->getTexture("p-MenuCardA"), 490, 150);
		QuitBtn.setPosition(160, 900);
		QuitBtn.AddText("Quit", TextureHandler::instance()->getFont(), sf::Color::Black, 35, 0, 0);
		QuitBtn.CenterText();
		ImageHandler::instance()->AddToDrawList("UI-Menu", &QuitBtn);
		ImageHandler::instance()->AddToDrawList("UI-Menu", QuitBtn.getText());
	}
	else if (DEVICETYPE == "MOBILE")
	{
	//MAIN MENU
		//Play Button
		PlayBtn.setImages(TextureHandler::instance()->getTexture("m-MenuCardIA"),
			TextureHandler::instance()->getTexture("m-MenuCardH"),
			TextureHandler::instance()->getTexture("m-MenuCardA"), 450, 690);
		PlayBtn.setPosition(30, 360);
		PlayBtn.AddText("Play", TextureHandler::instance()->getFont(), sf::Color::White, 35, 0, 0);
		PlayBtn.CenterText();
		ImageHandler::instance()->AddToDrawList("UI-Menu", &PlayBtn);
		ImageHandler::instance()->AddToDrawList("UI-Menu", PlayBtn.getText());

		//Options Button
		OptionBtn.setImages(TextureHandler::instance()->getTexture("m-MenuCardIA"),
			TextureHandler::instance()->getTexture("m-MenuCardH"),
			TextureHandler::instance()->getTexture("m-MenuCardA"), 450, 690);
		OptionBtn.setPosition(505, 360);
		OptionBtn.AddText("Options", TextureHandler::instance()->getFont(), sf::Color::White, 35, 0, 0);
		OptionBtn.CenterText();
		ImageHandler::instance()->AddToDrawList("UI-Menu", &OptionBtn);
		ImageHandler::instance()->AddToDrawList("UI-Menu", OptionBtn.getText());

		//Shop Button
		ShopBtn.setImages(TextureHandler::instance()->getTexture("m-MenuCardIA"),
			TextureHandler::instance()->getTexture("m-MenuCardH"),
			TextureHandler::instance()->getTexture("m-MenuCardA"), 450, 690);
		ShopBtn.setPosition(980, 360);
		ShopBtn.AddText("Shop", TextureHandler::instance()->getFont(), sf::Color::White, 35, 0, 0);
		ShopBtn.CenterText();
		ImageHandler::instance()->AddToDrawList("UI-Menu", &ShopBtn);
		ImageHandler::instance()->AddToDrawList("UI-Menu", ShopBtn.getText());

		//Quit Button
		QuitBtn.setImages(TextureHandler::instance()->getTexture("m-MenuCardIA"),
			TextureHandler::instance()->getTexture("m-MenuCardH"),
			TextureHandler::instance()->getTexture("m-MenuCardA"), 450, 690);
		QuitBtn.setPosition(1455, 360);
		QuitBtn.AddText("Quit", TextureHandler::instance()->getFont(), sf::Color::White, 35, 0, 0);
		QuitBtn.CenterText();
		ImageHandler::instance()->AddToDrawList("UI-Menu", &QuitBtn);
		ImageHandler::instance()->AddToDrawList("UI-Menu", QuitBtn.getText());
	}
}

void Menu::Update(sf::RenderWindow& window)
{
	switch (menuState)
	{
	case MAIN:
		this->MainMenu(window);
		break;
	case OPTIONS:
		this->Options();
		break;
	case SHOP:
		this->Shop();
		break;
//	case PAUSE:
//		this->Pause();
//		break;
	case PLAY:
		this->Play();
		break;
	}
}

std::string Menu::getMenuState()
{
	switch (menuState)
	{
	case MAIN:
		return "UI-Menu";
		break;
	case OPTIONS:
		return "UI-Options";
		break;
	case SHOP:
		return "UI-Shop";
		break;
	case PAUSE:
		return "UI-Pause";
		break;
	case PLAY:
		return "UI-Play";
		break;
//	default:
//		return "UI-Main";
//		break;
	}
}

bool Menu::IsPaused()
{
	if (menuState == PAUSE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Menu::Exit(sf::RenderWindow& window)
{
	window.close();
}

void Menu::Play()
{
	//test is the pause button has been pressed, and if so, go to the pause menu
}

void Menu::MainMenu(sf::RenderWindow& window)
{
	MenuTitle.setString("Tiles");
	
	//updates
//	if (DEVICETYPE == "PC")
	{
		MainContainer.Update(window);	//this stops the text from centering as it probably need to push a cast
	}
//	else
	{
		PlayBtn.Update(window);
		OptionBtn.Update(window);
		ShopBtn.Update(window);
		QuitBtn.Update(window);
	}

	//tests
	if (PlayBtn.IsActive() == true)
	{
		menuState = PLAY;
	}
	else if (OptionBtn.IsActive() == true)
	{
		menuState = OPTIONS;
	}
	else if (ShopBtn.IsActive() == true)
	{
		menuState = SHOP;
	}
	else if (QuitBtn.IsActive() == true)
	{
		this->Exit(window);
	}
}

void Menu::Options()
{
	MenuTitle.setString("Options");

}

void Menu::Shop()
{
	MenuTitle.setString("Shop");

}
