#include "pch.h"
#include "game.h"

void Game::initWindow()
{
	// size, name, settiings (sf::Style::Default for typical window)
	this->window.create(sf::VideoMode(width, height), "Game name", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}

void Game::initPlayer()
{
	this->player = new Player();
}

Game::Game(unsigned int width, unsigned int height, std::string map_source)
{
	this->map_source = map_source;
	this->width = width;
	this->height = height;
	this->createTileMap();
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

void Game::updateCollision()
{
	//Tiles
	for (auto tileRow : this->tileMap->getTiles())
	{
		for (auto& tile : tileRow)
		{
			sf::FloatRect playerBounds = this->player->getGlobalBounds();
			sf::FloatRect tileBounds = tile->getGlobalBounds();
		
			if (tileBounds.intersects(playerBounds) && !tile->can_pass_through)
			{
				std::cout << "Collision!" << "\n";
			}
		}
	}

	//Screen
	// Bottom
	if (this->player->getPosition().y + this->player->getGlobalBounds().height >= this->window.getSize().y)
	{
		this->player->resetVelocityY();
		this->player->setPosition(
			this->player->getPosition().x,
			this->window.getSize().y - this->player->getGlobalBounds().height
		);
		this->player->setInAir(false);
	}
	// Top
	if (this->player->getPosition().y <= 0)
	{
		this->player->resetVelocityY();
		this->player->setPosition(this->player->getPosition().x, 0.f);
	}
	// Right
	if (this->player->getPosition().x > this->window.getSize().x)
	{
		this->player->setPosition(0.f, this->player->getPosition().y);
	}
	// Left
	if (this->player->getPosition().x + this->player->getGlobalBounds().width < 0)
	{
		this->player->setPosition(
			this->window.getSize().x - this->player->getGlobalBounds().width,
			this->player->getPosition().y
		);
	}
}

void Game::createTileMap()
{
	this ->tileMap = new TileMap();
	this->tileMap->fill_the_background(this->width, this->height, map_source);
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

		if (this->event.type == sf::Event::KeyReleased && 
			(
				this->event.key.code == sf::Keyboard::A ||
				this->event.key.code == sf::Keyboard::D ||
				this->event.key.code == sf::Keyboard::W ||
				this->event.key.code == sf::Keyboard::S 
			)
		)
		{
			this->player->resetAnimationTimer();
		}
	}

	this->updatePlayer();

	this->updateCollision();
}

void Game::renderPlayer()
{
	this->player->render(this->window);
}

void Game::render()
{
	this->window.clear();

	//Render game
	this->renderTiles();
	this->renderPlayer();

	this->window.display();
}

const sf::RenderWindow& Game::getWindow() const
{
	return this->window;
}

void Game::renderTiles()
{
	this->tileMap->render(this->window);
}
