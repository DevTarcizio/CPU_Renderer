#pragma once
#include "../types/vertex.hpp"
#include "../types/vec2.hpp"

class VertexStage {
public:
	int width, height;

	VertexStage(int w, int h);

	vertex process(const vertexNDC& v);

private:


};