#ifndef B83182D1_DA5F_43E2_80A6_558F100A9EFF
#define B83182D1_DA5F_43E2_80A6_558F100A9EFF

#include "../GL.hpp"
#include "../Window/WindowsManager.hpp"
#include "../Input/InputManager.hpp"
#include <iostream>

class Point
{
public:
    float vbo_pos[2] {0.0f, 0.0f};
    glm::vec4 color {1.0f, 0.0f, 0.0f, 1.0f};
    glm::vec2 position{0.0f, 0.0f};
    uint32_t vbo;
    uint32_t vao;

    size_t id{0};

    float cursor_catch_threshold {0.015f};

    Point(float x_pos, float y_pos);
    Point(const glm::vec2& pos);

    void SetColor(const glm::vec4& new_color);

    void Update(float delta_t);
    void Draw(float delta_t);
private:
    void GenVAO();
};


#endif /* B83182D1_DA5F_43E2_80A6_558F100A9EFF */
