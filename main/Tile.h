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

	Tile(std::string texturename, float x, float y, bool can_pass_through, bool is_exit, sf::IntRect wherabouts_in_png);

	bool setUpSprite(std::string texturename, sf::IntRect wherabouts_in_png);

};

class DirtTile : public Tile
{
public:
	DirtTile(std::string texturename, float x, float y, bool can_pass_through, bool is_exit) : Tile(texturename, x, y, can_pass_through, is_exit, sf::IntRect(49, 1, 14, 14)) {};
};

class SkyTile : public Tile
{
public:
	SkyTile(std::string texturename, float x, float y, bool can_pass_through, bool is_exit) : Tile(texturename, x, y, can_pass_through, is_exit, sf::IntRect(36, 119, 14, 14)) {};
};

class BrickTile : public Tile
{
public:
	BrickTile(std::string texturename, float x, float y, bool can_pass_through, bool is_exit) : Tile(texturename, x, y, can_pass_through, is_exit, sf::IntRect(50, 34, 14, 14)) {};
};

