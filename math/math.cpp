#include "math.hpp"
#include <cmath>

namespace math {

    int crossProduct(const vec2i& a, const vec2i& b, const vec2i& p)
    {
        vec2i AB{ b.x - a.x, b.y - a.y };
        vec2i AP{ p.x - a.x, p.y - a.y };

        return (AB.x * AP.y) - (AB.y * AP.x);
    }

    vec2f multiply(const mat3& M, const vec2f& v)
    {
        vec2f r;

        r.x = M.m[0][0] * v.x + M.m[0][1] * v.y + M.m[0][2];
        r.y = M.m[1][0] * v.x + M.m[1][1] * v.y + M.m[1][2];

        return r;
    }

    mat3 identity()
    {
        return mat3{ {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
            } };
    }

    mat3 translate(float tx, float ty)
    {
        return mat3{ {
            {1, 0, tx},
            {0, 1, ty},
            {0, 0, 1}
            } };
    }

    mat3 scale(float sx, float sy)
    {
        return mat3{ {
            {sx, 0, 0},
            {0, sy, 0},
            {0, 0, 1}
            } };
    }

    mat3 rotate(float angle)
    {
        float c = cos(angle);
        float s = sin(angle);

        return mat3{ {
            {c, -s, 0},
            {s, c, 0},
            {0, 0, 1}
            } };
    }

    
}
