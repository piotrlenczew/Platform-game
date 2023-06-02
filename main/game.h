#pragma once
#include "TileMap.h"
#include "Player.h"

class Game
{
private:
	std::string map_source;
	sf::RenderWindow window;
	sf::Event event;
	unsigned int width;
	unsigned int height;
	Player* player;
	TileMap* tileMap;

	void initWindow();
	void initPlayer();

public:
	Game(unsigned int width, unsigned int height, std::string map_source);
	~Game();

	//Functions
	void createTileMap();
	void updatePlayer();
	void updateCollision();
	void update();
	void renderPlayer();
	void renderTiles();
	void render();
	const sf::RenderWindow& getWindow() const;
};

