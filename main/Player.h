#pragma once

enum PLAYER_ANIMATION_STATES { IDLE, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING };

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture textureSheet;
	sf::Clock animationTimer;

	//Animation
	short animationState;
	sf::IntRect currentFrame;
	bool animationSwitch;

	//Physics
	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;
	float gravity;
	float velocityMaxY;

	//Core values

	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimations();
	void initPhysics();

public:
	Player();
	~Player();

	//Accesors
	const bool& getAnimationSwitch();

	//Functions
	void resetAnimationTimer();
	void move(const float dir_x, const float dir_y);
	void updatePhysics();
	void updateMovement();
	void updateAnimations();
	void update();
	void render(sf::RenderTarget& target);
};

