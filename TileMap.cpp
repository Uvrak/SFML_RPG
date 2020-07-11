#include "stdafx.h"
#include "TileMap.h"

TileMap::TileMap(float gridSize, unsigned width, unsigned height)
	: gridSizeF(gridSize), gridSizeU(static_cast<unsigned>(gridSize))
{
	this->maxSize.x = width;
	this->maxSize.y = height;
	this->layers = 1;

	this->map.resize(this->maxSize.x);
	for (auto x = 0; x < this->maxSize.x; x++)
	{
		this->map.push_back(std::vector < std::vector < Tile* > >());
		for (auto y = 0; y < this->maxSize.y; y++)
		{
			this->map.resize(this->maxSize.y);
			this->map[x].push_back(std::vector <Tile*>());

			for (auto l = 0; l < this->layers; l++)
			{
				this->map[x][y].resize(this->layers);
				this->map[x][y].push_back(nullptr);
				
			}
		}
	}
}

TileMap::~TileMap()
{
	for (auto x = 0; x < this->maxSize.x; x++)
	{
		for (auto y = 0; y < this->maxSize.y; y++)
		{
			for (auto l = 0; l < this->layers; l++)
			{
				delete this->map[x][y][l];
			}
		}
	}
}

void TileMap::addTile(const unsigned x, const unsigned y, const unsigned z)
{
	/* Take two indicies from the mouse position in the grid and add a tile to that position
	if the internal tilemap array allows it.*/

	if (x < this->maxSize.x && x >= 0 &&
		y < this->maxSize.y && y >= 0 &&
		z <= this->layers && z >= 0)
	{
		if (this->map[x][y][z] == nullptr)
		{
			/* OK to add tile.*/
			this->map[x][y][z] = new Tile(x * this->gridSizeF, y * this->gridSizeF, this->gridSizeF);
			std::cout << "DEBUG: ADDED TILE!\n";
			
		}
		
	}
}

void TileMap::removeTile(const unsigned x, const unsigned y, const unsigned z)
{
	if (x < this->maxSize.x && x >= 0 &&
		y < this->maxSize.y && y >= 0 &&
		z <= this->layers && z >= 0)
	{
		if (this->map[x][y][z] != nullptr)
		{
			/* OK to add tile.*/
			this->map[x][y][z] = nullptr;
			std::cout << "DEBUG: Removed TILE!\n";

		}

	}
}

//Functions
void TileMap::update()
{
}

void TileMap::render(sf::RenderTarget& target)
{
	for (auto& x : this->map) 
	{
		for (auto& y: x)
		{
			for(auto& l : y)
			{
				if (l != nullptr)
					l->render(target);
			}
		}
	}
}

