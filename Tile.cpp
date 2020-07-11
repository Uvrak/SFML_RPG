#include "stdafx.h"
#include "Tile.h"

Tile::Tile()
{
}

Tile::Tile(float x, float y, float gridSizeF)
{
	this->tile.setSize(sf::Vector2f(gridSizeF, gridSizeF));
	this->tile.setFillColor(sf::Color::White);
	this->tile.setOutlineThickness(1.f);
	this->tile.setOutlineColor(sf::Color::Black);
	this->tile.setPosition(x, y);
}

Tile::~Tile()
{
}

//Functions
void Tile::update()
{
}

void Tile::render(sf::RenderTarget& target)
{
	target.draw(this->tile);
}

void Tile::addTile()
{
}

void Tile::removeTile()
{
}
