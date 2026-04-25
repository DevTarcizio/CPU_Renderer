#pragma once
#include "math/vec2.hpp"
#include "math/utils.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class Renderer {


public:
	Renderer();
	
	// Retorna se o pixel está ligado, ou desligado
	uint32_t getPixel(vec2i cords);

	// Verifica se o ponto dado está dentro da tela
	bool isInsideScreen(vec2i point) const;

	// Um toggle para ativar/desativar os pixels
	void togglePixel(vec2i cords);

	// Ligam e desligam os pixels, usadas principalmente para desenhar na tela
	void setOnPixel(vec2i cords);
	void setOffPixel(vec2i cords);
	
	uint32_t* getFrameBufferData();
	void drawLine(vec2i initial_point, vec2i final_point);
	void drawTriangle(vec2i v0, vec2i v1, vec2i v2);
	void drawFilledTriangle(vec2i v0, vec2i v1, vec2i v2);

private:
	const int width{ 800 };
	const int height{ 600 };

	// Vetor de pixels com coordenadas (x, y), mesmo com apenas uma dimensão, na qual cada coordenada
	// é acessada pelo índice, dado pela formula: indice = y * width + x
	// Definido o espaço apenas no construtor devido a ambiguidade do C
	std::vector<uint32_t> framebuffer;
};