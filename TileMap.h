#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"

class TileMap
{
private:
	float gridSizeF;
	unsigned gridSizeU;
	unsigned layers;
	sf::Vector2u maxSize;
	std::vector< std::vector< std::vector < Tile > > > map;
public:
	TileMap(float gridSize, unsigned width, unsigned height);
	virtual ~TileMap();

	//Functions
	void update();
	void render(sf::RenderTarget& target);
};
#endif
