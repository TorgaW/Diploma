#include "Point.hpp"

Point::Point(float x_pos, float y_pos)
{
    position.x = x_pos;
    position.y = y_pos;
    GenVAO();
}

Point::Point(const glm::vec2 &pos)
{
    position = pos;
    GenVAO();
}

void Point::SetColor(const glm::vec4 &new_color)
{
    color = new_color;
}

void Point::Update(float delta_t)
{
    double mx, my;
    glfwGetCursorPos(WindowsManager::GetMainWindowGLFW(), &mx, &my);
    double whalf = WindowsManager::GetMainWindow()->width / 2;
    double hhalf = WindowsManager::GetMainWindow()->height / 2;
    double nmx = mx - whalf;
    double nmy = my - hhalf;
    nmx /= whalf;
    nmy /= hhalf;
    nmy *= -1;
    glm::vec2 p0(nmx, nmy);
    if (glm::length(p0 - position) <= cursor_catch_threshold || InputManager::cursor_locked.is_locked(id))
    {
        color = {0.0, 1.0, 0.0, 1.0};
        if (glfwGetMouseButton(WindowsManager::GetMainWindowGLFW(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && InputManager::cursor_locked.is_free_or_locked_by(id))
        {
            position = {nmx, nmy};
            InputManager::cursor_locked.set_locked(id);
        }
        else InputManager::cursor_locked.unlock_strict(id);
    }
    else
        color = {1.0, 0.0, 0.0, 1.0};
}

void Point::Draw(float delta_t)
{
    glBindVertexArray(vao);
    glDrawArrays(GL_POINTS, 0, 1);
    glBindVertexArray(0);
}

void Point::GenVAO()
{
    // gen VBO
    glGenBuffers(1, &vbo);
    // gen VAO
    glGenVertexArrays(1, &vao);
    // bind object VAO - start state recording
    glBindVertexArray(vao);
    // bind object VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // fill object VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 2, vbo_pos, GL_STATIC_DRAW);

    //* set vertex attributes *//

    // vertex attribute for position
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void *)0);
    glEnableVertexAttribArray(0);

    //* finishing *//

    // unbind object VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    // unbind VAO - stop state recording
    glBindVertexArray(0);
}