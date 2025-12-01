#include <iostream>
#include <game/Game.h>
#include "raylib.h"

// desired game structure for main loop
int main()
{
    std::cout << "Starting swarm game" << std::endl;
    Game SwarmGame{};
    SwarmGame.Run(); 
    std::cout << "Game terminated." << std::endl;
    return 0;
}