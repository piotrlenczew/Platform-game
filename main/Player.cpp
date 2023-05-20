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
}

Player::Player()
{
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{
}

void Player::update()
{
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
