#pragma once
#include <iostream>
#include <vector>

class Renderer {


public:
	Renderer();
	uint32_t getPixel(int x, int y);
	void setPixel(int x, int y);
	uint32_t* getFrameBufferData();

private:
	const int width{ 800 };
	const int height{ 600 };

	// Vetor de pixels com coordenadas (x, y), mesmo com apenas uma dimensão, na qual cada coordenada
	// é acessada pelo índice, dado pela formula: indice = y * width + x
	// Definido o espaço apenas no construtor devido a ambiguidade do C
	std::vector<uint32_t> framebuffer;
};