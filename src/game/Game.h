#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include <memory>

class Game
{
public:
    Game();
    ~Game();

    void Initialize();
    void CreateWindow();
    void Run();

    bool IsRunning() const;

private:
    std::string msTitle;
    bool mbIsRunning;
    GLFWwindow* mpWindow;    // raw pointer because memory managed by GL
};