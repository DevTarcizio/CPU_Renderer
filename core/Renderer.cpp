#include "Renderer.hpp"

Renderer::Renderer() : framebuffer(width * height), vertexStage(width, height) {

}

bool Renderer::isInsideScreen(vec2i point) const
{
	if (point.x >= width || point.x < 0) {
		return false;
	}
	if (point.y >= height || point.y < 0) {
		return false;
	}

	return true;
}

uint32_t Renderer::toRGBA(Color color) {
	switch (color) {

	case Color::Red: return 0xFF0000FF;
	case Color::Green: return 0x00FF00FF;
	case Color::Blue: return 0x0000FFFF;
	case Color::Black: return 0x000000FF;
	case Color::White: return 0xFFFFFFFF;
	}
	return 0xFFFFFFFF;
}

uint32_t Renderer::getPixel(vec2i cords) {
	if (!isInsideScreen(cords)) {
		//std::cout << "Ponto fora da tela!\n";
		return 0;
	}

	int index{ ((cords.y * width) + cords.x) };
	return framebuffer[index];
}



void Renderer::togglePixel(vec2i cords) {
	if (!isInsideScreen(cords)) {
		//std::cout << "Ponto fora da tela!\n";
		return;
	}

	int index{ (cords.y * width) + cords.x };

	if (framebuffer[index] > 0) {
		framebuffer[index] = 0x000000FF;
	}
	else {
		framebuffer[index] = 0xFFFFFFFF;
	}
}

void Renderer::setOnPixel(vec2i cords){
	if (!isInsideScreen(cords)) {
		//std::cout << "Ponto fora da tela!\n";
		return;
	}
	
	int index{ (cords.y * width) + cords.x };

	framebuffer[index] = 0xFFFFFFFF;
}

void Renderer::setOnPixel(vec2i cords, uint32_t color) {
	if (!isInsideScreen(cords)) {
		//std::cout << "Ponto fora da tela!\n";
		return;
	}

	int index{ (cords.y * width) + cords.x };

	framebuffer[index] = color;

}

void Renderer::setOnPixel(vertex v) {
	if (!isInsideScreen(v.position)) {
		//std::cout << "Ponto fora da tela!\n";
		return;
	}

	int index{ (v.position.y * width) + v.position.x };
	framebuffer[index] = v.color;
}

void Renderer::setOffPixel(vec2i cords) {
	if (!isInsideScreen(cords)) {
		std::cout << "Ponto fora da tela!\n";
		return;
	}
	
	int index{ (cords.y * width) + cords.x };

	framebuffer[index] = 0x000000FF;
}


uint32_t* Renderer::getFrameBufferData() {
	return framebuffer.data();
}

void Renderer::drawLine(vertexNDC initial_point, vertexNDC final_point) {
	vertex initial_p = vertexStage.process(initial_point);
	vertex final_p = vertexStage.process(final_point);


	float distanceX{ static_cast<float>(final_p.position.x - initial_p.position.x) };
	float distanceY{ static_cast<float>(final_p.position.y - initial_p.position.y) };

	// Definimos a distância real de um ponto a outro, ideal para podermos desenhar retas 
	// em qualquer direção
	float steps{ std::max(std::abs(distanceX), std::abs(distanceY))};

	if (initial_p == final_p) {
		setOnPixel(initial_p);
		steps = 0;
		return;
	}

	
	// Define o quanto andar em X e em Y
	float Xincrement{ distanceX / steps };
	float Yincrement{ distanceY / steps };

	vec2f cords{ initial_p.position.x, initial_p.position.y };

	for (int i{ 0 }; i <= steps; i++) {
		// O método round arrendonda 
		vertex newCords{ round(cords.x), round(cords.y) };
		setOnPixel(newCords.position);
		cords.x += Xincrement;
		cords.y += Yincrement;
	}
}


void Renderer::drawTriangle(vertexNDC v0, vertexNDC v1, vertexNDC v2) {
	drawLine(v0, v1);
	drawLine(v0, v2);
	drawLine(v2, v1);
}

void Renderer::drawFilledTriangle(vertexNDC v0, vertexNDC v1, vertexNDC v2) {
	vertex p0 = vertexStage.process(v0);
	vertex p1 = vertexStage.process(v1);
	vertex p2 = vertexStage.process(v2);

	int minX = std::min(p0.position.x, std::min(p1.position.x, p2.position.x));
	int maxX = std::max(p0.position.x, std::max(p1.position.x, p2.position.x));

	int minY = std::min(p0.position.y, std::min(p1.position.y, p2.position.y));
	int maxY = std::max(p0.position.y, std::max(p1.position.y, p2.position.y));

	for (int i{ minX }; i <= maxX; i++) {
		for (int j{ minY }; j <= maxY; j++) {
			vec2i p{ i, j };

			int64_t a1 = math::crossProduct(p0.position, p1.position, p);
			int64_t a2 = math::crossProduct(p1.position, p2.position, p);
			int64_t a3 = math::crossProduct(p2.position, p0.position, p);

			if ((a1 >= 0 && a2 >= 0 && a3 >= 0) || (a1 <= 0 && a2 <= 0 && a3 <= 0)) {
				setOnPixel(p);
			}
		}
	}
}

void Renderer::drawFilledTriangle(vertexNDC v0, vertexNDC v1, vertexNDC v2, uint32_t color) {
	vertex p0 = vertexStage.process(v0);
	vertex p1 = vertexStage.process(v1);
	vertex p2 = vertexStage.process(v2);

	int minX = std::min(p0.position.x, std::min(p1.position.x, p2.position.x));
	int maxX = std::max(p0.position.x, std::max(p1.position.x, p2.position.x));

	int minY = std::min(p0.position.y, std::min(p1.position.y, p2.position.y));
	int maxY = std::max(p0.position.y, std::max(p1.position.y, p2.position.y));

	for (int i{ minX }; i <= maxX; i++) {
		for (int j{ minY }; j <= maxY; j++) {
			vec2i p{ i, j };

			int64_t a1 = math::crossProduct(p0.position, p1.position, p);
			int64_t a2 = math::crossProduct(p1.position, p2.position, p);
			int64_t a3 = math::crossProduct(p2.position, p0.position, p);

			if ((a1 >= 0 && a2 >= 0 && a3 >= 0) || (a1 <= 0 && a2 <= 0 && a3 <= 0)) {
				setOnPixel(p, color);
			}
		}
	}
}
;