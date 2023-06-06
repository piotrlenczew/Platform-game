#include "pch.h"
#include "Tile.h"

Tile::Tile(std::string texturename, float x, float y, bool can_pass_through, bool is_exit, bool deadly, sf::IntRect wherabouts_in_png)
{
    if (!setUpSprite(texturename, wherabouts_in_png))
    {
        return;
    }
    this->can_pass_through = can_pass_through;
    this->does_kill = does_kill;
    this->is_exit = is_exit;
    this->deadly = deadly;
    this->position = sf::Vector2f(x, y);
    sprite.setPosition(this->position);

}

const sf::FloatRect Tile::getGlobalBounds() const
{
    return this->sprite.getGlobalBounds();
}

bool Tile::setUpSprite(std::string texturename, sf::IntRect wherabouts_in_png)
{

    if (!texture.loadFromFile(texturename))
    {
        std::cout << "ERROR::Player::Could not load the player sheet!" << "\n";
        return false;
    }

    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(wherabouts_in_png);
    return true;
}
