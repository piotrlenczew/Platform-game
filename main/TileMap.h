#pragma once

#include "Tile.h"

class TileMap
{
private:
	std::vector< std::vector<Tile*> > tiles;

public:
	TileMap();
	~TileMap();

	//Functions
	void fill_the_background(unsigned width, unsigned height);
	void addTile(unsigned x, unsigned y);
	void removeTile(unsigned x, unsigned y);

	void update();
	void render(sf::RenderTarget& target);
};

