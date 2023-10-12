#include "Bezier.hpp"

CubicBezier::CubicBezier(const std::vector<Point*>& points, size_t subs)
{
    control_points = points;
    subdivisions = subs;
    UpdatePoints();
    GenVAO();
}

void CubicBezier::Update(float delta_t)
{
    UpdatePoints();
    UpdateVBO();
}

void CubicBezier::Draw(float delta_t)
{
    glBindVertexArray(vao);
    glDrawArrays(GL_LINE_STRIP, 0, subdivisions+1);
    glBindVertexArray(0);
}

void CubicBezier::UpdatePoints()
{
    float t = 0.0;
    step = 1.0 / (float)subdivisions;
    vbo_data.clear();
    vbo_data.reserve(subdivisions*2+2);
    for (size_t i = 0; i < subdivisions; i++)
    {
        glm::vec2 A = {std::lerp(control_points[0]->position.x, control_points[1]->position.x, t + step*i), std::lerp(control_points[0]->position.y, control_points[1]->position.y, t + step*i)};
        glm::vec2 B = {std::lerp(control_points[1]->position.x, control_points[2]->position.x, t + step*i), std::lerp(control_points[1]->position.y, control_points[2]->position.y, t + step*i)};
        glm::vec2 C = {std::lerp(control_points[2]->position.x, control_points[3]->position.x, t + step*i), std::lerp(control_points[2]->position.y, control_points[3]->position.y, t + step*i)};
        glm::vec2 D = {std::lerp(A.x, B.x, t + step*i), std::lerp(A.y, B.y, t + step*i)};
        glm::vec2 E = {std::lerp(B.x, C.x, t + step*i), std::lerp(B.y, C.y, t + step*i)};
        glm::vec2 P = {std::lerp(D.x, E.x, t + step*i), std::lerp(D.y, E.y, t + step*i)};
        vbo_data.push_back(P.x);
        vbo_data.push_back(P.y);
    }
    vbo_data.push_back(control_points[3]->position.x);
    vbo_data.push_back(control_points[3]->position.y);
}

void CubicBezier::GenVAO()
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

void CubicBezier::UpdateVBO()
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float) * vbo_data.size(), &vbo_data[0]);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}