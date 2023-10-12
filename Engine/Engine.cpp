#include "Engine.hpp"

bool Engine::Init()
{
    if (!glfwInit())
        return false;
    Window *mwin = WindowsManager::CreateWindow();
    WindowsManager::SetMainWindow(mwin);
    mwin->SetAsCurrentContext();
    if(!gladLoadGL())
        return false;
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
    glLineWidth(2.0f);
    InputManager::SetGLFWInputMode(GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    Render::Init();
    return true;
}

void Engine::Loop()
{
    while (!glfwWindowShouldClose(WindowsManager::GetMainWindowGLFW()))
    {
        if(should_terminate_engine || glfwGetKey(WindowsManager::GetMainWindowGLFW(), GLFW_KEY_ESCAPE) == GLFW_PRESS) break;

        Time::UpdateDeltaTime();

        /* clear screen */
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        Render::Update(Time::delta_time);
        Render::Draw(Time::delta_time);

        /* Swap front and back buffers */
        glfwSwapBuffers(WindowsManager::GetMainWindowGLFW());

        /* Poll for and process events */
        glfwPollEvents();
    }
}

void Engine::Final()
{
    glfwTerminate();
}
