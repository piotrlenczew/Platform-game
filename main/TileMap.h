#pragma once

#include "Tile.h"
#include <fstream>
#include "pch.h"

class TileMap
{
private:
	std::vector< std::vector<Tile*> > tiles;

public:
	TileMap();
	~TileMap();

	//Functions
	void fill_the_background(unsigned screen_width, unsigned screen_height, std::ifstream& in);
	void addTile(unsigned x, unsigned y);
	void removeTile(unsigned x, unsigned y);
	std::vector< std::vector<Tile*> > getTiles();

	void update();
	void render(sf::RenderTarget& target);
};

