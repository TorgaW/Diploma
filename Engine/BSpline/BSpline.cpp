#include "BSpline.hpp"

CubicBSpline::CubicBSpline(const std::vector<Point *> &points, size_t subs)
{
    control_points = points;
    subdivisions = subs;
    UpdatePoints();
    GenVAO();
}

void CubicBSpline::Update(float delta_t)
{
    UpdatePoints();
    UpdateVBO();
}

void CubicBSpline::Draw(float delta_t)
{
    glBindVertexArray(vao);
    glDrawArrays(GL_LINE_STRIP, 0, subdivisions);
    glBindVertexArray(0);
}

void CubicBSpline::UpdatePoints()
{
    float t = 0.0;
    step = 1.0 / (double)subdivisions;
    vbo_data.clear();
    vbo_data.reserve(subdivisions*2);
    for (size_t i = 0; i < subdivisions; i++)
    {
        glm::vec2 A = (control_points[0]->position) + 4.0f*(control_points[1]->position);
        glm::vec2 B = (t + step*i) * (-3.0f * control_points[0]->position + 3.0f * control_points[2]->position);
        glm::vec2 C = (t + step*i)*(t + step*i) * (3.0f * control_points[0]->position - 6.0f * control_points[1]->position + 3.0f * control_points[2]->position);
        glm::vec2 D = (t + step*i)*(t + step*i)*(t + step*i) * (-1.0f * control_points[0]->position + 3.0f * control_points[1]->position - 3.0f * control_points[2]->position + control_points[3]->position);
        glm::vec2 P = A+B+C+D;
        vbo_data.push_back(P.x / 6.0f);
        vbo_data.push_back(P.y / 6.0f);
    }
    
}

void CubicBSpline::GenVAO()
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
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vbo_data.size(), &vbo_data[0], GL_DYNAMIC_DRAW);

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

void CubicBSpline::UpdateVBO()
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float) * vbo_data.size(), &vbo_data[0]);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
