#include "Profile.h"

void Profile::LoadProfile(std::string FileName)
{
	name = getValueFromFile("PlayerName", FileName);
	highScore = stoi(getValueFromFile("HighScore", FileName));
	currency = stoi(getValueFromFile("Curency", FileName));
	//bFirstTimePlaying;
}

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
