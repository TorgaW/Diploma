#ifndef AE859150_2773_4349_A192_6D610D1EB5FA
#define AE859150_2773_4349_A192_6D610D1EB5FA

#include "../Curve/Curve.hpp"

class CubicBezier : public Curve
{
public:
    CubicBezier(const std::vector<Point*>& points, size_t subs);

    virtual void Update(float delta_t);
    virtual void Draw(float delta_t);

private:
    virtual void UpdatePoints();
    virtual void GenVAO();
    virtual void UpdateVBO();
};


#endif /* AE859150_2773_4349_A192_6D610D1EB5FA */
