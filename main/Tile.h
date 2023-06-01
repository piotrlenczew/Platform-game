#pragma once
class Tile
{
private:


public:
	bool can_pass_through;
	bool is_exit;
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;

	Tile(std::string texturename, float x, float y, bool can_pass_through, bool is_exit);

	bool setUpSprite(std::string texturename);

};

