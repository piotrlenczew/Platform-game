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

	virtual bool setUpSprite(std::string texturename, sf::IntRect wherabouts_in_png);

};

class DirtTile : public Tile
{
public:
	DirtTile(std::string texturename, float x, float y, bool can_pass_through, bool is_exit) : Tile(texturename, x, y, can_pass_through, is_exit, sf::IntRect(1, 1, 45, 45)) {};
};

class SkyTile : public Tile
{
public:
	SkyTile(std::string texturename, float x, float y, bool can_pass_through, bool is_exit) : Tile(texturename, x, y, can_pass_through, is_exit, sf::IntRect(32, 113, 45, 45)) {};
};

class BrickTile : public Tile
{
public:
	BrickTile(std::string texturename, float x, float y, bool can_pass_through, bool is_exit) : Tile(texturename, x, y, can_pass_through, is_exit, sf::IntRect(49, 34, 45, 45)) {};
};

