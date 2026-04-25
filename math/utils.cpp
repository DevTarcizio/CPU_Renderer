#include "utils.hpp"

namespace math {

    int crossProduct(const vec2i& a, const vec2i& b, const vec2i& p)
    {
        vec2i AB{ b.x - a.x, b.y - a.y };
        vec2i AP{ p.x - a.x, p.y - a.y };

        return (AB.x * AP.y) - (AB.y * AP.x);
    }

}
