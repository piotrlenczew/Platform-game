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
	unsigned int number_of_levels;
	unsigned int current_level;
	bool is_finished;
	Player* player;
	TileMap* tileMap;

	void initWindow();
	void initPlayer(unsigned int start_x, unsigned int start_y);

public:
	Game(unsigned int width, unsigned int height, unsigned int number_of_levels);
	~Game();

	//Functions
	bool get_is_finished();
	void show_end_message();
	void createTileMap();
	void updatePlayer();
	void updateCollision();
	void update();
	void renderPlayer();
	void renderTiles();
	void render();
	const sf::RenderWindow& getWindow() const;
};

