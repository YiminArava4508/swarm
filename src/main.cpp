#include <iostream>
#include <game/Game.h>

int main()
{
    Game SwarmGame{};
    SwarmGame.Initialize();
    SwarmGame.CreateWindow();
    SwarmGame.Run();

    while(SwarmGame.IsRunning())
    {
        // game loop?
    }

    std::cout << "Game terminated." << std::endl;
    return 0;
}
