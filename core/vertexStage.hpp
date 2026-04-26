#pragma once
#include "types.hpp"
#include "../math/vec2.hpp"

class VertexStage {
public:
	int width, height;

	VertexStage(int w, int h);

	vertex process(const vertexNDC& v);

private:


};