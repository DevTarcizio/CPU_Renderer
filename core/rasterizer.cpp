#include "rasterizer.hpp"
#include "Renderer.hpp"

Rasterizer::Rasterizer() {

}

void Rasterizer::rasterizerTriangle(vertex v0, vertex v1, vertex v2, Renderer& render) {
	int minX = std::min(v0.position.x, std::min(v1.position.x, v2.position.x));
	int maxX = std::max(v0.position.x, std::max(v1.position.x, v2.position.x));

	int minY = std::min(v0.position.y, std::min(v1.position.y, v2.position.y));
	int maxY = std::max(v0.position.y, std::max(v1.position.y, v2.position.y));

	for (int i{ minX }; i <= maxX; i++) {
		for (int j{ minY }; j <= maxY; j++) {
			vec2i p{ i, j };

			int64_t a1 = math::crossProduct(v0.position, v1.position, p);
			int64_t a2 = math::crossProduct(v1.position, v2.position, p);
			int64_t a3 = math::crossProduct(v2.position, v0.position, p);

			if ((a1 >= 0 && a2 >= 0 && a3 >= 0) || (a1 <= 0 && a2 <= 0 && a3 <= 0)) {
				renderer.setOnPixel(p);
			}
		}
	}
}

void Rasterizer::rasterizerTriangle(vertex v0, vertex v1, vertex v2, uint32_t color, Renderer& renderer) {
	int minX = std::min(v0.position.x, std::min(v1.position.x, v2.position.x));
	int maxX = std::max(v0.position.x, std::max(v1.position.x, v2.position.x));

	int minY = std::min(v0.position.y, std::min(v1.position.y, v2.position.y));
	int maxY = std::max(v0.position.y, std::max(v1.position.y, v2.position.y));

	for (int i{ minX }; i <= maxX; i++) {
		for (int j{ minY }; j <= maxY; j++) {
			vec2i p{ i, j };

			int64_t a1 = math::crossProduct(v0.position, v1.position, p);
			int64_t a2 = math::crossProduct(v1.position, v2.position, p);
			int64_t a3 = math::crossProduct(v2.position, v0.position, p);

			if ((a1 >= 0 && a2 >= 0 && a3 >= 0) || (a1 <= 0 && a2 <= 0 && a3 <= 0)) {
				renderer.setOnPixel(p, color);
			}
		}
	}
}
