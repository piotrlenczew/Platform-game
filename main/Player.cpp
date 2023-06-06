#include "pch.h"
#include "Player.h"

void Player::initVariables()
{
	this->animationState = IDLE;
	this->in_air = false;
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
	this->sprite.setScale(5.f, 5.f);
}

void Player::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Player::initPhysics()
{
	this->velocityMax = 10.f;
	this->velocityMin = 1.f;
	this->acceleration = 1.3f;
	this->drag = 0.9f;
	this->gravity = 3.f;
	this->velocityMaxY = 20.f;
}

Player::Player(sf::Vector2f spawnpoint) : spawnpoint(spawnpoint)
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
	this->initPhysics();
	this->setPosition(spawnpoint.x, spawnpoint.y);
}

Player::~Player()
{
}



const bool& Player::getAnimationSwitch()
{
	bool anim_switch = this->animationSwitch;
	if (this->animationSwitch)
		this->animationSwitch = false;

	return anim_switch;
}

const sf::Vector2f Player::getPosition() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Player::setInAir(bool in_air)
{
	this->in_air = in_air;
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::respawn()
{
	this->setPosition(this->spawnpoint.x, this->spawnpoint.y);
}

void Player::resetVelocityY()
{
	this->velocity.y = 0.f;
}

void Player::resetVelocityX()
{
	this->velocity.x = 0.f;
}

void Player::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Player::move(const float dir_x, const float dir_y)
{
	//Acceleration
	this->velocity.x += dir_x * this->acceleration;

	//Limit velocity
	if (std::abs(this->velocity.x) > this->velocityMax)
	{
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
}

void Player::updatePhysics()
{
	//Gravity
	this->velocity.y += 1.0 * this->gravity;
	if (std::abs(this->velocity.y) > this->velocityMaxY)
	{
		this->velocity.y = this->velocityMaxY * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}

	//Drag
	this->velocity *= this->drag;

	//Limit drag
	if (std::abs(this->velocity.x) < this->velocityMin)
		this->velocity.x = 0.f;
	if (std::abs(this->velocity.y) < this->velocityMin)
		this->velocity.y = 0.f;

	this->sprite.move(this->velocity);
}

void Player::updateMovement()
{
	if (!this->in_air)
		this->animationState = PLAYER_ANIMATION_STATES::IDLE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !this->in_air)
	{
		this->move(-1.f, 0.f);
		this->animationState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->in_air)
	{
		this->move(-1.f, 0.f);
		this->animationState = PLAYER_ANIMATION_STATES::IN_AIR_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !this->in_air)
	{
		this->move(1.f, 0.f);
		this->animationState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->in_air)
	{
		this->move(1.f, 0.f);
		this->animationState = PLAYER_ANIMATION_STATES::IN_AIR_RIGHT;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !this->in_air)
	{
		this->velocity.y = -20.0f;
		this->in_air = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->in_air)
	{
		this->velocity.y -= 1.8f;
	}
	/*
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !this->in_air)
	{
		this->animationState = PLAYER_ANIMATION_STATES::CRAWLING;
	}*/
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->in_air)
	{
		this->velocity.y += 1.8f;
	}
}

void Player::updateAnimations()
{
	if (this->animationState == PLAYER_ANIMATION_STATES::IDLE)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f || this->getAnimationSwitch())
		{
			this->currentFrame.top = 56.0f;
			this->currentFrame.left += 8.0f;
			if (this->currentFrame.left >= 32.0f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animationState == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimationSwitch())
		{
			this->currentFrame.top = 8.0f;
			this->currentFrame.left += 8.0f;
			if (this->currentFrame.left >= 64.0f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
		this->sprite.setScale(4.5f, 4.5f);
		this->sprite.setOrigin(0.f, 0.f);
	}
	else if (this->animationState == PLAYER_ANIMATION_STATES::MOVING_LEFT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimationSwitch())
		{
			this->currentFrame.top = 8.0f;
			this->currentFrame.left += 8.0f;
			if (this->currentFrame.left >= 64.0f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
		this->sprite.setScale(-4.5f, 4.5f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 4.5f, 0.f);
	}
	else if (this->animationState == PLAYER_ANIMATION_STATES::IN_AIR_RIGHT)
	{
		this->currentFrame.top = 80.0f;
		this->currentFrame.left += 16.0f;
		this->sprite.setScale(4.5f, 4.5f);
		this->sprite.setOrigin(0.f, 0.f);
	}
	else if (this->animationState == PLAYER_ANIMATION_STATES::IN_AIR_LEFT)
	{
		this->currentFrame.top = 80.0f;
		this->currentFrame.left += 16.0f;
		this->sprite.setScale(-4.5f, 4.5f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 4.5f, 0.f);
	}
	else
		this->animationTimer.restart();
}

void Player::update()
{
	this->updateMovement();
	this->updateAnimations();
	this->updatePhysics();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
