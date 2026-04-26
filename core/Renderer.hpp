#pragma once
#include "../types/vec2.hpp"
#include "../math/math.hpp"
#include "../types/vertex.hpp"
#include "vertexStage.hpp"
#include "rasterizer.hpp"
#include <iostream>
#include <vector>
#include <cmath>

class Renderer {


public:
	Renderer();
	
	enum class Color {
		Red,
		Green,
		Blue,
		Black,
		White,
	};

	// Converte do enum para hexadecimal
	uint32_t toRGBA(Color color);

	// Retorna se o pixel está ligado, ou desligado
	uint32_t getPixel(vec2i cords);

	// Verifica se o ponto dado está dentro da tela
	bool isInsideScreen(vec2i point) const;

	// Um toggle para ativar/desativar os pixels
	void togglePixel(vec2i cords);

	// Ligam e desligam os pixels, usadas principalmente para desenhar na tela
	void setOnPixel(vec2i cords);
	void setOnPixel(vec2i cords, uint32_t color);
	void setOnPixel(vertex v);
	void setOffPixel(vec2i cords);
	
	uint32_t* getFrameBufferData();
	void drawLine(vertexNDC initial_point, vertexNDC final_point);
	void drawTriangle(vertexNDC v0, vertexNDC v1, vertexNDC v2);
	void drawFilledTriangle(vertexNDC v0, vertexNDC v1, vertexNDC v2);
	void drawFilledTriangle(vertexNDC v0, vertexNDC v1, vertexNDC v2, uint32_t color);

private:
	const int width{ 1920 };
	const int height{ 991 };

	// Vetor de pixels com coordenadas (x, y), mesmo com apenas uma dimensão, na qual cada coordenada
	// é acessada pelo índice, dado pela formula: indice = y * width + x
	// Definido o espaço apenas no construtor devido a ambiguidade do C
	std::vector<uint32_t> framebuffer;

	// Classes da Pipeline
	VertexStage vertexStage;
	Rasterizer rasterizer;
};