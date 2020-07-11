#include "stdafx.h"
#include "TileMap.h"

TileMap::TileMap()
{
	this->gridSizeF = 50.f;
	this->gridSizeU = static_cast<unsigned>(this->gridSizeF);
	this->maxSize.x = 10;
	this->maxSize.y = 10;
	this->layers = 1;

	//this->map.resize(this->maxSize.x);
	for (auto x = 0; x < this->maxSize.x; x++)
	{
		this->map.push_back(std::vector < std::vector < Tile > >());
		for (auto y = 0; y < this->maxSize.y; y++)
		{
			//this->map.resize(this->maxSize.y);
			this->map[x].push_back(std::vector <Tile>());

			for (auto l = 0; l < this->layers; l++)
			{
				//this->map[x][y].resize(this->layers);
				this->map[x][y].push_back(Tile(x * this->gridSizeF, y * this->gridSizeF, this->gridSizeF));
			}
		}
	}
}

TileMap::~TileMap()
{
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
				l.render(target);
			}
		}
	}
}

