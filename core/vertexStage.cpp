#include "vertexStage.hpp"

VertexStage::VertexStage(int w, int h) : width(w), height(h) {

}

vertex VertexStage::process(const vertexNDC& v) {
	vertex out;

	out.position.x = (v.position.x + 1.0f) * 0.5f * width;
	out.position.y = (1.0f - (v.position.y + 1.0f) * 0.5f) * height;
	out.color = 0x000000FF;

	return out;
}
