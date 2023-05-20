#include "pch.h"
#include "game.h"

int main()
{
    Game game;

    while (game.getWindow().isOpen())
    {
        game.update();
        game.render();
    }

    return 0;
}