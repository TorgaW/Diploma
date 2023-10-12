#include "Line.hpp"

Line::Line(Point *p_0, Point *p_1)
{
    points[0] = p_0;
    points[1] = p_1;
    vbo_pos[0] = p_0->position.x;
    vbo_pos[1] = p_0->position.y;
    vbo_pos[2] = p_1->position.x;
    vbo_pos[3] = p_1->position.y;
    GenVAO();
}

void Line::Update(float delta_t)
{
    vbo_pos[0] = points[0]->position.x;
    vbo_pos[1] = points[0]->position.y;
    vbo_pos[2] = points[1]->position.x;
    vbo_pos[3] = points[1]->position.y;
    UpdateVBO();
}

void Line::Draw(float delta_t)
{
    glBindVertexArray(vao);
    glDrawArrays(GL_LINES, 0, 2);
    glBindVertexArray(0);
}

void Line::GenVAO()
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
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 4, vbo_pos, GL_DYNAMIC_DRAW);

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

void Line::UpdateVBO()
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float) * 4, vbo_pos);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
