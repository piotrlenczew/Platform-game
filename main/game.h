#pragma once

#include "pch.h"

class Game
{
private:
	sf::RenderWindow window;

	void initWindow();

public:
	Game();

	void update();
	void render();
	const sf::RenderWindow& getWindow() const;
};

