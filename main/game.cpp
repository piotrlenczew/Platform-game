#include "pch.h"
#include "game.h"

void Game::initWindow()
{
	// size, name, settiings (sf::Style::Default for typical window)
	this->window.create(sf::VideoMode(800, 600), "Game name", sf::Style::Close | sf::Style::Titlebar);
}

void Game::initPlayer()
{
	this->player = new Player();
}

Game::Game()
{
	this->initWindow();
	this->initPlayer();
}

Game::~Game()
{
	delete this->player;
}

void Game::updatePlayer()
{
	this->player->update();
}

void Game::update()
{
	//Polling window events
	while (this->window.pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window.close();
		else if (this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape)
			this->window.close();
	}

	this->updatePlayer();
}

void Game::renderPlayer()
{
	this->player->render(this->window);
}

void Game::render()
{
	this->window.clear();

	//Render game
	this->renderPlayer();


	this->window.display();
}

const sf::RenderWindow& Game::getWindow() const
{
	return this->window;
}
