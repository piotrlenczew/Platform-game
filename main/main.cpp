#include "pch.h"
#include "game.h"

int main()
{
    srand(static_cast<unsigned>(time(0)));

    unsigned int width = 32 * 24;
    unsigned int height = 32 * 16;
    
    Game game(width, height, "../Textures/map_1.txt");

    while (game.getWindow().isOpen())
    {
        game.update();
        if (game.get_is_finished())
        {
            game.show_end_message();
            break;
        }

        game.render();

    }

    return 0;
}