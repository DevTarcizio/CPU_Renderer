#include "color.hpp"

Color::Color() : r(0), g(0), b(0), a(1) {}
Color::Color(float red, float green, float blue, float alpha): r(red), g(green), b(blue), a(alpha) {}

Color Color::operator+(const Color& other) const {
	return {
		r + other.r,
		g + other.g,
		b + other.b,
		a + other.a
	};
}

Color Color::operator*(float scalar) const {
	return {
		r * scalar,
		g * scalar,
		b * scalar,
		a * scalar
	};
}

uint32_t Color::toRGBA() const {
	uint8_t R = static_cast<uint8_t>(r * 255.0f);
	uint8_t G = static_cast<uint8_t>(g * 255.0f);
	uint8_t B = static_cast<uint8_t>(b * 255.0f);
	uint8_t A = static_cast<uint8_t>(a * 255.0f);

	return (R << 24) | (G << 16) | (B << 8) | A;
}
