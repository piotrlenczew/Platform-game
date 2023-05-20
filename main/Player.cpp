#include "pch.h"
#include "Player.h"

void Player::initTexture()
{
	if (!this->textureSheet.loadFromFile("../Textures/Player.png"))
	{
		std::cout << "ERROR::Player::Could not load the player sheet!" << "\n";
	}
}

void Player::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0,0,32,66);
	this->sprite.setTextureRect(this->currentFrame);
}

Player::Player()
{
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{
}

void Player::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->sprite.move(-1.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->sprite.move(1.f, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->sprite.move(0.f, -1.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->sprite.move(0.f, 1.f);
	}
}

void Player::update()
{
	this->updateMovement();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
