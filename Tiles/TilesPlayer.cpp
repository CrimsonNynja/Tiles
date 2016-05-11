#include "TilesPlayer.h"

TilesPlayer::TilesPlayer()
{
	this->setAnimation(TextureHandler::instance()->getTexture("Player"), 144, 224);
	this->getAnimationComponent()->setAnimSpeed(100);
	this->drawLayer = 2;
	ImageHandler::instance()->AddToDrawList("Game", this);

}

void TilesPlayer::LoadFromProfile(Profile* profile)
{

}

void TilesPlayer::SaveToProfile(Profile* profile)
{

}

void TilesPlayer::Update()
{
	__super::Update();
	gui.Update();
	
	//if colliding with picking up
		//destroy pickup
		//gui.AddScore(score);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) == true)
	{
		gui.AddScore(score);
	}
}
