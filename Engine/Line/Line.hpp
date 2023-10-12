#ifndef C8C3AE3D_5FEC_4226_83BB_30C2E3577E3E
#define C8C3AE3D_5FEC_4226_83BB_30C2E3577E3E

#include "../GL.hpp"
#include "../Point/Point.hpp"
#include <cstdint>
#include <array>

class Line
{
    public:
    float vbo_pos[4] {0.0f, 0.0f, 0.0f, 0.0f};
    glm::vec4 color {0.2f, 0.0f, 0.0f, 0.5f};
    std::array<Point*, 2> points;
    uint32_t vbo;
    uint32_t vao;

    size_t id{0};

    Line(float x0_pos, float y0_pos, float x1_pos, float y1_pos);
    Line(const glm::vec2& pos_0, const glm::vec2& pos_1);
    Line(Point *p_0, Point *p_1);

    void SetColor(const glm::vec4& new_color);

    void Update(float delta_t);
    void Draw(float delta_t);
private:
    void GenVAO();
    void UpdateVBO();
};



#endif /* C8C3AE3D_5FEC_4226_83BB_30C2E3577E3E */
