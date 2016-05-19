#include "Menu.h"

Menu::Menu()
{
	//Menu Title Text
	MenuTitle.setFont(*TextureHandler::instance()->getFont());
	MenuTitle.setCharacterSize(70);
	MenuTitle.setColor(sf::Color::Black);
	MenuTitle.setPosition((std::stoi(getValueFromFile("FrameWidth", "Default.ini")) / 2) - 100.f, 50);
	MenuTitle.setString("Tiles");
	ImageHandler::instance()->AddToDrawList("UI-Menu", &MenuTitle);
	ImageHandler::instance()->AddToDrawList("UI-Shop", &MenuTitle);
	ImageHandler::instance()->AddToDrawList("UI-Options", &MenuTitle);

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

	//GLOBALS / ITEMS THAT DONT HAVE AN ALTERNATE IMAGE YET
	VSyncBox.setImages(TextureHandler::instance()->getTexture("CheckBoxIA"),  
		TextureHandler::instance()->getTexture("CheckBoxH"),
		TextureHandler::instance()->getTexture("CheckBoxA"), 100, 100);
	VSyncBox.setPosition(100, 300);
	ImageHandler::instance()->AddToDrawList("UI-Options", &VSyncBox);

	VSyncText.setString("V-Sync");
	VSyncText.setFont(*TextureHandler::instance()->getFont());
	VSyncText.setPosition(98, 410);
	VSyncText.setColor(sf::Color::Black);
	ImageHandler::instance()->AddToDrawList("UI-Options", &VSyncText);

	BackBtn.setImages(TextureHandler::instance()->getTexture("BackButton"),
		TextureHandler::instance()->getTexture("BackButtonH"),
		TextureHandler::instance()->getTexture("BackButton"), 400, 150);
	BackBtn.setPosition(100, 100);
	BackBtn.AddText("Back", TextureHandler::instance()->getFont(), sf::Color::White, 34, 100, 100);
	BackBtn.CenterText();
	ImageHandler::instance()->AddToDrawList("UI-Options", &BackBtn);		//should add to the other sub menues later
	ImageHandler::instance()->AddToDrawList("UI-Options", BackBtn.getText());		//should add to the other sub menues later

}

void Menu::Update(sf::RenderWindow& window, sf::Event& bevent)
{
	switch (menuState)
	{
	case MAIN:
		this->MainMenu(window, bevent);
		break;
	case OPTIONS:
		this->Options(window, bevent);
		break;
	case SHOP:
		this->Shop(window, bevent);
		break;
	case PAUSE:
		this->Pause(window, bevent);
		break;
	case PLAY:
		this->Play(bevent);
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

void Menu::Play(sf::Event& bevent)
{
	if (bevent.type == sf::Event::KeyPressed && bevent.key.code == sf::Keyboard::Escape)
	{
		menuState = PAUSE;
	}
	//test is the pause button has been pressed, and if so, go to the pause menu
}

void Menu::MainMenu(sf::RenderWindow& window, sf::Event& bevent)
{
	MenuTitle.setString("Tiles");
	
	this->ResetButtons();
	//updates
//	if (DEVICETYPE == "PC")
	{
		MainContainer.Update(window);	//this stops the text from centering as it probably need to push a cast
	}
//	else
	{
		PlayBtn.EventUpdate(window, bevent);
		OptionBtn.EventUpdate(window, bevent);
		ShopBtn.EventUpdate(window, bevent);
		QuitBtn.EventUpdate(window, bevent);
//		PlayBtn.Update(window);
//		OptionBtn.Update(window);
//		ShopBtn.Update(window);
//		QuitBtn.Update(window);
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

void Menu::Options(sf::RenderWindow& window, sf::Event& bevent)
{
	MenuTitle.setString("Options");

	VSyncBox.Update(window);
	BackBtn.EventUpdate(window, bevent);
//	BackBtn.CenterText();

	if (VSyncBox.IsChecked() == true)
	{
		//change value in file
	}

	if (BackBtn.IsActive() == true)
	{
		menuState = MAIN;
	}
}

void Menu::Shop(sf::RenderWindow& window, sf::Event& bevent)
{
	MenuTitle.setString("Shop");
}

void Menu::Pause(sf::RenderWindow& window, sf::Event& bevent)
{
	std::cout << "The game pauses here" << std::endl;
}

void Menu::ResetButtons()
{
	BackBtn.setActive(false);
	PlayBtn.setActive(false);
	OptionBtn.setActive(false);
	ShopBtn.setActive(false);
	QuitBtn.setActive(false);
	VSyncBox.setActive(false);
}
