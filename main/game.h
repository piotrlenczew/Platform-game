#pragma once

#include "Player.h"

class Game
{
private:
	sf::RenderWindow window;
	sf::Event event;

	Player* player;

	void initWindow();
	void initPlayer();

public:
	Game();
	~Game();

	//Functions
	void updatePlayer();
	void updateCollision();
	void update();
	void renderPlayer();
	void render();
	const sf::RenderWindow& getWindow() const;
};

