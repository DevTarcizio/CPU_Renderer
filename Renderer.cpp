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