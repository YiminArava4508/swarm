 #include <iostream>
 #include "Game.h"

// helper function for this translation unit
namespace
{
    void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        (void)window;
        glViewport(0, 0, width, height);
    }
    
    void process_input(GLFWwindow* window)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
    }
} // namespace

Game::Game() : msTitle("Swarm"), mbIsRunning(true), mpWindow(nullptr) {}

Game::~Game() {};

void Game::Initialize()
{
    if (glfwInit() != GLFW_TRUE)
    {
        std::cerr << "Failed to initialise GLFW\n";
        mbIsRunning = false;
    }
}

void Game::CreateWindow()
{   
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    mpWindow = glfwCreateWindow(800, 600, "Swarm OpenGL", nullptr, nullptr);
    if (mpWindow == nullptr)
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        mbIsRunning = false;
    }

    glfwMakeContextCurrent(mpWindow);
    glfwSetFramebufferSizeCallback(mpWindow, framebuffer_size_callback);
    glfwSwapInterval(1);
}

void Game::Run()
{
    while (glfwWindowShouldClose(mpWindow) == GLFW_FALSE && mbIsRunning)
    {
        process_input(mpWindow);

        glClearColor(0.1F, 0.12F, 0.25F, 1.0F);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(mpWindow);
        glfwPollEvents();
    }

    glfwDestroyWindow(mpWindow);
    glfwTerminate();
    mbIsRunning = false;
}

bool Game::IsRunning() const
{
    return mbIsRunning;
}
