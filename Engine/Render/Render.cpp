#include "Render.hpp"

void Render::Update(float delta_time)
{   
    for (size_t i = 0; i < points.size(); i++)
    {
        points[i]->Update(delta_time);
    }

    for (size_t i = 0; i < lines.size(); i++)
    {
        lines[i]->Update(delta_time);
    }

    for (size_t i = 0; i < curves.size(); i++)
    {
        curves[i]->Update(delta_time);
    }
    
}

void Render::Draw(float delta_time)
{
    for (size_t i = 0; i < lines.size(); i++)
    {
        line_shader.UseShader();
        line_shader.setVec4("line_color", lines[i]->color);
        lines[i]->Draw(delta_time);
    }

    for (size_t i = 0; i < curves.size(); i++)
    {
        line_shader.UseShader();
        line_shader.setVec4("line_color", curves[i]->color);
        curves[i]->Draw(delta_time);
    }
    
    for (size_t i = 0; i < points.size(); i++)
    {   
        point_shader.UseShader();
        glm::vec3 ppos{points[i]->position.x, points[i]->position.y, 0.0f};
        glm::mat4 ptran(1.0f);
        ptran = glm::translate(ptran, ppos);
        point_shader.setMat4("transform", ptran);
        point_shader.setVec4("point_color", points[i]->color);
        points[i]->Draw(delta_time);
    }
    
}

Point *Render::AddPoint(float x_pos, float y_pos)
{
    Point *t = new Point(x_pos, y_pos);
    t->id = (last_point_id++);
    points.push_back(t);
    return t;
}

Point *Render::AddPoint(const glm::vec2 &pos)
{
    Point *t = new Point(pos);
    t->id = (last_point_id++);
    points.push_back(t);
    return t;
}

Line *Render::AddLine(Point *p_0, Point *p_1)
{
    Line *t = new Line(p_0, p_1);
    t->id = (last_line_id++);
    lines.push_back(t);
    return t;
}

CubicBezier *Render::AddCubicBezier(const std::vector<Point*>& points, size_t subs)
{
    CubicBezier *t = new CubicBezier(points, subs);
    t->id = (last_curve_id++);
    curves.push_back(t);
    return t;
}

CubicBSpline *Render::AddCubicBSpline(const std::vector<Point *> &points, size_t subs)
{
    CubicBSpline *t = new CubicBSpline(points, subs);
    t->id = (last_curve_id++);
    curves.push_back(t);
    return t;
}
