#include "Engine/Engine.hpp"

int main(void)
{   
    //inits engine
    Engine::Init();

    auto point0 = Render::AddPoint({-0.1f, 0.1f});
    auto point1 = Render::AddPoint({0.1f, 0.1f});
    auto point2 = Render::AddPoint({0.1f, -0.1f});
    auto point3 = Render::AddPoint({0.0f, 0.0f});

    auto point4 = Render::AddPoint({-0.3f, 0.3f});
    auto point5 = Render::AddPoint({0.3f, 0.3f});
    auto point6 = Render::AddPoint({0.3f, -0.3f});
    auto point7 = Render::AddPoint({0.1f, 0.1f});

    auto line0 = Render::AddLine(point0, point1);
    auto line1 = Render::AddLine(point1, point2);
    auto line2 = Render::AddLine(point2, point3);

    auto line3 = Render::AddLine(point4, point5);
    auto line4 = Render::AddLine(point5, point6);
    auto line5 = Render::AddLine(point6, point7);

    auto cubic_bspline = Render::AddCubicBSpline({point0, point1, point2, point3}, 40);
    auto cubic_bezier = Render::AddCubicBezier({point4, point5, point6, point7}, 40);

    //starts loop
    Engine::Loop();
    //stops work and clean memory after loop
    Engine::Final();
    return 0;
}