#include "Board.h"

Board::~Board()
{
	delete TempTile;

	for (unsigned i = 0; i < Tiles.size(); i++)
	{
		delete Tiles[i];
	}
	Tiles.clear();
}

void Board::CreateBoard(int RowSize, int CollumnSize)	//row and collumn may be round the wrong way
{
	collumnSize = CollumnSize;
	rowSize = RowSize;

	for (unsigned i = 0; i < (RowSize * CollumnSize); i++)
	{
		Tiles.push_back(new Tile());
	}

	TempTile = new Tile;
	TempTile->setPosition(-200, -200);				//set the Tile off screen
	TempTile->setHidden(true);
	ImgHandler->AddToDrawList("Game", TempTile);
	ImgHandler->Sort("Game");

	Offset.x = (1920 - (collumnSize * TempTile->getGlobalBounds().width)) / 2;			//make dynamic later
	Offset.y = (1080 - (rowSize * TempTile->getGlobalBounds().height)) / 2;				//make dynamic later

	this->Reset();

}

void Board::Reset()
{
	sf::Vector2f position = Offset;

	for (unsigned i = 0; i < Tiles.size(); i++)
	{
		ImgHandler->AddToDrawList("Game", Tiles[i]);
		Tiles[i]->setDrawLayer(5);

		Tiles[i]->setPosition(position);
		Tiles[i]->setLastPosition();
		position.x += Tiles[i]->getGlobalBounds().width;

		if (position.x >= 1920 - Offset.x)
		{
			position.y += Tiles[i]->getGlobalBounds().height;
			position.x = Offset.x;
		}
	}
	ImgHandler->Sort("Game");
}

Tile* Board::getTile(int index)
{
	return Tiles[index];
}

Tile* Board::getTile(int row, int collumn)
{
	if (getTileIndex(row, collumn) != -1)
	{
		return Tiles[getTileIndex(row, collumn)];
	}
	else
	{
		return nullptr;
	}
}

int Board::getTileIndex(int row, int collumn)
{
	if (row <= rowSize && collumn <= collumnSize)
	{
		int rowCount = 0;
		for (unsigned i = 0; i < Tiles.size(); i++)
		{
			float f = float(i + 1) / float(collumnSize);

			if ((ceil(f) == row))
			{
				rowCount += 1;
				if (rowCount == collumn)
				{
					//std::cout << i << std::endl;
					return i;
				}
			}
		}
	}
	else
	{
		std::cout << "the specified tile is out of the bounds of the board of size: " << rowSize << ", " << collumnSize << std::endl;
		return -1;
	}

	std::cout << "error, cannot fid the tile at: " << row << ", " << collumn << std::endl;
	return -1;
}

int Board::getBoardSize()
{
	return (rowSize * collumnSize);
}

void Board::MoveRow(int RowNo)
{
	Tile* Temp;
	bMoving = true;
	FunctPointer = &Board::MoveRow;
	FptrBordMoving = RowNo;
	MoveDirection = -1;

	/* get all the nessasary tiles */
	for (unsigned i = 1; i < collumnSize + 1; i++)
	{
		if (getTileIndex(RowNo, i) != -1)
		{
			Tiles[getTileIndex(RowNo, i)]->setPosition(Tiles[getTileIndex(RowNo, i)]->getPosition().x + (5 * MoveDirection), Tiles[getTileIndex(RowNo, i)]->getPosition().y);
		}
	}

	/* set the Temp tile to the end of the row */
	TempTile->setHidden(false);
	if (MoveDirection == 1)
	{
		TempTile->setPosition(getTile(RowNo, 1)->getPosition().x - TempTile->getGlobalBounds().width, getTile(RowNo, 1)->getPosition().y);
	}
	else if (MoveDirection == -1)
	{
		TempTile->setPosition(getTile(RowNo, collumnSize)->getPosition().x + TempTile->getGlobalBounds().width, getTile(RowNo, 1)->getPosition().y);
	}

	/* Test if the row has moved a tiles length */
	if ((MoveDirection == 1 && (Tiles[getTileIndex(RowNo, 1)]->getPosition().x
		>= Tiles[getTileIndex(RowNo, 1)]->getLastPosition().x + Tiles[getTileIndex(RowNo, 1)]->getGlobalBounds().width))
		|| (MoveDirection == -1 && (Tiles[getTileIndex(RowNo, 1)]->getPosition().x
			<= Tiles[getTileIndex(RowNo, 1)]->getLastPosition().x - Tiles[getTileIndex(RowNo, 1)]->getGlobalBounds().width)))
	{
		if (MoveDirection == 1)
		{
			Temp = TempTile;
			TempTile = Tiles[getTileIndex(RowNo, collumnSize)];
			for (unsigned i = 12; i > 1; i--)	//from 12-2
			{
				Tiles[getTileIndex(RowNo, i)] = Tiles[getTileIndex(RowNo, i - 1)];
			}
			Tiles[getTileIndex(RowNo, 1)] = Temp;
			Temp = NULL;
		}
		else
		{
			Temp = TempTile;
			TempTile = Tiles[getTileIndex(RowNo, 1)];
			for (unsigned i = 1; i < collumnSize; i++)	//from 1-11
			{
				Tiles[getTileIndex(RowNo, i)] = Tiles[getTileIndex(RowNo, i + 1)];
			}
			Tiles[getTileIndex(RowNo, collumnSize)] = Temp;
			Temp = NULL;
		}

		//should set the tiles to an exact position here as well///////////////////
		bMoving = false;
		MoveDirection = 0;
		FunctPointer = NULL;
	}
	/*  */
}

bool Board::IsOnBoundry(int index)
{
	if ((index % collumnSize == 0) || index % collumnSize == 1)
	{
		//on the side of the x axis
		return true;
	}
	if ((index <= rowSize) || index >= Tiles.size() - rowSize)
	{
		//on the side of the y axis
		return true;
	}
	return false;
}

void Board::Update()
{
	for (unsigned i = 0; i < Tiles.size(); i++)
	{
		Tiles[i]->Update();
	}
	//	Tiles[getTileIndex(2, 1)]->setColor(sf::Color(0, 0, 255, 255));
	//TempTile->Update();

	if (bMoving == true && FunctPointer != NULL)
	{
		(*this.*FunctPointer)(FptrBordMoving);
	}
	else
	{
		for (auto x: Tiles)
		{
			x->setLastPosition();
		}
	}

	//std::cout << Tiles[20]->getPosition().x << std::endl;
}
