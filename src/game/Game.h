#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include <memory>

class Game
{
public:
    Game();
    ~Game();

    void CreateWindow();
    void Run();
    // void Render();

    bool IsRunning() const;

private:
    std::string msTitle;
    bool mbIsRunning;
};