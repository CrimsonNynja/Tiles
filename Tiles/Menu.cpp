#include "Menu.h"

Menu::Menu()
{
	//Menu Title Text
	MenuTitle.setFont(*TexHandler->getFont());
	MenuTitle.setCharacterSize(70);
	MenuTitle.setColor(sf::Color::Black);
	MenuTitle.setPosition((std::stoi(getValueFromFile("FrameWidth", "Default.ini")) / 2) - 100.f, 50);
	MenuTitle.setString("Tiles");
	ImgHandler->AddToDrawList("UI-Menu", &MenuTitle);
	ImgHandler->AddToDrawList("UI-Shop", &MenuTitle);
	ImgHandler->AddToDrawList("UI-Options", &MenuTitle);

	if (DEVICETYPE == "PC")
	{
	//MAIN MENU
		//Play Button
		MainContainer.AddElement(&PlayBtn);
		PlayBtn.setImages(TexHandler->getTexture("p-MenuCardIA"),
			TexHandler->getTexture("p-MenuCardH"),
			TexHandler->getTexture("p-MenuCardA"), 490, 150);
		PlayBtn.setPosition(160, 290);
		PlayBtn.AddText("Play", TexHandler->getFont(), sf::Color::Black, 35, 0, 0);
		PlayBtn.CenterText();
		ImgHandler->AddToDrawList("UI-Menu", &PlayBtn);
		ImgHandler->AddToDrawList("UI-Menu", PlayBtn.getText());

		//Options Button
		MainContainer.AddElement(&OptionBtn);
		OptionBtn.setImages(TexHandler->getTexture("p-MenuCardIA"),
			TexHandler->getTexture("p-MenuCardH"),
			TexHandler->getTexture("p-MenuCardA"), 490, 150);
		OptionBtn.setPosition(315, 490);
		OptionBtn.AddText("Options", TexHandler->getFont(), sf::Color::Black, 35, 0, 0);
		OptionBtn.CenterText();
		ImgHandler->AddToDrawList("UI-Menu", &OptionBtn);
		ImgHandler->AddToDrawList("UI-Menu", OptionBtn.getText());

		//Shop Button
		MainContainer.AddElement(&ShopBtn);
		ShopBtn.setImages(TexHandler->getTexture("p-MenuCardIA"),
			TexHandler->getTexture("p-MenuCardH"),
			TexHandler->getTexture("p-MenuCardA"), 490, 150);
		ShopBtn.setPosition(315, 705);
		ShopBtn.AddText("Shop", TexHandler->getFont(), sf::Color::Black, 35, 0, 0);
		ShopBtn.CenterText();
		ImgHandler->AddToDrawList("UI-Menu", &ShopBtn);
		ImgHandler->AddToDrawList("UI-Menu", ShopBtn.getText());

		//Quit Button
		MainContainer.AddElement(&QuitBtn);
		QuitBtn.setImages(TexHandler->getTexture("p-MenuCardIA"),
			TexHandler->getTexture("p-MenuCardH"),
			TexHandler->getTexture("p-MenuCardA"), 490, 150);
		QuitBtn.setPosition(160, 900);
		QuitBtn.AddText("Quit", TexHandler->getFont(), sf::Color::Black, 35, 0, 0);
		QuitBtn.CenterText();
		ImgHandler->AddToDrawList("UI-Menu", &QuitBtn);
		ImgHandler->AddToDrawList("UI-Menu", QuitBtn.getText());
	}
	else if (DEVICETYPE == "MOBILE")
	{
	//MAIN MENU
		//Play Button
		PlayBtn.setImages(TexHandler->getTexture("m-MenuCardIA"),
			TexHandler->getTexture("m-MenuCardH"),
			TexHandler->getTexture("m-MenuCardA"), 450, 690);
		PlayBtn.setPosition(30, 360);
		PlayBtn.AddText("Play", TexHandler->getFont(), sf::Color::White, 35, 0, 0);
		PlayBtn.CenterText();
		ImgHandler->AddToDrawList("UI-Menu", &PlayBtn);
		ImgHandler->AddToDrawList("UI-Menu", PlayBtn.getText());

		//Options Button
		OptionBtn.setImages(TexHandler->getTexture("m-MenuCardIA"),
			TexHandler->getTexture("m-MenuCardH"),
			TexHandler->getTexture("m-MenuCardA"), 450, 690);
		OptionBtn.setPosition(505, 360);
		OptionBtn.AddText("Options", TexHandler->getFont(), sf::Color::White, 35, 0, 0);
		OptionBtn.CenterText();
		ImgHandler->AddToDrawList("UI-Menu", &OptionBtn);
		ImgHandler->AddToDrawList("UI-Menu", OptionBtn.getText());

		//Shop Button
		ShopBtn.setImages(TexHandler->getTexture("m-MenuCardIA"),
			TexHandler->getTexture("m-MenuCardH"),
			TexHandler->getTexture("m-MenuCardA"), 450, 690);
		ShopBtn.setPosition(980, 360);
		ShopBtn.AddText("Shop", TexHandler->getFont(), sf::Color::White, 35, 0, 0);
		ShopBtn.CenterText();
		ImgHandler->AddToDrawList("UI-Menu", &ShopBtn);
		ImgHandler->AddToDrawList("UI-Menu", ShopBtn.getText());

		//Quit Button
		QuitBtn.setImages(TexHandler->getTexture("m-MenuCardIA"),
			TexHandler->getTexture("m-MenuCardH"),
			TexHandler->getTexture("m-MenuCardA"), 450, 690);
		QuitBtn.setPosition(1455, 360);
		QuitBtn.AddText("Quit", TexHandler->getFont(), sf::Color::White, 35, 0, 0);
		QuitBtn.CenterText();
		ImgHandler->AddToDrawList("UI-Menu", &QuitBtn);
		ImgHandler->AddToDrawList("UI-Menu", QuitBtn.getText());
	}

	//GLOBALS / ITEMS THAT DONT HAVE AN ALTERNATE IMAGE YET
	VSyncBox.setImages(TexHandler->getTexture("CheckBoxIA"),  
		TexHandler->getTexture("CheckBoxH"),
		TexHandler->getTexture("CheckBoxA"), 100, 100);
	VSyncBox.setPosition(100, 300);
	ImgHandler->AddToDrawList("UI-Options", &VSyncBox);
	VSyncBox.setActive(StringToBool(getValueFromFile("V-syncEnabled", "Default.ini")));	//not working
	std::cout << VSyncBox.IsChecked();

	VSyncText.setString("V-Sync");
	VSyncText.setFont(*TexHandler->getFont());
	VSyncText.setPosition(98, 410);
	VSyncText.setColor(sf::Color::Black);
	ImgHandler->AddToDrawList("UI-Options", &VSyncText);

	BackBtn.setImages(TexHandler->getTexture("BackButton"),
		TexHandler->getTexture("BackButtonH"),
		TexHandler->getTexture("BackButton"), 400, 150);
	BackBtn.setPosition(100, 100);
	BackBtn.AddText("Back", TexHandler->getFont(), sf::Color::White, 34, 100, 100);
	BackBtn.CenterText();
	ImgHandler->AddToDrawList("UI-Options", &BackBtn);		//should add to the other sub menues later
	ImgHandler->AddToDrawList("UI-Options", BackBtn.getText());
	ImgHandler->AddToDrawList("UI-Shop", &BackBtn);
	ImgHandler->AddToDrawList("UI-Shop", BackBtn.getText());

	PauseCard.setAnimation(TexHandler->getTexture("PauseCard"), 400, 600);
	PauseCard.setPosition(((1920 - PauseCard.getGlobalBounds().width) / 2), (1080 - PauseCard.getGlobalBounds().height) / 2);		//
	PauseCard.setDrawLayer(1);
	ImgHandler->AddToDrawList("UI-Pause", &PauseCard);

	Resume.setImages(TexHandler->getTexture("PauseButtonIA"), 
		TexHandler->getTexture("PauseButtonH"), 
		TexHandler->getTexture("PauseButtonIA"), 380, 125);
	Resume.setPosition(PauseCard.getPosition().x + ((PauseCard.getGlobalBounds().width - Resume.getGlobalBounds().width) / 2), 400);
	Resume.AddText("Resume", TexHandler->getFont(), sf::Color::White, 24, 100, 100);
	Resume.CenterText();
	Resume.setDrawLayer(0);
	ImgHandler->AddToDrawList("UI-Pause", &Resume);
	ImgHandler->AddToDrawList("UI-Pause", Resume.getText());

	PMainMenu.setImages(TexHandler->getTexture("PauseButtonIA"),
		TexHandler->getTexture("PauseButtonH"),
		TexHandler->getTexture("PauseButtonIA"), 380, 125);
	PMainMenu.setPosition(PauseCard.getPosition().x + ((PauseCard.getGlobalBounds().width - Resume.getGlobalBounds().width) / 2), 600);
	PMainMenu.AddText("Main Menu", TexHandler->getFont(), sf::Color::White, 24, 100, 100);
	PMainMenu.CenterText();
	PMainMenu.setDrawLayer(0);
	ImgHandler->AddToDrawList("UI-Pause", &PMainMenu);
	ImgHandler->AddToDrawList("UI-Pause", PMainMenu.getText());
}

void Menu::EventUpdate(sf::RenderWindow & window, sf::Event & bevent)
{
	switch (menuState)
	{
	case MAIN:
		PlayBtn.EventUpdate(window, bevent);
		OptionBtn.EventUpdate(window, bevent);
		ShopBtn.EventUpdate(window, bevent);
		QuitBtn.EventUpdate(window, bevent);
		break;
	case OPTIONS:
		VSyncBox.EventUpdate(window, bevent);
		BackBtn.EventUpdate(window, bevent);
		break;
	case SHOP:
		BackBtn.EventUpdate(window, bevent);
		break;
	case PAUSE:
		Resume.EventUpdate(window, bevent);
		PMainMenu.EventUpdate(window, bevent);
	case PLAY:
		if (bevent.type == sf::Event::KeyPressed && bevent.key.code == sf::Keyboard::Escape)
		{
			menuState = PAUSE;
		}
		break;
	}
}

void Menu::Update()
{
	//std::cout << this->getMenuState() << std::endl;
	switch (menuState)
	{
	case MAIN:
		this->MainMenu();
		break;
	case OPTIONS:
		this->Options();
		break;
	case SHOP:
		this->Shop();
		break;
	case PAUSE:
		this->Pause();
	//case PLAY:
	//	this->Play();
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
	//think this is now redundant
}

void Menu::MainMenu()
{
	MenuTitle.setString("Tiles");
	
	//updates
//	if (DEVICETYPE == "PC")
	{
//		MainContainer.Update(window);	//this stops the text from centering as it probably need to push a cast
	}
//	else
	{
		PlayBtn.Update();
		OptionBtn.Update();
		ShopBtn.Update();
		QuitBtn.Update();
	}

	//tests
	if (PlayBtn.IsActive() == true)		//gives a vector subscript error now, WHY?
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
	else if (QuitBtn.IsActive() == true)		//add back in later
	{
//		this->Exit(window);
	}
	this->ResetButtons();	//potentially move this so it activate whenever menus are changed, however it is still a lot faster here
}

void Menu::Options()
{
	MenuTitle.setString("Options");

	VSyncBox.Update();
	BackBtn.Update();

	if (VSyncBox.IsChecked() == true)
	{
		//change value in file
	}

	if (BackBtn.IsActive() == true)
	{
		menuState = MAIN;
	}
}

void Menu::Shop()
{
	MenuTitle.setString("Shop");

	BackBtn.Update();

	if (BackBtn.IsActive() == true)
	{
		menuState = MAIN;
	}
}

void Menu::Pause()
{
	Resume.Update();
	PMainMenu.Update();

	if (Resume.IsActive() == true)
	{
		menuState = PLAY;
		ResetButtons();
	}
	else if (PMainMenu.IsActive() == true)
	{
		menuState = MAIN;
	}
}

void Menu::ResetButtons()
{
	BackBtn.setActive(false);
	PlayBtn.setActive(false);
	OptionBtn.setActive(false);
	ShopBtn.setActive(false);
	QuitBtn.setActive(false);
	Resume.setActive(false);
	PMainMenu.setActive(false);
	//VSyncBox.setActive(false);
}
