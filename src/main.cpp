#include <iostream>
#include "game.h"
#include "constants.h"

int main(int argc, char *args[])
{
    std::cout << "Game is running..." << std::endl;
    Game game;
    game.Initialize(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (game.IsRunning())
    {
        game.ProcessInput();
        game.Update();
        game.Render();
    }

    game.Destroy();

    return 0;
}
