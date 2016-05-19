#pragma once

#include <ctime>
#include "TextureHandler.h"
#include "ImageHandler.h"
#include "GameSprite.h"

class Pickup : public GameSprite		//idea, every 100 score is converted to 1 coing at the end of the game
{
public:
	Pickup();
	void Reset();
	int getscoreAmmount() const;
	std::string getType();
	void Update();

private:
	enum ScoreType
	{
		DEFAULT = 0,	//+1 score
		BONUS,			//+5 score
		COIN			//+1 currency
	}scoreType;
	bool bScoreType = true;		//true is score, false is currency

	int scoreAmmount = 1;
};