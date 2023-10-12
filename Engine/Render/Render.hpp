#ifndef CCC939BF_831C_4535_BA0D_003F50A0E4B7
#define CCC939BF_831C_4535_BA0D_003F50A0E4B7

#include "../BSpline/BSpline.hpp"
#include "../Bezier/Bezier.hpp"
#include "../Line/Line.hpp"
#include "../Shader/Shader.hpp"

#include <vector>

class Render
{
public:
    static inline std::vector<Point*> points{};
    static inline Shader point_shader{};
    static inline size_t last_point_id {0};

    static inline std::vector<Line*> lines{};
    static inline Shader line_shader{};
    static inline size_t last_line_id {0};

    static inline std::vector<Curve*> curves{};
    static inline size_t last_curve_id {0};

    static inline void Init()
    {
        point_shader = Shader("Resources/Shaders/PointF.frag", "Resources/Shaders/PointV.vert");
        line_shader = Shader("Resources/Shaders/LineF.frag", "Resources/Shaders/LineV.vert");
    };

    static void Update(float delta_time);

    static void Draw(float delta_time);

    static Point *AddPoint(float x_pos, float y_pos);
    static Point *AddPoint(const glm::vec2& pos);
    static Line *AddLine(Point *p_0, Point *p_1);
    static CubicBezier *AddCubicBezier(const std::vector<Point*>& points, size_t subs);
    static CubicBSpline *AddCubicBSpline(const std::vector<Point*>& points, size_t subs);
};


#endif /* CCC939BF_831C_4535_BA0D_003F50A0E4B7 */
