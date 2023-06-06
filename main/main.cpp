#include "pch.h"
#include "game.h"

int main()
{
    srand(static_cast<unsigned>(time(0)));

    unsigned int width = 32 * 24;
    unsigned int height = 32 * 16;
    
    Game game(width, height, 3);

    while (game.getWindow().isOpen())
    {
        game.update();
        
        if (game.get_is_finished())
        {
            game.show_end_message();
        }

        game.render();

    }

    return 0;
}