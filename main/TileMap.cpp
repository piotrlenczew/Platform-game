#include "pch.h"
#include "TileMap.h"
#include "Tile.h"
#include <fstream>

TileMap::TileMap()
{

}

TileMap::~TileMap()
{
}

void TileMap::fill_the_background(unsigned screen_width, unsigned screen_height, std::string map_source)
{
    std::ifstream in(map_source);
    if (!in.is_open())
    {
		std::cout << "Error: file not found" << std::endl;
		return;
	}
    unsigned int width, height;
    in >> width;
    in >> height;
    int type = 0;
    for (int i = 0; i < height; i++)
    {
        std::vector<Tile*> row;
        for (int j = 0; j < width; j++)
        {
            in >> type;
            std :: cout<< type << " ";
            if (type == 1)
            {
                row.push_back(new DirtTile("../Textures/squares.png", j * 45, i * 45, false, false));
            }
            else if (type == 2)
            {
                row.push_back(new SkyTile("../Textures/squares.png", j * 45, i * 45, true, false));
            }
            else if (type == 3)
            {
                row.push_back(new BrickTile("../Textures/squares.png", j * 45, i * 45, false, false));
            }
        }
        std::cout << std::endl;
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

