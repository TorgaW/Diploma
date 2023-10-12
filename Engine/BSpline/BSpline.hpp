#ifndef FD3AE0AC_F391_40D5_9525_482E9C599838
#define FD3AE0AC_F391_40D5_9525_482E9C599838

#include "../Curve/Curve.hpp"

class CubicBSpline : public Curve
{
public:
    CubicBSpline(const std::vector<Point*>& points, size_t subs);

    virtual void Update(float delta_t);
    virtual void Draw(float delta_t);

private:
    virtual void UpdatePoints();
    virtual void GenVAO();
    virtual void UpdateVBO();
};


#endif /* FD3AE0AC_F391_40D5_9525_482E9C599838 */
