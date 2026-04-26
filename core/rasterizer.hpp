#pragma once
#include "../types/vertex.hpp"
#include "../math/math.hpp"
#include <algorithm>


class Renderer;

class Rasterizer {
public:
	Rasterizer();

	void rasterizerTriangle(vertex v0, vertex v1, vertex v2, Renderer& render);
	void rasterizerTriangle(vertex v0, vertex v1, vertex v2, uint32_t color, Renderer& render);

};