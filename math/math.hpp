#pragma once
#include "../types/vec2.hpp"
#include "../types/mat3.hpp"

namespace math {
	int	crossProduct(const vec2i& a, const vec2i& b, const vec2i& p);

	// Métodos de transformação de matrizes
	vec2f multiply(const mat3& M, const vec2f& v);
	mat3 identity();
	mat3 translate(float tx, float ty);
	mat3 scale(float sx, float sy);
	mat3 rotate(float angle);
};