#pragma once

#include "GameMode.h"

class DefaultGameType : public GameMode
{
public:
	DefaultGameType();
	void Update();

protected:
	/* timed vard, determine when an action should happen on the board */
	int time;
	unsigned const int moveCount = 4;
	unsigned const int FadeCount = 6;

	/* variables relating to board movents, but not time */
	bool bMoved = false;
	bool bFaded = false;
	int randVar = 0;
	unsigned int fadeCount = 0;
	unsigned int fadeMax = 7;
};