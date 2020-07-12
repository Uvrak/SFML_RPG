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
	std::vector< std::vector< std::vector < Tile* > > > map;
	sf::Texture tilesheet;

public:
	TileMap(float gridSize, unsigned width, unsigned height);
	virtual ~TileMap();
	
	//Accessors
	const sf::Texture* getTileSheet() const;

	//Functions
	void addTile(const unsigned x, const unsigned, const unsigned z, const sf::IntRect& texture_rect);
	void removeTile(const unsigned x, const unsigned y, const unsigned z);
	void update();
	void render(sf::RenderTarget& target);
};
#endif
