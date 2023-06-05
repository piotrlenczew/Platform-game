#include "pch.h"
#include "TileMap.h"
#include "Tile.h"
#include <fstream>

TileMap::TileMap()
{

}

TileMap::~TileMap()
{
    for (auto tileRow : this->tiles)
    {
        for (auto& tile : tileRow)
        {
            delete tile;
        }
    }
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
            if (type == 0)
            {
                row.push_back(new MinecraftLavaTile("../Textures/terrain.png", j * 32, i * 32, false, false));
            }
            if (type == 1)
            {
                row.push_back(new MinecraftDirtTile("../Textures/terrain.png", j * 32, i * 32, false, false));
            }
            else if (type == 2)
            {
                row.push_back(new MinecraftGrassTile("../Textures/terrain.png", j * 32, i * 32, false, false));
            }
            else if (type == 3)
            {
                row.push_back(new MinecraftLeafTile("../Textures/terrain.png", j * 32, i * 32, false, false));
            }
            else if (type == 4)
            {
                row.push_back(new MinecraftWoodTile("../Textures/terrain.png", j * 32, i * 32, false, false));
            }
            else if (type ==  5)
            {
                row.push_back( new MinecraftSkyTile("../Textures/terrain.png", j * 32, i * 32, true, false));
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

std::vector<std::vector<Tile*>> TileMap::getTiles()
{
    return this->tiles;
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

