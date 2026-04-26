#pragma once
#include <cstdint>
#include "vec2.hpp"

struct vertex {
	vec2i position;
	uint32_t color;

	bool operator==(const vertex& other) const {
		return position == other.position && color == other.color;
	}
};

struct vertexNDC {
	vec2f position;
};