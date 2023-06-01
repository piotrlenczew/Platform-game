#include "pch.h"
#include "Tile.h"

Tile::Tile(std::string texturename, float x, float y, bool can_pass_through, bool is_exit)
{
    if (!setUpSprite(texturename))
    {
        return;
    }
    this->can_pass_through = can_pass_through;
    this->is_exit = is_exit;
    this->position = sf::Vector2f(x, y);
    sprite.setPosition(this->position);

}

bool Tile::setUpSprite(std::string texturename)
{

    if (!texture.loadFromFile(texturename))
    {
        std::cout << "ERROR::Player::Could not load the player sheet!" << "\n";
        return false;
    }

    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(78, 0, 60, 16));
    return true;
}
