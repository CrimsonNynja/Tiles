#include "Profile.h"

std::string Profile::getName() const
{
	return name;
}

unsigned int Profile::getHighScore() const
{
	return highScore;
}

bool Profile::IsFirstTimePlaying() const
{
	return bFirstTimePlaying;
}
