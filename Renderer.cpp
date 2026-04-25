#include "Renderer.hpp"

Renderer::Renderer() : framebuffer(width * height) {

}

uint32_t Renderer::getPixel(vec2i cords) {
	if (cords.x >= width || cords.x < 0) {
		std::cout << "Valor maior ou menor que a largura da tela!";
		return 0;
	}
	if (cords.y >= height || cords.y < 0) {
		std::cout << "Valor maior ou menor que a altura da tela!";
		return 0;
	}

	int index{ ((cords.y * width) + cords.x) };
	return framebuffer[index];
}


void Renderer::setPixel(vec2i cords) {
	if (cords.x >= width || cords.x < 0) {
		std::cout << "Valor maior ou menor que a largura da tela!";
		return;
	}
	if (cords.y >= height || cords.y < 0) {
		std::cout << "Valor maior ou menor que a altura da tela!";
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
		steps = 0;
	}

	// Define o quanto andar em X e em Y
	float Xincrement{ distanceX / steps };
	float Yincrement{ distanceY / steps };

	vec2f cords{ initial_point.x, initial_point.y };

	for (int i{ 0 }; i <= steps; i++) {
		// O método round arrendonda 
		vec2i newCords{ round(cords.x), round(cords.y) };
		setPixel(newCords);
		cords.x += Xincrement;
		cords.y += Yincrement;
	}
};