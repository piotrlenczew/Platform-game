#pragma once
class Player
{
private:
	sf::Sprite sprite;
	sf::Texture textureSheet;

	//Animation
	sf::IntRect currentFrame;

	//Movement

	//Core values

	void initTexture();
	void initSprite();

public:
	Player();
	~Player();

	//Functions
	void updateMovement();
	void update();
	void render(sf::RenderTarget& target);
};

