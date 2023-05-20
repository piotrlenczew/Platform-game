#pragma once
class Player
{
private:
	sf::Sprite sprite;
	sf::Texture textureSheet;

	//Animation

	//Movement

	//Core values

	void initTexture();
	void initSprite();

public:
	Player();
	~Player();

	//Functions
	void update();
	void render(sf::RenderTarget& target);
};

