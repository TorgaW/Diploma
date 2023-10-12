#ifndef A1FC2F00_B855_4D05_999D_73815FA92764
#define A1FC2F00_B855_4D05_999D_73815FA92764

#include "../Point/Point.hpp"
#include <vector>

class Curve
{
public:
    size_t subdivisions;
    std::vector<Point *> control_points;

    uint32_t vbo;
    uint32_t vao;
    std::vector<float> vbo_data;
    glm::vec4 color{1.0f, 1.0f, 0.0f, 1.0f};

    size_t id;

    virtual void Update(float delta_time)
    {
        glBindVertexArray(vao);
        glDrawArrays(GL_LINE_STRIP, 0, subdivisions + 1);
        glBindVertexArray(0);
    };

    virtual void Draw(float delta_time){};

protected:
    virtual void UpdatePoints(){};
    virtual void GenVAO(){};
    virtual void UpdateVBO(){};

    float step{0.0};
};

#endif /* A1FC2F00_B855_4D05_999D_73815FA92764 */
