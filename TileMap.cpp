#include "TileMap.h"

TileMap::TileMap()
{
	this->gridSizeU = 50;
	this->maxSize.x = 5000;
	this->maxSize.y = 5000;
	this->layers = 5;

	for (int x = 0; x < this->maxSize.x; x++)
	{
		this->map.push_back(std::vector < std::vector < Tile > >());
		for (int y = 0; y < this->maxSize.y; y++)
		{
			this->map[x].push_back(std::vector <Tile>());

			for (int l = 0; l < this->layers; l++) 
			{
				this->map[x][y].push_back(Tile());
			}
		}
	}

}
	

TileMap::~TileMap()
{
}
