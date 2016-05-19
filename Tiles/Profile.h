#pragma once

#include <string>
#include "INIReader.h"

class Profile
{
public:
	void LoadProfile(std::string FileName);
	void SaveProfile();

	std::string getName() const;
	unsigned int getHighScore() const;
	bool IsFirstTimePlaying() const;

private:
	std::string name;
	unsigned int highScore;
	//one for score and another for time?
	unsigned int currency;
	bool bFirstTimePlaying = true;
	// currenty selected texture pack
	// currrently selected charater? - may not have this feature
	//play time
	//challanges completed ?
	// currency?
};
