#pragma once

#include <string>

class Profile
{
public:
	void LoadProfile();
	void SaveProfile();

	std::string getName() const;
	unsigned int getHighScore() const;
	bool IsFirstTimePlaying() const;

private:
	std::string name;
	unsigned int highScore;
	//one for score and another for time?
	bool bFirstTimePlaying = true;
	// currenty selected texture pack
	// currrently selected charater? - may not have this feature
	//play time
	//challanges completed ?
	// currency?
};
