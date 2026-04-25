#include "Renderer.hpp"

Renderer::Renderer() : framebuffer(width * height) {

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

uint32_t Renderer::getPixel(vec2i cords) {
	if (!isInsideScreen(cords)) {
		std::cout << "Ponto fora da tela!\n";
		return 0;
	}

	int index{ ((cords.y * width) + cords.x) };
	return framebuffer[index];
}



void Renderer::togglePixel(vec2i cords) {
	if (!isInsideScreen(cords)) {
		std::cout << "Ponto fora da tela!\n";
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
		std::cout << "Ponto fora da tela!\n";
		return;
	}
	
	int index{ (cords.y * width) + cords.x };

	framebuffer[index] = 0xFFFFFFFF;
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

void Renderer::drawLine(vec2i initial_point, vec2i final_point) {
	float distanceX{ static_cast<float>(final_point.x - initial_point.x) };
	float distanceY{ static_cast<float>(final_point.y - initial_point.y) };

	// Definimos a distância real de um ponto a outro, ideal para podermos desenhar retas 
	// em qualquer direção
	float steps{ std::max(std::abs(distanceX), std::abs(distanceY))};

	if (initial_point == final_point) {
		setOnPixel(initial_point);
		steps = 0;
		return;
	}

	
	// Define o quanto andar em X e em Y
	float Xincrement{ distanceX / steps };
	float Yincrement{ distanceY / steps };

	vec2f cords{ initial_point.x, initial_point.y };

	for (int i{ 0 }; i <= steps; i++) {
		// O método round arrendonda 
		vec2i newCords{ round(cords.x), round(cords.y) };
		setOnPixel(newCords);
		cords.x += Xincrement;
		cords.y += Yincrement;
	}
}


void Renderer::drawTriangle(vec2i v0, vec2i v1, vec2i v2) {
	drawLine(v0, v1);
	drawLine(v0, v2);
	drawLine(v1, v2);
}


void Renderer::drawFilledTriangle(vec2i v0, vec2i v1, vec2i v2) {
	int minX = std::min(v0.x, std::min(v1.x, v2.x));
	int maxX = std::max(v0.x, std::max(v1.x, v2.x));

	int minY = std::min(v0.y, std::min(v1.y, v2.y));
	int maxY = std::max(v0.y, std::max(v1.y, v2.y));

	for (int i{ minX }; i <= maxX; i++) {
		for (int j{ minY }; j <= maxY; j++) {
			vec2i p{ i, j };

			int a1 = math::crossProduct(v0, v1, p);
			int a2 = math::crossProduct(v1, v2, p);
			int a3 = math::crossProduct(v2, v0, p);

			if (a1 >= 0 && a2 >= 0 && a3 >= 0 || a1 <= 0 && a2 <= 0 && a3 <= 0) {
				setOnPixel(p);
			}
		}
	}
};