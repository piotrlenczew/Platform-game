#include "pch.h"
#include "game.h"

void Game::initWindow()
{
	// size, name, settiings (sf::Style::Default for typical window)
	this->window.create(sf::VideoMode(800, 600), "Game name", sf::Style::Close | sf::Style::Titlebar);
}

Game::Game()
{
	this->initWindow();
}

void Game::update()
{
	std::cout << "Updating game" << "\n";
}

void Game::render()
{
}

const sf::RenderWindow& Game::getWindow() const
{
	return this->window;
}
