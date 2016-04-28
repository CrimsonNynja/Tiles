#include "Board.h"

void Board::CreateBoard()
{
	Tiles.resize(12 * 7);
	float x = 80, y = 124;

	for (unsigned int i = 0; i < Tiles.size(); i ++)
	{
		Tiles[i].setPosition(x, y);
		x += Tiles[i].getGlobalBounds().width;
		if (x >= stoi(getValueFromFile("FrameWidth", "Default.ini")) - 210)
		{
			x = 80;
			y += Tiles[i].getGlobalBounds().height;
		}
		ImageHandler::instance()->AddToDrawList("Game", &Tiles[i]);
	}
}

void Board::DeleteBoard()
{
	Tiles.clear();
}
