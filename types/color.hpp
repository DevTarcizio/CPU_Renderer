#pragma once
#include <cstdint>

struct Color {
	float r;
	float g;
	float b;
	float a;

	// Construtor Padrão
	Color();

	// Construtor com valores
	Color(float red, float green, float blue, float alpha = 1.0f);

	// Operadores 
	Color operator+(const Color& other) const;
	Color operator*(float scalar) const;

	uint32_t toRGBA() const;
};