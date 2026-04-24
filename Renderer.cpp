#include "Renderer.hpp"

Renderer::Renderer() : framebuffer(width * height) {

}

uint32_t Renderer::getPixel(int x, int y) {
	if (x >= width || x < width) {
		std::cout << "Valor maior ou menor que a largura da tela!";
		return -1;
	}
	if (y >= height || y < height) {
		std::cout << "Valor maior ou menor que a altura da tela!";
		return -1;
	}

	int index{ ((y * width) + x) };
	return framebuffer[index];
}

void Renderer::setPixel(int x, int y) {
	if (x >= width || x < 0) {
		std::cout << "Valor maior ou menor que a largura da tela!";
		return;
	}
	if (y >= height || y < 0) {
		std::cout << "Valor maior ou menor que a altura da tela!";
		return;
	}

	int index{ (y * width) + x };

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


void Renderer::drawLine(int x0, int y0, int x1, int y1) {
	float distanceX{ static_cast<float>(x1 - x0) };
	float distanceY{ static_cast<float>(y1 - y0) };

	// Definimos a distância real de um ponto a outro, ideal para podermos desenhar retas 
	// em qualquer direção
	float steps{ std::max(std::abs(distanceX), std::abs(distanceY))};

	float Xincrement{ distanceX / steps };
	float Yincrement{ distanceY / steps };

	float x = x0;
	float y = y0;

	for (int i{ 0 }; i <= steps; i++) {
		setPixel(round(x), round(y));
		x += Xincrement;
		y += Yincrement;
	}
};