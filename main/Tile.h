#pragma once
class Tile
{
private:


public:
	bool can_pass_through;
	bool is_exit;
	bool deadly;
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;

	Tile(std::string texturename, float x, float y, bool can_pass_through, bool is_exit, bool deadly, sf::IntRect wherabouts_in_png);

	const sf::FloatRect getGlobalBounds() const;

	virtual bool setUpSprite(std::string texturename, sf::IntRect wherabouts_in_png);

};

class DirtTile : public Tile
{
public:
	DirtTile(std::string texturename, float x, float y, bool can_pass_through, bool is_exit, bool deadly) : Tile(texturename, x, y, can_pass_through, is_exit, deadly, sf::IntRect(3, 3, 40, 40)) {};
};

class SkyTile : public Tile
{
public:
	SkyTile(std::string texturename, float x, float y, bool can_pass_through, bool is_exit, bool deadly) : Tile(texturename, x, y, can_pass_through, is_exit, deadly, sf::IntRect(32, 113, 40, 40)) {};
};

class BrickTile : public Tile
{
public:
	BrickTile(std::string texturename, float x, float y, bool can_pass_through, bool is_exit, bool deadly) : Tile(texturename, x, y, can_pass_through, is_exit, deadly, sf::IntRect(49, 34, 40, 40)) {};
};

class MinecraftDirtTile : public Tile
{
public:
	MinecraftDirtTile(std::string texturename, float x, float y, bool can_pass_through, bool is_exit, bool deadly) : Tile(texturename, x, y, can_pass_through, deadly, is_exit, sf::IntRect(64, 0, 32, 32)) {};
};

class MinecraftGrassTile : public Tile
{
public:
	MinecraftGrassTile(std::string texturename, float x, float y, bool can_pass_through, bool is_exit, bool deadly) : Tile(texturename, x, y, can_pass_through, deadly, is_exit, sf::IntRect(96, 0, 32, 32)) {};
};

class MinecraftLeafTile : public Tile
{
public:
	MinecraftLeafTile(std::string texturename, float x, float y, bool can_pass_through, bool is_exit, bool deadly) : Tile(texturename, x, y, can_pass_through, deadly, is_exit, sf::IntRect(128, 96, 32, 32)) {};
};

class MinecraftWoodTile : public Tile
{
public:
	MinecraftWoodTile(std::string texturename, float x, float y, bool can_pass_through, bool is_exit, bool deadly) : Tile(texturename, x, y, can_pass_through, deadly, is_exit, sf::IntRect(160, 224, 32, 32)) {};
};

class MinecraftSkyTile : public Tile
{
public:
	MinecraftSkyTile(std::string texturename, float x, float y, bool can_pass_through, bool is_exit, bool deadly) : Tile(texturename, x, y, can_pass_through, deadly, is_exit, sf::IntRect(128, 352, 32, 32)) {};
};


class MinecraftLavaTile : public Tile
{
public:
	MinecraftLavaTile(std::string texturename, float x, float y, bool can_pass_through, bool is_exit, bool deadly) : Tile(texturename, x, y, can_pass_through, is_exit, deadly, sf::IntRect(416, 448, 32, 32)) {};
};

class MinecraftMushroomTile : public Tile
{
public:
	MinecraftMushroomTile(std::string texturename, float x, float y, bool can_pass_through, bool is_exit, bool deadly) : Tile(texturename, x, y, can_pass_through, is_exit, deadly, sf::IntRect(384, 32, 32, 32)) {};
};