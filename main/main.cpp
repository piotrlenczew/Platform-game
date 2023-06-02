#include "pch.h"
#include "game.h"

int main()
{
    srand(static_cast<unsigned>(time(0)));

    unsigned int width = 800;
    unsigned int height = 600;
    
    Game game(width, height, "../Textures/map_1.txt");

    while (game.getWindow().isOpen())
    {
        game.update();
        game.render();
    }

    return 0;
}