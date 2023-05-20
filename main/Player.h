#pragma once
class Player
{
private:
	sf::Sprite sprite;
	sf::Texture textureSheet;
	bool running;
	sf::Clock animationTimer;

	//Animation
	sf::IntRect currentFrame;

	//Movement

	//Core values

	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimations();

public:
	Player();
	~Player();

	//Functions
	void updateMovement();
	void updateAnimations();
	void update();
	void render(sf::RenderTarget& target);
};

