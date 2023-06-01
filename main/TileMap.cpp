#include "pch.h"
#include "TileMap.h"

TileMap::TileMap()
{
	//Initialize tilemap
}

TileMap::~TileMap()
{
}

void TileMap::fill_the_background(unsigned width, unsigned height)
{
    for (int i = 0; i < width / 60 + 1; i++)
    {
        std::vector<Tile*> row;
        for (int j = 0; j < height / 16 + 1; j++)
        {
            row.push_back(new Tile("../Textures/Tiles.png", i * 60, j * 16, false, false));
        }
        tiles.push_back(row);
    }
}

void TileMap::addTile(unsigned x, unsigned y)
{
}

void TileMap::removeTile(unsigned x, unsigned y)
{
}

void TileMap::update()
{
}

void TileMap::render(sf::RenderTarget& target)
{
    for (auto& row : tiles)
    {
        for (auto& tile : row)
        {
            target.draw(tile->sprite);
        }
    }
}

