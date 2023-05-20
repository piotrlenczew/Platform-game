#include "pch.h"
#include "Player.h"

void Player::initVariables()
{
	this->running = false;
}

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
	this->currentFrame = sf::IntRect(0, 56, 8, 8);

	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(4.0f, 4.0f);
}

void Player::initAnimations()
{
	this->animationTimer.restart();
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}

Player::~Player()
{
}

void Player::updateMovement()
{
	this->running = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->sprite.move(-1.f, 0.f);
		this->running = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->sprite.move(1.f, 0.f);
		this->running = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->sprite.move(0.f, -1.f);
		this->running = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->sprite.move(0.f, 1.f);
		this->running = true;
	}
}

void Player::updateAnimations()
{
	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
	{
		if (!this->running)	// standing
		{
			this->currentFrame.left += 8.0f;
			if (this->currentFrame.left >= 32.0f)
				this->currentFrame.left = 0;
		}

		this->animationTimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}
}

void Player::update()
{
	this->updateMovement();
	this->updateAnimations();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
