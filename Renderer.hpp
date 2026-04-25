#pragma once
#include "math/vec2.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class Renderer {


public:
	Renderer();
	
	// Retorna se o pixel está ligado, ou desligado
	uint32_t getPixel(vec2i cords);

	// Um toggle para ativar/desativar os pixels
	void setPixel(vec2i cords);


	// Retorna os dados do framebuffer
	uint32_t* getFrameBufferData();

	// Desenha uma linha a partir de 2 pares de coordenadas
	void drawLine(vec2i initial_point, vec2i final_point);


private:
	const int width{ 800 };
	const int height{ 600 };

	// Vetor de pixels com coordenadas (x, y), mesmo com apenas uma dimensão, na qual cada coordenada
	// é acessada pelo índice, dado pela formula: indice = y * width + x
	// Definido o espaço apenas no construtor devido a ambiguidade do C
	std::vector<uint32_t> framebuffer;
};