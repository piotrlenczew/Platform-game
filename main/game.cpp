#include "pch.h"
#include "game.h"
#include <fstream>

void Game::initWindow()
{
	// size, name, settiings (sf::Style::Default for typical window)
	this->window.create(sf::VideoMode(width, height), "Game name", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}

void Game::initPlayer(unsigned int start_x, unsigned int start_y)
{
	this->player = new Player(sf::Vector2f(100, 100));
}

Game::Game(unsigned int width, unsigned int height, unsigned int number_of_levels)
{
	this->width = width;
	this->height = height;
	this-> number_of_levels = number_of_levels;
	this->current_level = 1;
	this->is_finished = false;
	this->createTileMap();
	this->initWindow();
}

Game::~Game()
{
	delete this->player;
	delete this->tileMap;
}

void Game::updatePlayer()
{
	this->player->update();
}

void Game::updateCollision(sf::FloatRect playerBoundsBeforeMove)
{
	//Tiles
	sf::FloatRect tileBounds;
	sf::FloatRect playerBounds = playerBoundsBeforeMove;
	sf::FloatRect currentPlayerBounds = this->player->getGlobalBounds();
	for (auto tileRow : this->tileMap->getTiles())
	{
		for (auto& tile : tileRow)
		{
			tileBounds = tile->getGlobalBounds();
			playerBounds = playerBoundsBeforeMove;
			currentPlayerBounds = this->player->getGlobalBounds();
			if (tileBounds.intersects(currentPlayerBounds) && tile->can_pass_through)
			{
				if (tile->deadly)
				{
					this->player->respawn();
					return;
				}
				if (tile->is_exit)
				{
					is_finished = true;
					break;
				}
			}
		
			else if (tileBounds.intersects(currentPlayerBounds))
			{
				//Bottom collision
				if (playerBounds.top < tileBounds.top &&
					playerBounds.top + playerBounds.height < tileBounds.top + tileBounds.height &&
					playerBounds.left < tileBounds.left + tileBounds.width &&
					playerBounds.left + playerBounds.width > tileBounds.left
					)
				{
					this->player->resetVelocityY();
					this->player->setPosition(currentPlayerBounds.left, tileBounds.top - playerBounds.height);
					this->player->setInAir(false);
					playerBounds.top = tileBounds.top - playerBounds.height;
					currentPlayerBounds = this->player->getGlobalBounds();
				}
				//Top collision
				else if (playerBounds.top > tileBounds.top &&
					playerBounds.top + playerBounds.height > tileBounds.top + tileBounds.height &&
					playerBounds.left < tileBounds.left + tileBounds.width &&
					playerBounds.left + playerBounds.width > tileBounds.left
					)
				{
					this->player->resetVelocityY();
					this->player->setPosition(currentPlayerBounds.left, tileBounds.top + tileBounds.height);
					playerBounds.top = tileBounds.top + tileBounds.height;
					currentPlayerBounds = this->player->getGlobalBounds();
				}

				//Right collision
				if (playerBounds.left < tileBounds.left &&
					playerBounds.left + playerBounds.width < tileBounds.left + tileBounds.width &&
					playerBounds.top < tileBounds.top + tileBounds.height &&
					playerBounds.top + playerBounds.height > tileBounds.top
					)
				{
					this->player->resetVelocityX();
					this->player->setPosition(tileBounds.left - playerBounds.width, currentPlayerBounds.top);
				}
				//Left collision
				else if (playerBounds.left > tileBounds.left &&
					playerBounds.left + playerBounds.width > tileBounds.left + tileBounds.width &&
					playerBounds.top < tileBounds.top + tileBounds.height &&
					playerBounds.top + playerBounds.height > tileBounds.top
					)
				{
					this->player->resetVelocityX();
					this->player->setPosition(tileBounds.left + tileBounds.width, currentPlayerBounds.top);
				}
			}
		}
		if (is_finished)
		{
			break;
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
	//if (this->player->getPosition().y <= 0)
	//{
	//	this->player->resetVelocityY();
	//	this->player->setPosition(this->player->getPosition().x, 0.f);
	//}
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
	std::string map_source = "../Maps/map_" + std::to_string(this->current_level) + ".txt";
	std::ifstream map_file(map_source);
	this->tileMap->fill_the_background(this->width, this->height, map_file);
	int spawn_x;
	int spawn_y;
	map_file >> spawn_x >> spawn_y;
	this->initPlayer(spawn_x, spawn_y);
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
	sf::FloatRect playerBoundBeforeMove = this->player->getGlobalBounds();

	this->updatePlayer();

	this->updateCollision(playerBoundBeforeMove);
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

void Game::show_end_message()
{
	if (current_level != number_of_levels)
	{
		current_level += 1;
		delete this->tileMap;
		this->window.clear();
		this->window.display();
		this->is_finished = false;
		delete this->player;
		createTileMap();
		return;
	}
	sf::Sprite sprite;
	sf::Texture texture;
	if (!texture.loadFromFile("../Textures/END.png"))
	{
		std::cout << "ERROR::GAME::COULD_NOT_LOAD_END_TEXTURE" << std::endl;
	}
	sprite.setTexture(texture);
	this->window.clear();
	this->window.draw(sprite);
	this->window.display();
	sf::sleep(sf::seconds(5));
	this->window.close();
}

bool Game::get_is_finished()
{
	return is_finished;
}

const sf::RenderWindow& Game::getWindow() const
{
	return this->window;
}

void Game::renderTiles()
{
	this->tileMap->render(this->window);
}
